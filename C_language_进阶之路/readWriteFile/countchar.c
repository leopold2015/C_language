#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE * fptr;
    int ch;
    int counter = 0;
    if(argc < 2)
    {
        printf("need to provide the file's name.\n");
        return EXIT_FAILURE;
    }
    fptr = fopen(argv[1], "r");
    if(fptr == NULL)
    {
        printf("fopen failed\n");
        return EXIT_FAILURE;
    }
    printf("the name of the file is %s\n", argv[1]);

    do 
    {
        ch = fgetc(fptr);
        if(ch != EOF)
        {
            counter ++;
        }
    }
    while(ch != EOF);
    //while(!feof(fptr));
    fclose(fptr);
    printf("the file has %d characters.\n", counter);
    return EXIT_FAILURE;
}