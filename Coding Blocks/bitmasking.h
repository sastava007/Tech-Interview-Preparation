// Time complexicity O(no of set bits). This approach will keep on removing the last set bit

int set_bits(int n)
{
    static int setbits=0;
    if(n>0)
    {
        setbits++;
        n=n&(n-1);
        set_bits(n);

    }
    else
    return setbits;

}

// Return ith bit of a binary number
int ithbit(int n,int i)
{
    return (n&(1<<i))!=0?1:0;
}

// Set the ith bit to 1
void setithbit(int *n,int i)
{
    *n=*n|(1<<i);
}

//Set the ith bit to 0
void clearithbit(int *n,int i)
{
    int a=~(1<<i);
    *n=*n&a;
}

//Print all the subsequences of a string
/*
void filterchar(char *a,int n)
{
    int i=0;
    while(n>0)
    {
        (n&1==1)?cout<<a[i]:cout<<"";
        i++;
        n=n>>1;
    }
}
*/
void generate_subs(char *a)
{
    int n=strlen(a);
    int range=(1<<n)-1;
    for(int i=0;i<=range;i++)
    {
        //   filterchar(a,i);
    }
}

//check whether a number is odd or even using bit wise operator
bool odd_even(int n)
{
    if(n&1)
        return true;
    else
        return false;
}
