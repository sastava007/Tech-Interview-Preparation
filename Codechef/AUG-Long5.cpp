#include<bits/stdc++.h>
#define ll long long
using namespace std;

class solution
{
    public:
    ll solve(ll *arr, int n)
    {
        unordered_map<ll, vector<ll>> m;
        ll ans=0,i;
        m[arr[0]].emplace_back(0);
        for(i=1;i<n;i++)
        {
            arr[i]^=arr[i-1];
            if(!arr[i])
            ans+=i;
            m[arr[i]].emplace_back(i);
        }

        for(auto it:m)
        {
            ll size=it.second.size();
            if(size>=2)
            {
                vector<ll> v=it.second;
                for(int j=0;j<size;j++)
                ans+=(v[j]*(2*j-size+1));

                ans-=((size)*(size-1))/2;
            }
        }
        m.clear();
        return ans;
    }

};

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll a[n];
        for(i=0;i<n;i++)
        cin>>a[i];
        solution obj;
        cout<<obj.solve(a,n)<<"\n";
    }

}
