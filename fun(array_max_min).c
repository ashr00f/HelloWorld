#include <stdio.h>
#include <stdlib.h>

int array_max_min(int*arr,int size,int max,int *min)
{

    int i;
    max=arr[0],*min=arr[0];
    for(i=0; i<size; i++)
    {
        if (arr[i]>max)
        {
            max=arr[i];

        }
      else if (arr[i]<arr[0])
        {
           *min=arr[i];

        }
        }

    return max;

}