void Bubble_Sort(int *arr,int size)
{
    int i=0,j,temp,c=0,flag=0;
    for(i=0;i<size;i++)
    {
       flag=0;
        for(j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
            c++;
        }
        if(flag==0)
            break;
    }
printf("%d\n\n",c);
}



int main()
{
int i,arr[]={100,120,1,4,5,3,20,45,-20,8,100,7,-8,0,2,5,10,5};

int size=sizeof(arr)/sizeof(arr[0]);
printf("%d\n\n",size);
array_print(arr,size);
Bubble_Sort(arr,size);
Bubble_Sort(arr,size);
array_print(arr,size);











    return 0;
}
