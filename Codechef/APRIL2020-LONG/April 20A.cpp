#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int t,n,i,j;
    cin>>t;
    while (t--)
    {
        cin>>n;
        ll a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n,greater<ll>());
        for(i=0;i<n;i++)
            a[i]=a[i]-i>0?a[i]-i:0;

        ll ans=0;
        for(i=0;i<n;i++)
        {
            ans = (ans%mod +a[i]%mod)%mod;
        }
        cout<<ans<<"\n"; 
    }
    return 0;
}