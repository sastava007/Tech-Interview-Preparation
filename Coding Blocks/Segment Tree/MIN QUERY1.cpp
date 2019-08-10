#include<bits/stdc++.h>
#define ll long long
using namespace std;

void builtseg(ll *arr, ll *seg, int low, int high, int node)
{
    if(low==high)       ///we are building the tree bottom to top
    {
        seg[node]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    builtseg(arr, seg, low, mid, 2*node+1);
    builtseg(arr, seg, mid+1, high, 2*node+2);
    /// node will store minimum of its child nodes, for minimum range query!
    seg[node]=min(seg[2*node+1], seg[2*node+2]);
}

void updateQuery(ll *seg, ll qlow, ll qhigh, int low, int high, int node, ll value)
{
    if(high<qlow || low>qhigh)     /// no overlapping
    return;

    if(low==high)           ///we are updating the tree bottom to top
    {
        seg[node]=value;
        return;
    }
    int mid=(low+high)/2;
    updateQuery(seg,qlow,qhigh,low,mid,2*node+1,value);
    updateQuery(seg,qlow,qhigh,mid+1,high,2*node+2,value);

    seg[node]=min(seg[2*node+1], seg[2*node+2]);
}

ll rangeQuery(ll *seg, ll qlow, ll qhigh, int low, int high, int node)
{
    ///We have total 3 types of overlapping possible
        /// 1. Partial overlapping: when some part of segment range lies within query range
        /// 2. Total overlapping: when segment range lies completely within query range
        /// 3. No overlapping: when segment range lies totally outside the query range

    if(low>=qlow && high<=qhigh)   ///total overlapping
    return seg[node];

    if(high<qlow || low>qhigh)     /// no overlapping
    return INT_MAX;

    int mid=(low+high)/2;          ///this is a top-bottom approach
    return min(rangeQuery(seg,qlow,qhigh,low,mid,2*node+1),rangeQuery(seg,qlow,qhigh,mid+1,high,2*node+2));

}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q,i;
    ll t,qlow,qhigh;
    cin>>n>>q;
    ll a[n];
    for(i=0;i<n;i++)
    cin>>a[i];

    ll x = (int)(ceil(log2(n)));
    ll max_size = 2*(int)pow(2, x) - 1;

    ll seg[max_size];

    builtseg(a,seg,0,n-1,0);

    while(q--)
    {
        cin>>t>>qlow>>qhigh;
        if(t==1)
        cout<<rangeQuery(seg,qlow-1,qhigh-1,0,n-1,0)<<"\n";
        else
        updateQuery(seg,qlow-1,qlow-1,0,n-1,0,qhigh);
    }


}
