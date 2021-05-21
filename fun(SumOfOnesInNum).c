#include <stdio.h>
#include <stdlib.h>

int SumOfOnesInNum(int num)
{
    int s=0;
    while(num>0)
    {
        if((num&1))
        {
            s=s+1;
        }
        num=num>>1;
    }
    return s;
}
