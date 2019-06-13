#include<bits/stdc++.h>
using namespace std;
#define ll long long

unordered_set<ll> subset_sum(vector<ll> v,int n)
{
    ll range=(1<<n),i;
    unordered_set<ll> ans;
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
        ans.insert(sum);
    }
    return ans;
}

main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);

    ll n,a,b,i;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
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
        ll k;
        cin>>k;

        ll n1=v1.size();
        ll n2=v2.size();
        unordered_set<ll> sv1,sv2;
        sv1=subset_sum(v1,n1);
        sv2=subset_sum(v2,n2);
        sv1.insert(0);
        sv2.insert(0);

        string possible="No";
        for(auto it:sv1)
        {
            if(sv2.find(k-it)!=sv2.end())
            {
                possible="YES";
                break;
            }
        }
        cout<<possible<<"\n";

    }




}
