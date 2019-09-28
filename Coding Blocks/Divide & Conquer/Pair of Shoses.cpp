#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma gcc optimize("ofast")
#define deb(x) cout<<#x<<" "<<x<<"\n"

int bsearch(ll *a, int low, int high, ll k)
{
    if(low<=high)
    {
        int mid=low+(high-low)/2;
        if(a[mid]==k)
            return mid;
        if(k<a[mid])
            return bsearch(a,low,mid-1,k);
        else
            return bsearch(a,mid+1,high,k);
    }
    return -1;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll a[n],k;
        for(i=0;i<n;i++)
            cin>>a[i];
        cin>>k;
        sort(a,a+n);

        ll min_diff=INT_MAX;
        pair<ll,ll> ans;

        for(i=0;i<n;i++)
        {
            int pos=bsearch(a,i+1,n-1,k-a[i]);

            if(pos!=-1)
            {
                if((a[pos]-a[i])<min_diff)
                    {
                        ans=make_pair(a[i],a[pos]);
                        min_diff=a[pos]-a[i];
                    }
            }
            //deb(pos);
        }
        cout<<"Deepak should buy roses whose prices are "<<ans.first<<" and "<<ans.second<<".\n";
    }
}
