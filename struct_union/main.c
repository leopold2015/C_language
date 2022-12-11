#include <stdio.h>
#include <stdlib.h>


#define NAMESIZE    32
struct simp_st 
{

	int i;
	float f;
	char ch;
//}__attribute__((packed));
};
/*
struct birthday_st
{
	int year;
	int month;
	int day;

		
}
*/


struct student_st
{
	int id;
	char name[NAMESIZE];
//	struct birthday_st birth;
	struct birthday_st
	{	
        	int year;
        	int month;
        	int day;
	}birth;
	int math;
	int chinese;
};

void func(struct simp_st *b)
{
	printf("%ld\n", sizeof(b));
}



int main()
{
	

	// TYPE NAME = VALUE；

	struct simp_st a;
	struct simp_st *p = &a;


	printf("sizeof(point)= %ld \n", sizeof(p));
	printf("sizeof(struct) = %ld \n", sizeof(a));


//	func(a);

	func(p);















#if 0
	/*	 
	struct simp_st a = {123, 456.789, 'a'};
	
	a.i = 112233;

	printf("%d, %f, %c\n", a.i, a.f, a.ch);

	*/
	int i = 0;
	struct student_st stu = {10011, "Alan", {2010,11,11}, 98, 87};
	struct student_st *p = &stu;
	//struct student_st stu = {.math = 90, .chinese = 98};
	struct student_st arr[2] = {{10011, "Alan", {2010,11,11}, 98, 87},{10012, "Alan", {2012,12,12}, 90, 97}};
	p = &arr[0];


	//printf("%d %s %d-%d-%d %d %d\n", stu.id, stu.name, stu.birth.year, stu.birth.month, stu.birth.day, stu.math, stu.chinese);

	for(i = 0; i < 2; i++, p++)   // p = p + 1
	{
		
		printf("%d %s %d-%d-%d %d %d\n", p->id, p->name, p->birth.year, p->birth.month, p->birth.day, p->math, p->chinese);
		
	}


#endif 
	exit(0);
}
