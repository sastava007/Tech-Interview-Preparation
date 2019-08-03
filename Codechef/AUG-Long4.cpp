#include<bits/stdc++.h>
using namespace std;
#define ll long long

void update(ll *d, ll l, ll r, ll value)
{
    d[l]+=value;
    d[r+1]-=value;

}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,i,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll c[n];

        for(i=0;i<n;i++)
        cin>>c[i];

        ll temp;
        unordered_map<ll,ll> z;
        for(i=0;i<n;i++)
        {
            cin>>temp;
            z[temp]++;
        }

        ll a[n]={0},d[n]={0};

        for(i=0;i<n;i++)
        {
            ll x=max(0ll, i-c[i]);

            ll y=min((n-1),i+c[i]);

            update(d,x,y,1);
        }

        unordered_map<ll,ll> m;
        for(i=0;i<n;i++)
        {
            if(i!=0)
                a[i]=a[i-1]+d[i];
            else
                a[i]=d[i];
            m[a[i]]++;
        }

        ll flag=0;
        for(auto it:z)
        {
            auto x=m.find(it.first);
            if(x==m.end() || x->second!=it.second)
                {
                    flag=1;
                    break;
                }
        }
        if(flag==0)
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }

}
