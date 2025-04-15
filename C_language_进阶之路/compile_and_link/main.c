#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int areDistinct(int *arr, int len);

int main(int argc, char ** argv)
{
    if(argc != 2)
    {
        return EXIT_FAILURE;
    }

    FILE * pFile = fopen(argv[1], "r");
    int length = 0;
    int value = 0;
    int *pArr = NULL;
    int dist = 0;

    if(pFile == NULL)
    {
        return EXIT_FAILURE;
    }

    while(fscanf(pFile, "%d", &value) == 1)
    {
        length ++;
    }

    fseek(pFile, 0, SEEK_SET);
    pArr = malloc(length * sizeof(int));

    length = 0;

    while(fscanf(pFile, "%d", &(pArr[length])) == 1)
    {

        length ++;
    }
    fclose(pFile);

    dist = areDistinct(pArr, length);
    printf("The elements are");
    if(dist == 0)
    {
        printf(" not");
    }

    printf(" distinct.\n");

    free(pArr);


    return EXIT_SUCCESS;
}