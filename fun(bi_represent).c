void bi_represent(int num)
{
    int i,f=0;
    for(i=31; i>=0; i--)
    {
        if((num>>i)&1)
        {
            printf("1");
            f=1;
        }
        else
        {  if(1==f)
            printf("0");
        }
    }
}




