	#include <stdio.h>
#include <stdlib.h>

int add_mul (int x,int y,int*pr_mul)
{

  *pr_mul=x*y;
    return x+y;
}

int main()
{
    int x=3,y=5,r_mul=7,r_sum;
  r_sum=add_mul(x,y,&r_mul);




   printf("%d,%d %d,%d       ",x,y,r_mul,r_sum);

    return 0;
}