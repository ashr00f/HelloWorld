/*#include <stdio.h>
#include <stdlib.h>

int main()
{
  unsigned char i,num,r,flag,s;
    while(1)
    {r=1;s=0;flag=0;
         scanf("%d",&num);
    while(num>0)
    {

        if((num&1)==1)
            {
            s=s+1;
        }
        num=num>>1;

    }
        printf("sum =%d\n",s);




    }





    return 0;
}
