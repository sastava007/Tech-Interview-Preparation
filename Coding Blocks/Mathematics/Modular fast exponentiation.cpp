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
main()
{
    ll a=2;
    ll b=100;
    cout<<power(a,b,10);

}
