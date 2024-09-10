#include<stdio.h>

struct student
{
    int age;
    int num;
    int math;
};


int main(void)
{
    int i = 2;
    typeof(i) k = 6;
    
    int *p = &k;
    typeof(p) q = &i;

    printf("k = %d\n", k);
    printf("*p = %d\n", *p);
    printf("i = %d\n", i);
    printf("q = %d\n", *q);


    printf("-----------------wo shi fenge xian--------------"\n);

    struct student stu  = {20, 1001, 99};
    int *p = &stu.math;
    struct student *stup = NULL;
    
    stup = container_of( p, (struct student), stu.math);
    printf("%p\n", stup);
    printf("age:%d\n", stup->age);
    printf("num:%d\n", stup->num);

    return 0;
}