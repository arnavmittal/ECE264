
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * * argv)
{
    int ind = 0;
    int invert = 0;
    int lineout = 0;
    int sup = 0;
    int match = 0;
    for(ind = 1 ; ind < argc; ++ind)
    {
        if(strcmp(argv[ind], "--help") == 0)
        {
            printf("Usage: grep-lite [OPTION]... PATTERN\nSearch for PATTERN in standard input. PATTERN is a\nstring. grep-lite will search standard input line by\nline, and (by default) print out those lines which\ncontain pattern as a substring.\n\n-v, --invert-match     print non-matching lines\n-n, --line-number      print line numbers with output\n-q, --quiet            suppress all output\n\nExit status is 0 if any line is selected, 1 otherwise;\nif any error occurs, then the exit status is 2.");
            printf("\n");
            return 1;
        }
    }
    for(ind = 1 ; ind < argc-1; ++ind)
    {
        if(!strcmp(argv[ind], "-v") || !strcmp(argv[ind], "--invert-match"))
        {
            invert = 1;
        }
        if(!strcmp(argv[ind], "-n") || !strcmp(argv[ind], "--line-number"))
        {
            lineout = 1;
        }
        if(!strcmp(argv[ind], "-q") || !strcmp(argv[ind], "--quiet"))
        {
            sup = 1;
        }
        if(strcmp(argv[ind], "-v") && strcmp(argv[ind], "-n") && strcmp(argv[ind], "-q") && strcmp(argv[ind], "--quiet") && strcmp(argv[ind], "--line-number") && strcmp(argv[ind], "--invert-match"))
        {
            fprintf(stderr, "Bogus Command Line Arguemunt Found\n");
            return 2;
        }
    }
    {
        if(argv[argc-1][0] == '-')
        {
            fprintf(stderr, "Pattern should not begin with -\n");
            return 2;
        }
    }
    int count = 1;
    char str[2000];
    while(fgets(str, 2000, stdin))
    {
        if(strstr(str, argv[argc-1]))
        {
            match = 1;
        }
        if(sup==0)
        {
            if((invert == 0 && strstr(str, argv[argc-1])) || (invert == 1 && !strstr(str, argv[argc-1])))
            {
                if (lineout == 1)
                {
                    fprintf(stdout, "%d:", count);
                }
                fprintf(stdout, "%s", str);
            }
        }
        count++;
    }
    if ( match == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
