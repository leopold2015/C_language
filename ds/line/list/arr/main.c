#include<stdio.h>
#include <stdlib.h>

#include "sqlist.h"

int main()
{
	int i = 0, err = 0;
	sqlist *list;
	sqlist *list1;
	sqlist *list2;


	datatype arr[] = {12,23,34,45,56};
	datatype arr1[] = {78, 89, 10, 23, 56, 12};

	//list = sqlist_create();
	

	sqlist_create1(&list1);
	if(list1 == NULL)
	{
		fprintf(stderr, "sqlist_create1() failed!!\n");
		exit(1);
	}


	sqlist_create1(&list2);
        if(list1 == NULL)
        {
                fprintf(stderr, "sqlist_create1() failed!!\n");

		exit(1);
	}

	sqlist_create1(&list);
	if(list == NULL)
	{
		fprintf(stderr, "sqlist_create() failed!!\n");
		exit(1);
	}
	
	for(i = 0; i< sizeof(arr)/sizeof(*arr); i++)
	{
		if((err = sqlist_insert(list, 0, &arr[i])) != 0)
		{
			if(err == -1)
			{
				fprintf(stderr, "The arr is full.\n");

			}
			else if(err == -2)
			{
			
				fprintf(stderr, "The pos you want to insert is wrong.\n");
			}
			else
			{
				fprintf(stderr, "Error!!\n");
			}

			exit(1);
		}
	}



	for(i = 0; i< sizeof(arr)/sizeof(*arr); i++)
        {
                if((err = sqlist_insert(list1, 0, &arr[i])) != 0)
                {
                        if(err == -1)
                        {
                                fprintf(stderr, "The arr is full.\n");

                        }
                        else if(err == -2)
                        {
                        
                                fprintf(stderr, "The pos you want to insert is wrong.\n");
                        }
                        else
                        {
                                fprintf(stderr, "Error!!\n");
                        }

                        exit(1);
                }
        }


	for(i = 0; i< sizeof(arr1)/sizeof(*arr1); i++)
        {
                if((err = sqlist_insert(list2, 0, &arr1[i])) != 0)
                {
                        if(err == -1)
                        {
                                fprintf(stderr, "The arr is full.\n");

                        }
                        else if(err == -2)
                        {

                                fprintf(stderr, "The pos you want to insert is wrong.\n");
                        }
                        else
                        {
                                fprintf(stderr, "Error!!\n");
                        }

                        exit(1);
                }
        }

	sqlist_display(list);

	sqlist_delete(list, 1);
	
	sqlist_display(list);

	sqlist_display(list1);
	sqlist_display(list2);
	sqlist_union(list1, list2);
	sqlist_display(list1);

	sqlist_destroy(list);
	exit(0);
}
