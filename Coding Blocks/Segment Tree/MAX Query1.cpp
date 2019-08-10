#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"

void builtseg(ll *a, ll *seg, int low, int high, int node)
{
    if(low==high)
    {
        seg[node]=a[low];
        return;
    }
    int mid=(low+high)/2;
    builtseg(a, seg, low, mid, 2*node+1);
    builtseg(a, seg, mid+1, high, 2*node+2);

    seg[node]=max(seg[2*node+1],seg[2*node+2]);
}

ll query(ll *seg, int qlow, int qhigh, int low, int high, int node, ll k)
{
    if(high<qlow || low>qhigh)          ///no overlapping
        return 0;
    if(low>=qlow && high<=qhigh && seg[node]>=k)
    {
        ll ans=high-low+1;
        return ans;
    }

    int mid=(low+high)/2;
    return max(query(seg,qlow,qhigh,low,mid,2*node+1,k),query(seg,qlow,qhigh,mid+1,high,2*node+2,k));
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,i,q,l,r;
    ll k;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    cin>>q;
    int x=(int)ceil(log2(n));
    ll max_size = 2*(int)pow(2, x) - 1;
    ll seg[max_size];

    builtseg(a,seg,0,n-1,0);

    while(q--)
    {
        cin>>l>>r>>k;
        cout<<query(seg,l-1,r-1,0,n-1,0,k)<<"\n";

    }
}
