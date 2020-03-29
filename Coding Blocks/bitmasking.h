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

// find position of first set bit from right (1-Based indexing)
int firstSetBit(int n)
{
    int c=0;
    if(n==0)
        return c;
    while((n&1)!=1)
    {
        c++;
        n>>=1;
    }
    return c+1;
}

// Return ith bit of a binary number from right
int ithbit(int n,int i)
{
    return (n&(1<<i))!=0?1:0;
}

// Set the ith bit to 1
void setithbit(int &n,int i)
{
    n=n|(1<<i);
}

//Set the ith bit to 0
void clearithbit(int &n,int i)
{
    int mask=~(1<<i);
    n=n&mask;
}

void clearLastIBit(int &n, int i)
{
    // We need a mask like this 111111111000 (if i=3) To get all 1 we can start with -1 which is stored as 2s complement
    int mask = -1<<i;
    n=n&mask;
}

void clearRangeBits(int &n, int l, int r)
{   
    // if n=31 0011111, l=1 and r=3 then mask=1110001 mask = a|b where a = 1110000 and b = 0000001 
    // a can be build using (-1)<<(r+1) and b can be using 2^i-1 which is same as 1<<i - 1
    int a = (-1)<<(r+1);
    int b = (1<<l) -1;
    int mask = a|b;
    n=n&mask;
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
