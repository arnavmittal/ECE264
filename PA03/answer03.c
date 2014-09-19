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
    int num = 0;
    for(ind = 0;ind < len-1; ind++)
    {
        strcat_ex(&buffer, &num, strArr[ind]);
        strcat_ex(&buffer, &num, glue);
    }
    strcat_ex(&buffer, &num, strArr[ind]);
    return(buffer);
}
int comparefunc(const void * arg1, const void * arg2)
{
    const char * ptr1 = (const char *) arg1;
    const char * ptr2 = (const char *) arg2;
    const char val1 = * ptr1;
    const char val2 = * ptr2;
    if (val1 < val2)
    {
        return -1;
    }
    if (val1 == val2)
    {
        return 0;
    }
    return 1;
}

int comparefunc2(const void * arg1, const void * arg2)
{
    int cmp=0;
    const char ** arg11 = (const char **) arg1;
    const char ** arg22 = (const char **) arg2;
    cmp = strcmp(*arg11, *arg22);
    return(cmp);
}

void sortStringArray(char * * arrString, int len)
{
    if(arrString != NULL)
    {
        qsort(arrString, len, sizeof(char*), comparefunc2);
    }
}
void sortStringCharacters(char * str)
{
    if(str != NULL)
    {
        qsort(str, strlen(str), sizeof(char), comparefunc);
    }
}
void destroyStringArray(char * * strArr, int len)
{
    int ind=0;
    if(strArr != NULL)
    {
        for(ind=0; ind < len; ind++)
        {
            free(strArr[ind]);
        }
    }
    free(strArr);
}
