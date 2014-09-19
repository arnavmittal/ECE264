#include <stdlib.h>
#include<string.h>
#include "answer03.h"

char * strcat_ex(char * * dest, int * n, const char * src)
{
    char * tmp = NULL;
    int sz = 0; // num bytes required to store the result
    int dest_len = (*dest == NULL) ? 0:strlen(*dest);
    int src_len = (src == NULL) ? 0:strlen(src);
    sz = dest_len + src_len + 1;
    if(*dest == NULL || sz > *n)
    {
        // DRY: Don't Repeat Yourself.
        *n = (1 + 2 * (dest_len + src_len));
        tmp = malloc(*n*sizeof(char));
        *tmp = '\0';
        if(*dest != NULL)
        {
            strcpy(tmp,*dest);
            free(*dest);
        }
        if(src != NULL)
        {
            tmp=strcat(tmp,src);
        }
        *dest = tmp;
        return(*dest);
    }
    else
    {
        strcat(*dest, src);
        return(*dest);
    }
}
char * * explode(const char * str, const char * delims, int * arrLen)
{
    int ind=0;
    int last=0;
    int len=0;
    int arrInd=0;
    *arrLen = 1;
    for(ind = 0; ind < strlen(str); ind++)
    {
        if (strchr(delims, str[ind]) != NULL)
        {
            (*arrLen)++;
        }
    }
    char * * strArr = malloc(((*arrLen)) * sizeof(char *));
    for(ind=0; ind < strlen(str); ind++)
    {
        if (strchr(delims, str[ind]) != NULL)
        {
            len = ind - last;
            strArr[arrInd]=malloc((len+1)*sizeof(char));
            memcpy(strArr[arrInd], &str[last], len);
            strArr[arrInd][len]='\0';
            arrInd++;
            last=ind+1;
        }
    }
    len = ind - last;
    strArr[arrInd]=malloc((len+1)*sizeof(char));
    memcpy(strArr[arrInd], &str[last], len);
    strArr[arrInd][len]='\0';
    arrInd++;
    last=ind+1;
    return(strArr);
}
char * implode(char * * strArr, int len, const char * glue)
{
    char * buffer = NULL;//malloc(len*sizeof(char*));
    int ind = 0;
    for(ind = 0;ind < len-1; ind++)
    {
        strcat_ex(&buffer, &len, strArr[ind]);
        strcat_ex(&buffer, &len, glue);
    }
    strcat_ex(&buffer, &len, strArr[ind]);
    return(buffer);
}
void sortStringArray(char * * arrString, int len)
{
    return(0);
}
void sortStringCharacters(char * str)
{
    return(0);
}
void destroyStringArray(char * * strArr, int len)
{
    return(0);
}
