int areDistinct(int *arr, int len)
{
    int ind1;
    int ind2;
    for(ind1 = 0; ind1 < len; ind1++)
    {
        for(ind2 = ind1 + 1; ind2 < len; ind2 ++)
        {
            if(arr[ind1] == arr[ind2])
            {
                // find two same value
                return 0;
            }
        }
    }

    // not find two equel value
    return 1;
}