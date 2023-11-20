#include <stdio.h>
#include <stdlib.h>

/*
* 缓冲区的作用：大多数情况下是好事，合并系统调用
* 
* 行缓冲：换行时候刷新，满了的时候刷新，强制刷新（标准输出是这样）
*
* 全缓冲：满了的时候刷新，强制刷新（默认，只要不是终端设备）
*
* 无缓冲：如stderr，需要立即输出的内容
setvbuf 修改文件的缓冲模式
*/

int main()
{
    int i;
    
    printf("Before while()");
    fflush(stdout);
    while(1);

    printf("after while()");

    exit(0);
}