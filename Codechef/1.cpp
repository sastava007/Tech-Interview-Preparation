#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> subset_sum(vector<ll> v,ll n)
{
    ll range=(1<<n),i;
    vector<ll> ans;
    for(i=1;i<range;i++)
    {
        ll j=i,idx=0,sum=0;
        while(j>0)
        {
            if(j&1)
                sum+=v[idx];
            j=j>>1;
            idx++;
        }
        ans.push_back(sum);
    }
    return ans;
}

main()
{
    ios_base:: sync_with_stdio(false);
        cin.tie(NULL);


    ll n,a,b,i;
    cin>>n>>a>>b;

    ll ele;
    vector<ll> v1,v2;
    for(i=0;i<n;i++)
        {
            cin>>ele;
            if(i<=(n/2))
            v1.push_back(ele);
            else
            v2.push_back(ele);
        }

   ll n1=v1.size();
   ll n2=v2.size();
    vector<ll> sv1,sv2;
    sv1=subset_sum(v1,n1);
    sv2=subset_sum(v2,n2);

    sv1.push_back(0);
    sv2.push_back(0);

    sort(sv2.begin(),sv2.end());
    ll ans=0;
    for(auto it:sv1)
    {
        ll lb=lower_bound(sv2.begin(),sv2.end(),a-it)-sv2.begin();
        ll ub=upper_bound(sv2.begin(),sv2.end(),b-it)-sv2.begin();
        ans+=(ub-lb);

    }
    cout<<ans;


}
