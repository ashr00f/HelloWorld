void Bubble_Sort_array_of_pointers(char**arr,int size)
{
    int i,j,*temp,r;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size-1;j++)
        {
          if(string_compare_1(arr[j],arr[j+1])==2)
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }

        }

    }
}
///////////////////////////////////////////////////////////////////////
void array_print_2d(int *arr[6][5])
{
    int i,j;
    for(i=0; i<6; i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%d,",arr[i][j]);
        }
        printf("    ////   ");
    }
    printf("\n");

}
void Bubble_Sort_2d_array(char* arr[6][5])
{
    int i,j,*temp,r;
    for(i=0;i<6;i++)
    {
          Bubble_Sort(arr[i],5);


    }
}
