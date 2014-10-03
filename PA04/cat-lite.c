
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char * * argv)
{
  int ind = 0;
  for(ind = 1 ; ind < argc; ++ind)
  {
      if(strcmp(argv[ind], "--help") == 0)
      {
          printf("Usage: cat-lite [--help] [FILE]...\nWith no FILE, or when FILE is -, read standard input.\n\nExamples:\n  cat-lite README   Print the file README to standard output.\n  cat-lite f - g    Print f's contents, then standard input, \n                    then g's contents.\n  cat-lite          Copy standard input to standard output.");
          printf("\n");
          return EXIT_SUCCESS;
      }
  }
  for(ind=1; ind<argc; ind++)
  {
    FILE * fptr;
	if(strcmp(argv[ind], "-") == 0)
	{
        fptr = stdin;
	}
	else
	{
        fptr = fopen(argv[ind], "r");
        if(fptr == NULL)
        {
            fprintf(stderr, "cat cannot open %s \n", argv[ind]);
            return EXIT_FAILURE;
        }
    }
    while(!feof(fptr))
    {
        int ch = fgetc(fptr);
        if(ch != EOF)
        {
            fprintf(stdout,"%c", ch);
        }
    }
      fclose(fptr);
    }
    if(argc == 1)
    {
        while(!feof(stdin))
        {
            int ch = fgetc(stdin);
            if(ch != EOF)
            {
                fprintf(stdout,"%c", ch);
            }

        }
    }
  return EXIT_SUCCESS;
}

