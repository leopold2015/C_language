#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buff[1024];
    int year = 2023, month = 11, day = 12;

    sprintf(buff, "%d-%d-%d", year, month, day);
    
    puts(buff);
    //char str[] = "12a345";
    //printf("%d\n", atoi(str));

    exit(0);
     
}