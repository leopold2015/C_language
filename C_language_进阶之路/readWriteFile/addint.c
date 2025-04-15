#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc < 4)
    {
        return EXIT_FAILURE;
    }

    FILE *fin1;
    FILE *fin2;

    fin1 = fopen(argv[1], "r");
    if(fin1 == NULL)
    {
        printf("open file %s failed\n", argv[1]);
        return EXIT_FAILURE;
    }

    fin2 = fopen(argv[2], "r");
    if(fin1 == NULL)
    {
        printf("open file %s failed\n", argv[2]);
        return EXIT_FAILURE;
    }

    FILE *fout;
    fout = fopen(argv[3], "w");
    if(fout == NULL)
    {
        fclose(fin1);
        fclose(fin2);
        return EXIT_FAILURE;
    }

    int val1= 0 ;
    int val2 = 0;
    int in1ok = 1;
    int in2ok = 1;

    while((in1ok == 1) || (in2ok == 1))
    {
        val1 = 0;
        val2 = 0;
        if(fscanf(fin1, "%d", &val2) != 1)
        {
            in1ok = 0;
        }
        if(fscanf(fin2, "%d", &val2) != 1)
        {
            in2ok = 0;
        }

        if((in1ok == 1) || (in2ok == 1))
        {
            fprintf(fout, "%d\n", val1 + val2);
        }
    }

    fclose(fin1);
    fclose(fin2);
    fclose(fout);

    return EXIT_FAILURE;

    // exec example: ./addint in1 in2 out
}