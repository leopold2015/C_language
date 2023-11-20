#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE * fp = NULL;
    char buffer[32] = {0};
    fp = fopen("test.txt", "r");

    fread(buffer, 32, 1, fp);

    printf("%s\n", buffer);

    fclose(fp);
    return 0;

}