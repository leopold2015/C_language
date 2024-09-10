#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{

    char *linebuf = NULL;
    size_t len = 0;

    while(1)
    {
        prompt();
        getline(&linebuf, &len, stdin);

        parse();

        if()
        {


        }
        else    //child
        {
            fork();
            if(pid == 0)
            {


            }
        }

    }
    return 0;
}