#include <stdio.h>
#include <stdlib.h>

int array_find(int*arr,int size,int num,int *num_lb)
{

    int i,r=-1,f=0;
    for(i=0; i<size; i++)
    {
        if (arr[i]==num)
        {
            if(0==f)
            {*num_lb=i;
             f=1;
            }
            r=i;

        }

        printf("%d",f);
    }
    printf("%d\n",*num_lb);
    return r;

}