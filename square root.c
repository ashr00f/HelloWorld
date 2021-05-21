#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i=0,num,total,max=0,power,result=1,flag=0;
    while(1)
    {
      flag=0;
       printf("enter number: ");
       scanf("%d",&num);
        for(i=1;(i*i<=num)&&(flag==0);i++)
        {
            if((i*i)==num)
            {
                printf("root=%d\n",i);
                flag=1;
            }
        }
        if(flag==0)
        {
           printf("no rot\n");
        }
    }








    return 0;
}
