#include<bits/stdc++.h>
using namespace std;

// Time complexicity O(no of bits)
/*
int set_bits(int n)
{
    int setbits=0;
    while(n=n>>1)
        setbits++;
    return setbits;
}
*/
// Time complexicity O(no of set bits). This approach will keep on removing the last setbits
void filterchar(char *a,int n)
{
    int i=0;
    while(n>0)
    {
        n&1==1?cout<<a[i]:cout<<"";
        i++;
        n=n>>1;
    }
    cout<<"\n";
}
void generate_subs(char *a)
{
    int n=strlen(a);
    int range=(1<<n)-1;
    for(int i=0;i<=range;i++)
    {
        filterchar(a,i);
    }
}


main()
{
    char a[]="abc";
    generate_subs(a);
}
