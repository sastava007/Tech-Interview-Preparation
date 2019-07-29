#include<bits/stdc++.h>
#define ll long long
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        ll prefix_sum[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(i!=0)
            prefix_sum[i]=prefix_sum[i-1]+a[i];
            else
            prefix_sum[i]=a[i];
        }
        unordered_set<ll> s;
        bool flag=false;
        for(i=0;i<n;i++)
        {
            if(prefix_sum[i]==0)
            {
                flag=true;
                break;
            }
            if(s.find(prefix_sum[i])!=s.end())
            {
                flag=true;
                break;
            }
            else
            s.insert(prefix_sum[i]);
        }
        flag?cout<<"Yes\n":cout<<"No\n";
    }
}
