   Q1

{
    int i,r=-1,f=0;
    for(i=0; i<size; i++)
    {
        if (arr[i]==num)
        {
            if(0==f)
            {*num_lb=i;

            }
            r=i;
            f++;

        }
    }
        printf("%d",f);
    printf("%d\n",*num_lb);
    return r;

}

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    Q2
#include <stdio.h>
#include <stdlib.h>

int array_max_min_indexes(int*arr,int size,int max,int *min,int*max_index,int*min_index)
{

    int i;
    max=arr[0],*min=arr[0];
    for(i=0; i<size; i++)
    {
        if (arr[i]>max)
        {
            max=arr[i];
                *max_index=i;
        }
      else if (arr[i]<arr[0])
        {
           *min=arr[i];
           *min_index=i;
        }
        }

    return max;

}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
     Q3
	 int powerof3(int num)
{
    int i,x;
    for(i=1; i<num; i++)
    { x=(i*i*i);
        if(num==x)
        {
            return 0;
        }

    }
     return 1;
}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    Q4
int array_num_in_between(int num1,int num2,int*arr,int arr_size)
{
    int i,j=0,x;
    if(num1>num2)
    {
        x=num1;
        num1=num2;
        num2=x;
    }

    for(i=num1+1; i<num2; i++)
    {
      arr[j]=i;
      j++;

    }
    return j;
}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    Q5
int array_find_max_repeat(int*arr,int arr_size)
{
    int i,j,x=-1,z=-1,y;

    for(i=0; i<arr_size; i++)
    {
        for(j=0; j<arr_size; j++)
        {
            if(arr[i]==arr[j])
            {
                x++;
            }
        }
        if(x>z)
        {
            z=x;
            y=arr[i];
        }
        x=0;
    }
    printf("%d   %d   \n",y,z);
    return y;
}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    Q6
void array_reverse(int*arr,int size)
{  int i,x=size-1,z;

    for(i=0;i<size/2;i++)
    {
    z=arr[i];
   arr[i]=arr[x];
    arr[x]=z;
    x--;
    }

}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
     Q7
void array_swap(int*arr_1,int size_1,int*arr_2,int size_2)
{  int i,x;
  if (size_1>size_2)
        size_1=size_2;

    for(i=0;i<size_1;i++)
    {
    x=arr_1[i];
   arr_1[i]=arr_2[i];
    arr_2[i]=x;
    }

}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	 Q8
	 int array_find(int*arr,int arr_size,int num)
{
    int i,j,x=0,z=0,m=0;
    for(i=0; i<arr_size; i++)
    {
        if(arr[i]==num)
        {
            x++;
        }
        else
        {
             x=0;
        }
         
            if(x>m)
            {
                m=x;
            }
    }
    return m;
}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
     Q9
int array_find_most_repeat(int*arr,int arr_size)
{
    int i,j,x=0,z=0,y;
// 0ne for loop compare num with next num but save the num after each count
    for(i=0; i<arr_size; i++)
    {
        for(j=i; j<arr_size; j++)
        {
            if(arr[i]==arr[j])
            {
                x++;
            }
        }
        if(x>z)
        {
            z=x;
            y=arr[i];
        }
        x=0;
    }	 
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
     Q10
	 int array_merge(int*arr1,int*arr2,int*ar,int size1)
{
    int i,j=0,m=size1*2;
    for(i=0; i<m; i=i+2)
    {
        ar[i]=arr1[j];
      
        ar[i+1]=arr2[j];
        j++;
    }
    return m;
}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    Q11 (not solved)
	int array_no_repeat(int*arr1,int*arr2,int size1)
{
    int i,j,m;
    for(i=0; i<size1; i++)
    {
        if(arr1[i]!=0)
        {
        for(j=0; j<size1;j++)
        {
            // printf("%d",arr1[j]);
            if(arr1[j+1]==arr1[i])
            {
                arr1[j]=0;

            }
            printf("%d",arr1[j]);
       }
        }
       printf("\n");
    }
   // array_print(arr1,size1);


   for(i=0; i<size1; i++)
    {
        if(arr1[i]==0)
        {
            j--;
        }
        else
        {
            arr1[i]=arr2[j];
        }
        j++;
    }
    return j;
}
\\\\\\\\\\\\\\\
void arrayRemoveRepeatedNum(int *arr, int size, int *returnedArr, int *returnedArrSize)
{
    int countArr = 0;
    arraySorting(arr, size);
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            returnedArr[countArr++] = arr[i];
        }
    }
    *returnedArrSize = countArr;
}

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
      Q12
	  void array_swap_after_zero(int*arr,int size)
{
    int i,j,m,f=0,s,r;

    for(i=0; i<size; i++)
    {
        if(arr[i]==0)
        {
            f++;
        }
        if(1==f)
        {
        m=i;
        f++;
        }
        if(3==f)
        {
        j=i;
        f++;
        }

    }
    for(r=m+1;r<=m+3;r++)
    {
      s=arr[r];
    arr[r]=arr[j+1];
    arr[j+1]=s;
    j++;
    }
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
      Q13
	  int array_max_diff(int*arr,int size)
{
    int i,j,min=arr[0],f=0,r;

    for(i=0; i<size; i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
           j=i;
        }

    }
    int max=arr[j];
    for(i=j; i<size; i++)
    {
   if(arr[i]>max)
   {
       max=arr[i];
   }
    }
    r=max-min;
return r;
}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
  Q14
  int array_find_most_repeat_mono(char*arr,int arr_size)
{
    int i,j,x=0,z=0,max=0;
    int arrr[256]= {0};

    for(i=0; i<arr_size; i++)
    {
        arrr[arr[i]]++;
    }

    for(i=0; i<256; i++)
    {
        if(arrr[i]>max)
        {
            max=arrr[i];
            z=i;
        }
    }


    printf("%d   \n",max);
    return z;
}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
   Q15
   void pointer_swap(int*p1,int*p2)
{
    int x,y;
    int**p3,**p4,**p;
    p1=&x;p2=&y;
    *p3=&(p1);
    *p4=&(p2);
    *p=*p3;
    *p3=*p4;
    *p4=*p;

}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    Q16
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    Q17	
  int i,x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,y;
    printf("Enter 10 numbers from 0 to 9");
    scanf("%d",&x0);
    scanf("%d",&x1);
    scanf("%d",&x2);
    scanf("%d",&x3);
    scanf("%d",&x4);
    scanf("%d",&x5);
    scanf("%d",&x6);
    scanf("%d",&x7);
    scanf("%d",&x8);
    scanf("%d",&x9);

    for(i=0;i<10;i++)
    {
      switch

    }
   