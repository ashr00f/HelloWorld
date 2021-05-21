int Power(int n,int p)
{
    int i,x=1;
    for (i=1; i<=p; i++)
        x=x*n;
    return x;
}
