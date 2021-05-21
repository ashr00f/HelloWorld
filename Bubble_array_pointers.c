void Bubble_Sort_array_of_pointers(char**arr,int size)
{
    int i,j,*temp;
    for(i=0;i<size-1;i++)
    {
        for(j=0;j<size-1;j++)
        {
          if(arr[j][0]>arr[j+1][0])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }

    }
}








    return 0;
}
