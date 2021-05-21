int max_word_len (char*str)
{

  int i,j=0,max_len=0;
  
  for(i=0;str[i];i++)
  {
     if(str[i]==' ')
	 {
		 j=0;
	 }
	 else
	 {
		 j++;
	 }
       if(j>max_len)
	   {
		   max_len=j;
	   }
	   
  }
  return max_len ;
}
