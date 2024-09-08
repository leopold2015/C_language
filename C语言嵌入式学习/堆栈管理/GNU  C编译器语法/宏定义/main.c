#include<stdio.h>

//#define MAX(x,y)({\
    typeof(x) _x=(x); \
    typeof(y) _y = (y); \
    (void)(&_x == &_y); \
    _x > _y ? _x : _y;})

#define MAX(x,y)({\
    typeof(x) _x=(x); \
    typeof(y) _y = (y); \
    _x > _y ? _x : _y;})

/* 内核中使用的宏定义语句表达式 */
#define min_t(type, x, y)({\
type __min1 = (x); \
type __min2 = (y); \
__min1 < __min2 ? __min1 : __min2; })

#define max_t(type, x, y)({\
type __max1 = (x); \
type __max2 = (y); \
__max1 > __max2 ? __max1 : __max2; })

int main(void)
{
    int i =  2;
    int j = 6;
    printf("max = %d\n",MAX(i++,j++));
    printf("min = %d\n",min_t(int,i,j));
    printf("max = %d\n",max_t(int,i++,j++));

    return 0;


}

