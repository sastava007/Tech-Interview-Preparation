#include <bits/stdc++.h>
#define deb(x) cout<<#x<<" "<<x<<"\n";
#define ll long long
using namespace std;

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
bool ifSet(int n, int i)
{
    return (n&(1<<i))!=0?true:false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        n=2*n+2;
        ll a[n], xore1=0, xore2=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            xore1^=a[i];
        }
        // deb(xore1);

        int index=firstSetBit(xore1);
        // deb(index);
        for(i=0;i<n;i++)
            {
                if(ifSet(a[i],index))
                    xore2^=a[i];
            }
        // deb(xore2);

        int ele1=xore2;
        int ele2=xore2^xore1;
        ele1<ele2?cout<<ele1<<" "<<ele2<<"\n":cout<<ele2<<" "<<ele1<<"\n";
            
    }
	return 0;
}