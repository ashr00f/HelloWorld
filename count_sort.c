void counting_sort(int*arr,int size)
{
    int i,j=0,max=arr[0],min=arr[0],r,z,x=0;

max=array_max_min(arr,size,&min);
    x=(max-min)+1;
    int *s=(int*)calloc(x,sizeof(int));
    for(i=0; i<size; i++)
    {
        s[arr[i]-min]++;
    }
    for(i=0; i<x; i++)
    {
            for(z=0; z<s[i]; z++)
            {
                arr[j]=i+min;
                j++;
            }
    }
    free(s);
}
