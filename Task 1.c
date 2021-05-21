int array_binary_search2(int*arr,int arr_size)
{

    int first=0,last,mid,z=0,max=0;

    last=arr_size-1;

    while(first<=last)
    {
        mid=(first+last)/2;

        if(arr[mid]!=arr[mid-1]&&arr[mid]!=arr[mid+1])
        {
            printf("%d\n",arr[mid]);
            return  mid;
        }
        else if(arr[mid]==arr[mid+1])
        {
            if(mid%2==0)
            {
                 printf("%d\n",mid);
                first=mid+1;
            }
            else
            {
           printf("%d\n",mid);
               last=mid-1;
            }
        }

        else //if(arr[mid]==arr[mid-1])
        {
           if(mid%2==0)
            {
             printf("%d\n",mid);
                last=mid-1;
            }
            else
            {printf("%d\n",mid);
                first=mid+1;
            }
        }
    }
    return -1;
}
void atm_min(int num,int*arr)
{
    int i,f=0,last,mid,z=0,max=0;
    int ar[7]= {1,5,10,20,50,100,200};
    array_print(ar,7);
    for(i=6; i>=0; i--)
    {
        arr[i]=num/ar[i];
        num=num%ar[i];

        }
}

