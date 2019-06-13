#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,sum=0,x;
        cin>>n;
        for (ll int x = n; x > 0; x = x / 10)
        sum = sum + x % 10;
        ll int z=sum;
        while(z%10!=0)
            z++;
        cout<<n<<z-sum<<"\n";
    }
}
