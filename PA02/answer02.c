#include <stdlib.h>
#include "answer02.h"

size_t my_strlen(const char * str)
{
    int ind = 0;
    int len = 0;
    while(str[ind]!='\0')
    {
        len = len + 1;
        ind++;
    }
    return(len);
}

int my_countchar(const char * str, char ch)
{
    int ind=0;
    int same=0;
    while(str[ind]!='\0')
    {
        if(str[ind]==ch)
        {
            same = same + 1;
        }
        ind++;
    }
    return(same);
}

char * my_strchr(const char * str, int ch)
{   
    int ind=0;
    //char * nstr;
    //int nind=0;
    while (str[ind] != ch || str[ind] != '\0')
    {
        ind++;
    }
    if (str[ind] == '\0')
    {
        return(NULL);
    }
    /*else
    {
        while(str[ind] != '\0')
        {
            nstr[nind] = str[ind];
            ind++;
            nind++;
        }
        nstr[nind] = '\0';
        printf("%s", nstr);
    }
    nstr = &str;*/
    return(&str[ind]);
}

char * my_strrchr(const char * str, int ch)
{
  return(0);
}

char * my_strstr(const char * haystack, const char * needle)
{
  return (0);
}
char * my_strcpy(char * dest, const char * src)
{
    return (0);
}
char * my_strcat(char * dest, const char * src)
{
    return (0);
}
int my_isspace(int ch)
{
    return (0);
}
int my_atoi(const char * str)
{
    return (0);
}