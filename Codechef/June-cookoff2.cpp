#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    int t;
    ll n,i,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ll taste[m+1]={0};
        ll d,v;
        while(n--)
        {
            cin>>d>>v;
            if(taste[d]==0)
                taste[d]=v;
            else
                taste[d]=max(taste[d],v);
        }
        sort(taste,taste+m+1,greater<int>());

        ll ans=taste[0]+taste[1];
        cout<<ans<<"\n";


    }
}

