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