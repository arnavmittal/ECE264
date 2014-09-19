#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "answer03.h"

// The caller /must/ free the result

int main(int argc, char * * argv)
{
    /*
    int n;
    char* dest;
    dest = NULL;
    char * src = "How did it get so late so soon?";
    
    printf("n= %d    dest = %s     src = %s     \n\n",n, dest, src);
    char * s2 = strcat_ex( &dest, &n, src);
    printf("n= %d    dest = %s     src = %s     s2=%s\n\n",n, dest, src,s2);
    
    const char * str = "lady beatle brew";
    const char * delims = " ";
    int b;
    char * * strArr = explode(str, delims, &b);
    printf("%d \n", b);
    */
    /*char * str = "The\nTuring test";
    char * delims = " \n";
    int n=0;
    */
    int len = 3;
    char * * strArr = malloc(len * sizeof(char*));
    strArr[0] = strdup("The");
    strArr[1] = strdup("Turing");
    strArr[2] = strdup("test");
    const char * glue = " ";
    char * s = implode(strArr, len, glue);
    printf("%s", s);
    return EXIT_SUCCESS;
}


