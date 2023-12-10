#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

/*
-y year
-m month
-d day
-H hour
-M minute
-S second
*/

int main(int argc, char ** argv)
{
    FILE *fp;
    time_t stamp;
    struct tm *tm;
    int c;
    char timestr[1024];
    char fmtstr[1024];
    fmtstr[0]='\0';
    timestr[0]='\0';

    stamp = time(NULL);
    tm = localtime(&stamp);

    while(1)
    {
        c = getopt(argc, argv, "HMSymd");
        if(c<0)
            break;
    
        switch(c)
        {
            case 1:
                if(fp  == stdout)
                {
                    fp = fopen(argv[optind -1], "w");
                    if(fp == NULL)
                    {
                        fprintf(stderr, "fopen()");
                        fp = stdout;
                    }
                }    
                break;
            case 'H':
                if(strcmp(optarg, "12") == 0)
                    strncat(fmtstr,"%I(%P) ", 1024);
                else if (strcmp(optarg, "24") == 0)
                        strncat(fmtstr,"%H ", 1024);
                    else 
                        fprintf(stderr, "Invalid argument -H!!!\n");
                break;
            case 'M':
                strncat(fmtstr,"%M ", 1024);
                break;
            case 'S':
                strncat(fmtstr,"%S ", 1024);
                break;  
            case 'y':
                if(strcmp(optarg, "2") == 0)
                    strncat(fmtstr,"%y ", 1024);
                else if (strcmp(optarg, "4") == 0)
                        strncat(fmtstr,"%Y ", 1024);
                    else 
                        fprintf(stderr, "Invalid argument -y!!!\n");
                
                break;
            case 'm':
                strncat(fmtstr,"%m ", 1024);
                break;
            case 'd':
                strncat(fmtstr,"%d ", 1024);
                break; 
        }
    }

    strftime(timestr, 1024, fmtstr, tm);
    fputs(timestr, fp);

    if(fp)
    {
        fclose(fp);
    }

/*
    tm->tm_mday += 100;
    (void)mktime(tm);
    strftime(timestr, 1024, "100 days later:%Y-%m-%d\n", tm);
    puts(timestr);
*/
    exit(0);
}