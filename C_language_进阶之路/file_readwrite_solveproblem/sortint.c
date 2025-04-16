#include <stdio.h>
#include <stdlib.h>

int comparefunc(const void *arg1, const void *arg2)
{
    const int * ptr1 = (const int *) arg1;
    const int * ptr2 = (const int *) arg2;
    const int val1 = *ptr1;
    const int val2 = *ptr2;

    if(val1 < val2)
    {
        return -1;
    }
    if(val1 == val2)
    {
        return 0;
    }

    return 1;
}

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        return EXIT_FAILURE;
    }

    FILE *infptr;
    infptr = fopen(argv[1], "r");
    if(infptr == NULL)
    {
        return EXIT_FAILURE;
    }

    int count = 0;
    int val;
    while(fscanf(infptr, "%d", &val) == 1)
    {
        count++;
    }
    int *arr;
    arr = malloc(sizeof(int) * count);
    if(arr == NULL)
    {
        fclose(infptr);
        return EXIT_FAILURE;
    }

    fseek(infptr, 0, SEEK_SET);
    int ind = 0;
    while(fscanf(infptr, "%d", &val) == 1)
    {
        arr[ind] = val;
        ind ++;
    }

    qsort(&arr[0], count, sizeof(int), comparefunc);
    fclose(infptr);
    FILE *outfptr;
    outfptr = fopen(argv[2], "w");
    if(outfptr == NULL)
    {
        free(arr);
        return EXIT_FAILURE;
    }

    for(ind = 0; ind < count; ind++)
    {
        fprintf(outfptr, "%d\n", arr[ind]);
    }

    fclose(outfptr);
    free(arr);
    return EXIT_FAILURE;
}