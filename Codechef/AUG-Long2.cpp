/*August Long Challenge Div2:https://www.codechef.com/AUG19B/problems/DSTAPLS*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<<"\n";

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;

        ll t1=n/k;
        ll t2=__gcd(n, k);
        if(k==1)
        cout<<"NO\n";

        else if(t1%t2==0)
        cout<<"NO\n";
        else
        cout<<"YES\n";
    }
}
