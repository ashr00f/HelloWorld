int main()
{int max;
   int arr1[20]={1,9,1,3,0,0,0,5,7,8,2,9,4,2,4,7,88,99,26,35};
   max =array_maxrebeat(arr1,20);
   printf("\n%d",max);
   return 0;

}

int array_maxrebeat(int *arr1,int size)
{int max,min,i=0,countsize,index=0,j;
int count[100]={0};
    max =array_max(arr1,size);
    min=array_min(arr1,size);
printf("%d\n",max);
printf("%d\n",min);
    countsize=max-min+1;
    for(i=0;i<size;i++)
    {
        count[arr1[i]-min]++;
    }
//array_print(count,100);
    int maxcount=count[0];
    for(j=0; j<countsize; j++)
    {
        if(count[j]>maxcount)
        {
            maxcount=count[j];
            index=j;
        }
    }

    return index+min;
}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
int count_size=max-min+1;       //for readability

        int *unique=(int*)calloc(sizeof(int),(max-min+1));

