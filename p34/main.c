#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	int i = 0, k = 0, j = 0;
	char *name[5] = {"Follow me", "Basic", "Greet", "Fortran", "Computer"};
	char* tmp;

	for(i = 0; i< 5-1; i++)
	{
		k = i;
		for(j= i+1; j < 5; j++)
		{
			if(strcmp(name[k], name[j]) > 0)
				k = j;
		}

		if(k != i)
		{

			tmp = name[i];
			name[i] = name[k];
			name[k] = tmp;
		}
	}

	for(i = 0; i < 5; i++)
	{
		puts(name[i]);
	}

	return 0;
}

