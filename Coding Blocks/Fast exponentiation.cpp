#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll power(ll a,ll b)
{
    if(b==0)
        return 1;
    // If b is even then b/2 else a(b/2)
    ll pre_ans=power(a,b/2);
    pre_ans*=pre_ans;
    if(b%2!=0)
        pre_ans*=a;
    return pre_ans;
}
main()
{
    ll a=3;
    ll b=10;
    cout<<power(a,b);

}
