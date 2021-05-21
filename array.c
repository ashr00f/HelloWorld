#include <stdio.h>
#include <stdlib.h>
int IsPrime(int x)
{
    int i;
    for (i=2;i<x;i++)
    {
        if(x%i==0)
        {
            return 0;
        }
    }
         return 1;

}
int fact(int n);
void swap(int *px,int *py)
{
    int temp=*px;
    *px=*py;
    *py=temp;
}

int add_mul(int n1,int n2,int*pr_mul)
{
    *pr_mul=n1*n2;
    (n1)++;
    return n1+n2;
}

void array_print(int *arr,int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n");

}

int array_find(int*arr,int size,int element,int*pfirst_oc)
{
    int i,last_oc=-1,first_oc=-1,flag=0;
    for(i=0;i<size;i++)
    {
        if(arr[i]==element)
        {
            if(flag==0)
            {
                first_oc=i;
                flag=1;
            }
            last_oc=i;
        }
    }
    *pfirst_oc=first_oc;
    return last_oc;
}


int main(void)
{
   int n, arr[10]={70000,9,300,700,9,11,5020,9,5};
   scanf("%d",&n);
   int f_index,l_index;
 l_index  =array_find(arr,10,n,&f_index);
   if(l_index!=-1)
   printf("first find at %d  last at %d",f_index,l_index);
else
    printf("not found\n");


  return 0;
}




