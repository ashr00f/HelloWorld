      Q1
	  int missing_num(int*arr,size)
{
    int i,s=0,x;
    
    for(i=0; i<size; i++)
    {
       s=s+arr[i];
    }
   x=((size*(size+1))/2)-s;
    return x;
}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
     Q2

int missing_num(int*arr,size)
{
    int i,s=0,x;
    
    for(i=0; i<size; i++)
    {
       s=s+arr[i];
    }
   x=s-((size*(size+1))/2);
    return x;
}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    Q3
int missing_num(int*arr,size)
{
    int i,s=0,x;
    
    for(i=0; i<size; i++)
    {
       s=s^arr[i];
    }
  
    return s;
}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
     Q4
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
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
     Q5
int array_find_most_repeat_mono(int*arr,int arr_size)
{
    int i,j,x=0,z=0,max=0;
    int arrr[10]= {0};

    for(i=0; i<arr_size; i++)
    {
        arrr[arr[i]]++;
    }

    for(i=0; i<10; i++)
    {
        if(arrr[i]>max)
        {
            max=arrr[i];
            z=i;
        }
    }


    printf("%d   \n",max);
    return z;
}\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
     Q6
char f_repeated_char(char*str)
{
    int i,j,max=0;
    char s[256]={0};
char r,z;
    for(i=0;str[i];i++)
    {
        r=str[i];
        // printf("%d  %c",r,r);
        s[r]++;
      // printf("%d\n",s[r]);
    }

    for(i=0; i<256; i++)
    {
        if(s[i]>max)
        {
            max=s[i];
           // printf("\n%d\n",max);
            j=i;
        }
    }
    //printf("%d\n",j);
    char ss[256];
    for(i=0; i<256; i++)
    {
        ss[i]='0'+i;

    }
    z=ss[j-'0'];


    return z;
}
     (or)
int f_repeated_char(char*str)
{
    int i,j=0,max=1;
    int s[256]={0};
char r,z;
    for(i=0;str[i];i++)
    {
        r=str[i];

        s[r]++;
         if(s[r]>max)
        {
            return str[i];
        }
       
    }
  
}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
     Q7
	 void f_repeated_char_remove(char*str,char*str_c)
{
    int i,j=0;
   char s[256]={0};
char r,z;
    for(i=0;str[i];i++)
    {
        r=str[i];
        s[r]++;
        if(s[r]==1)
        {
            str_c[j]=str[i];

            j++;
        }
    }

     str_c[j]=0;
}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    Q8
	int arr_end_num(int*arr,int size,int*arr_n,int size_n,int num)
{
    int i,j=0,max=1;

    for(i=0;i<size;i++)
    {

         if(arr[i]!=num)
        {
            arr_n[i]=arr[i];
        }
        else
        {
            break ;
        }

    }
return i ;
}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
   Q9
    \\\\\    (a)    ////////
	void num_byte_swap(char *num)
{
    char x;
    char *p1=num+1;
        x=*num;
       *num=*p1;
        *p1=x;
		
}
		\\\\\\\\\\\\\
		void num_byte_swap(char *num)
{
    char x,y;
    char *p=num,*p1=num+1,*p2=num+2;
    char*p3=num+3;
        x=*num;
       *num=*p3;
        *p3=x;
         y=*p1;
         *p1=*p2;
         *p2=y;
}


     \\\\\    (b)    ///////
	 

void num_byte_swap(short *num)
{
    short x,y;
   x=*num>>8;
   y=*num<<8;
   *num=x|y;
}
       \\\\\\\\\\\
	   
	 