#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll power(ll a,ll b, ll c)
{
    if(b==0)
        return 1;

    // If b is even then b/2 else a(b/2)

    ll pre_ans=power(a,b/2,c);
    pre_ans=(pre_ans*pre_ans)%c;
    if(b&1)
        pre_ans=(pre_ans*a)%c;
    return pre_ans;
}

ll generateFib(ll fib[], ll n)
{
    fib[0]=0LL;
    fib[1]=1LL;
    for(ll i=2;i<=n;i++)
    fib[i]=(fib[i-1]+fib[i-2])%10;
    return fib[n];
}

ll lastDigit(ll n)
{
    ll fib[60]={0LL};
    generateFib(fib,60);
    return fib[n];

}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    ll t;
    ll n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll c=round(log2(n));
        ll temp=(power(2LL,c,60LL)-1LL)%60;
        cout<<lastDigit(temp)<<"\n";
        //cout<<temp<<"\n";

    }
}
