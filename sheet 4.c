   Q1
      void string_reverse(char*str)
{
    int i,x,l;
    char z;
l=str_len(str);
x=l-1;
    for(i=0; i<l/2;i++)
    {
        z=str[i];

        str[i]=str[x];

        str[x]=z;
        x--;

    }
}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    Q2
	int string_mirror_check(char*str)
{
    int i,x,l;
    char z;
    l=str_len(str);
    x=l-1;
    for(i=0; i<l/2; i++)
    {
        if(str[i]!=str[x])
        {
            printf("not mirror\n");
           return -1;
        }
        x--;
    }
    printf("mirror\n");
    return 1;
}

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
   Q3
   void string_circular_shift(char*str)
{
    int i,x,y=0,f=0,g=0,z,r=0,j;
    z=str_len(str);
    for(j=0; j<z; j++)
    {
        x=str[z-1];
        for(i=z-1; i>y; i--)
        {
            str[i]=str[i-1];
        }
        if(str[z-1]==' ')
        {
            r=f;
            g=1;
        }
        f++;
        str[y]=x;
        if(1==g)
        {
            y=r;
            g=0;
        }
    }
}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
   Q4
   void stringToInt_triangle(char*str,char*res)
{
    int i,x=0,x1=0,x2=0,f=0;
    char a[]="Equilateral triangle";
    char b[]="Isosceles triangle";
    char c[]="Scalene triangle";
    char d[]="Not triangle";

    for(i=0; str[i]; i++)
    {
        if (str[i]==' ')
        {
            f++;
        }
        switch (f)
        {
        case 0 :

            if(str[i]>='0'&&str[i]<='9')
            {
                x=(str[i]-'0')+x*10;
                printf("%d\n",x);
            }
            break;
        case 1 :
            if(str[i]>='0'&&str[i]<='9')
            {
                x1=(str[i]-'0')+x1*10;
                printf("%d\n",x1);
            }
            break;
        case 2 :
            if(str[i]>='0'&&str[i]<='9')
            {
                x2=(str[i]-'0')+x2*10;
                printf("%d\n",x2);
            }
            break;
        }
    }
    if((x+x1)>x2&&(x1+x2)>x&&(x2+x)>x1)
    {

        if(x==x1&&x1==x2)
        {
            str_copy(a,res,25);

        }
        else if(x==x1||x1==x2)
        {
            str_copy(b,res,25);

        }
        else
        {
            str_copy(c,res,25);

        }
    }
    else
    {
        str_copy(d,res,25);


    }


}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    Q5
	void floatTostring(float num,char*str)
{
     int i=0,j,x,y,z,r=1,v=10,a,rr;
    x=num;
    while(x)
    {
        x=x/10;
        i++;
    }
    rr=i;
    x=num;
while(x)
   {
       y=x%10;

str[i-1]=y+'0';
x=x/10;
i--;
   }
   i=rr;
  str[i]='.';
  z=num;
 num=num-z;
i++;
r=num*v;
for(j=0;j<2;j++)
 {
    str[i]=r+'0';

 v=v*10;
 a=num*v;
  r=((a%10)%10);
    i++;
 }
 str[i]=0;
}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
   Q6
   