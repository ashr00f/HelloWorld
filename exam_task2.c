void array_swap_reverse (int*arr1,int*arr2,int size)
{

  int i,j=size-1,temp;
  
  for(i=0;i<size;i++)
  {
    temp=arr1[i];
	arr1[i]=arr2[j];
	arr2[j]=temp;
	j--;
  }
   
}
