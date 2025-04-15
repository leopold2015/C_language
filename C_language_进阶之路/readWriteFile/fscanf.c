#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    FILE *fptr;
    int val;
    int sum  = 0;
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

    fptr = fopen(argv[1], "r");
    if(fptr == NULL)
    {
        printf("fopen failed. \n");
        return EXIT_FAILURE;
    }

    printf("the name of the file is %s\n", argv[1]);
    while(fscanf(fptr, "%d", &val) == 1)
    {
        printf("%d ", val);
        sum += val;
    }

    fclose(fptr);
    printf("the sum is %d\n", sum);

    return EXIT_FAILURE;
}