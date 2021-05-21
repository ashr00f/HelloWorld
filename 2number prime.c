#include <stdio.h>
#include <stdlib.h>

int fact(int n)
{
    int r=1,i;
    printf("n==%d\n",n);
    for(i=1;i<=n;i++)
    {
        r=r*i;
    }
    return r;
}
int IsPrime(int n)
{
    int i;
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}
void print_primebetween2numbers(int n1,int n2)
{
    int i;
    for(i=n1;i<=n2;i++)
    {
        if(IsPrime(i))
        {
            printf("%d,",i);
        }
    }
    printf("\n");
}

int main(void)
{
  int num1, num2, start, End,i;
  scanf("%d%d",&num1,&num2);
  if(num1<num2)
  print_primebetween2numbers(num1,num2);
  else
   print_primebetween2numbers(num2,num1); 

  
  return 0;
}




