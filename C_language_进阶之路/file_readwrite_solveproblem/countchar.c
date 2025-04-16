#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUM_CHAR  26

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        return EXIT_FAILURE;
    }

    char charcount[NUM_CHAR] = {0};
    FILE *infptr;
    infptr = fopen(argv[1], "r");
    if(infptr == NULL)
    {
        return EXIT_FAILURE;
    }

    int onechar;
    do
    {
        onechar = fgetc(infptr);
        if(isupper(onechar))
        {
            charcount[onechar - 'A'] ++;
        }
        if(islower(onechar))
        {
            charcount[onechar - 'a'] ++;
        }
    }while(onechar != EOF);

    fclose(infptr);
    
    FILE * outfptr;
    outfptr = fopen(argv[2], "w");
    if(outfptr == NULL)
    {
        return EXIT_FAILURE;
    }

    int ind;
    for(ind = 0; ind < NUM_CHAR; ind++)
    {
        fprintf(outfptr, "%c: %d\n", ind + 'A', charcount[ind]);
    }

    fclose(outfptr);
    return EXIT_SUCCESS;
}