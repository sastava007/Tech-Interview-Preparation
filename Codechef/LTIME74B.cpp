#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<<"\n";

ll sum(ll n)
{
    ll sum=0;
    while(n>0)
    {
        sum+=(n%10);
        n/=10;
    }
    return sum;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        ll a[n];
        for(i=0;i<n;i++)
            cin>>a[i];

        ll max_pro=0;

        for(i=0;i<n-1;i++)
        for(j=0;j<n;j++)
        {
            if(j!=i)
            {
                max_pro=max(max_pro,sum(a[i]*a[j]));

            }
        }
        cout<<max_pro<<"\n";

    }
}

