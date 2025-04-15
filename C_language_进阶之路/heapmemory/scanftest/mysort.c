#include <stdio.h>

static void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void mysort(int *arr, int len)
{
    int ind1 = 0, ind2 = 0;
    for(ind1 = 0; ind1 < len; ind1++)
    {
        int minind = ind1;
        for(ind2 = ind1 + 1; ind2 < len; ind2 ++)
        {
            if(arr[minind] > arr[ind2])
            {
                minind = ind2;
            }

        }

        if(minind != ind1)
        {
            swap(&arr[ind1], &arr[minind]);
        }
    }
}


