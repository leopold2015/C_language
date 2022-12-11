#include <stdio.h>
#include <stdlib.h>

#define M        4
#define N        3
#define K        4



static void change()
{
    int i, j; 
    int a[M][N] = {{1,2}, {3,4}, {5,6}}, b[N][M];

    for(i = 0; i < M; i++)
    {
	for(j = 0; j < N; j++)
	{
             printf("%d ", a[i][j]);
	}

	printf("\n");
    }

    for(i = 0; i < M; i++)
    {
    	for(j = 0; j < N; j++)
	{
	    b[j][i] = a[i][j];
	}
    }

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
             printf("%d ", b[i][j]);
        }

        printf("\n");
    }
}


static void max()
{
	int a[M][N] = {43, 4,23,98,9,7};

	int i, j;
	int max = a[0][0], row = 0, colum = 0;

	for(i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
		{
			printf("%d ", a[i][j]);
			if(max < a[i][j])
			{
				max = a[i][j];
				row = i + 1;
				colum = j + 1;
			}
		}
		printf("\n");
	}

	printf("max num is: %d, row is %d, column is %d\n", max, row, colum);
}


static void sum()
{
	int a[M][N] = {1,2,3,4,5,6,7,8,9,10,11,12};
	
	int i, j;
	int rowSum[M] = {0};
	int columSum[N] = {0};
 
	for(i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
		{
			printf("%d ", a[i][j]);
			rowSum[i] += a[i][j];
			columSum[j] += a[i][j];
		}

		printf("\n");
	}

	printf("rowSum is :\n");
	for(i = 0; i < M; i++)
	{
		printf("%d \n", rowSum[i]);
	}



	printf("columSum is :\n");

	for(i = 0; i < N; i++)
        {
                printf("%d ", columSum[i]);
        }
	printf("\n");

	
}

static void mul()
{
	int a[M][N] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int b[N][K] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int c[M][K] = {0};

	int i,j,k;
	
	for(i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
		{
			for(k = 0; k < K; k++)
			{
				c[i][k] += a[i][j] * b[j][k];
			}
		}
	}

	for(i = 0; i < M; i++)
	{
		for(k = 0; k < K; k++)
		{
			printf("%d ", c[i][k]);	
		}

		printf("\n");
	}

}
int main()
{
    
	//change();
	
	//max();
	
	//sum();
	
	mul();
	exit(0);
}
