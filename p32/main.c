#include <stdio.h>

#define N 10
static void sort1()
{
    int i, j, tmp;
    int a[N] = {12, 8, 45, 30, 98, 67, 2, 7, 68, 11};

    for(i = 0; i < N; i++)
    {
    	printf("%d ", a[i]);
    }
    printf("\n");

    for(i = 0; i < (N-1); i++)
    {
    	for(j = 0; j < N-1-i; j++)
	{
	    if(a[j] > a[j+1])
	    {
	    	tmp = a[j];
		a[j] = a[j+1];
		a[j+1] = tmp;
	    }
	}
    	
    }

    for(i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}


static void sort2()
{

    int i, j, k, tmp;
    int a[N] = {5,7,6, 8,9,2,1,4,3};


    for(i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    for(i = 0; i< N; i++)
    {
	k = i;
    	for(j = i+1; j< N; j++)
	{
	    if(a[k] > a[j])
	    {
	    	k = j;
	    } 
	}
	if(i != k)
	{
	    tmp = a[i];
	    a[i] = a[k];
	    a[k] = tmp;
	}
    }

    for(i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

static void base_convert()
{

    int  num, base;
    int n[128], i =0;
    
    printf("Please enter the converted num:");
    scanf("%d", &num);
    printf("Please enter the num:");
    scanf("%d", &base);

    do
    {
    	n[i] = num%base;
	num = num/base;
	i++;
    }while(num != 0);

    for(i --; i >=0; i--)
    {
	if(n[i] >=10)
    	    printf("%c", n[i]-10+'A');
	else
	    printf("%d", n[i]);
    }

    printf("\n");


}

static void primer(void)
{
    char primer[1001] = {0};

    int i,j;

    for(i = 2; i < 1001; i++)
    {
    	if(primer[i] == 0)
	{
	    for(j = i*2; j < 1001; j+=i)
	    {
	    	primer[j] = -1;
	    }
	}
    }

    for(i = 2; i < 1001; i++)
    {
    	if(primer[i] == 0)
	{
	    printf("%d ", i);
	}
    }
    printf("\n");
}

int main()
{
    //sort1();
   // sort2();

    //base_convert();
    primer();

    return 0;

}
