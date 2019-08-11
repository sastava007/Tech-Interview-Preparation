/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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

    seg[node]=min(seg[2*node+1],seg[2*node+2]);
}

ll query(ll *seg, int qlow, int qhigh, int low, int high, int node, ll k)
{
        ///We have total 3 types of overlapping possible
        /// 1. Partial overlapping: when some part of segment range lies within query range
        /// 2. Total overlapping: when segment range lies completely within query range
        /// 3. No overlapping: when segment range lies totally outside the query range

    ///NO OVERLAPPING
    if(high<qlow || low>qhigh)
    return 0;

    ///total overlapping
    if(qlow<=low && high<=qhigh)
    {
        if(seg[node]>=k)
        return (high-low+1);
    }

    if((low==high) && seg[node]<k) /// this means that even when we have reached the last element of tree and it is also not greater than K then we can't go further & we need to return 0 from here
        return 0;
    ///partial overlapping
    int mid=(low+high)/2;
    return (query(seg,qlow,qhigh,low,mid,2*node+1,k)+query(seg,qlow,qhigh,mid+1,high,2*node+2,k));

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

*/

/*         Given a range and we need to find number of elements which are greater than or equal to a given value in that range
 *         Approach: Earlier I was using simple Segment trees to solve this problem but it was giving TLE so I shifted to segmen trees with vector where I can use lower_bound()
 *         to find all elements which are less than that value and subtract it from size of seg[node]
 */


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define deb(x) cout<<#x<<" "<<x<"\n"

vector<ll> seg[400005];     ///2D vector
vector<ll> a(400000);

void builtseg(int low, int high, int node)
{
    if(low==high)
    {
        seg[node].emplace_back(a[low]);
        return;
    }
    int mid=(low+high)/2;
    builtseg(low, mid, 2*node+1);
    builtseg(mid+1, high, 2*node+2);

    merge(seg[2*node+1].begin(),seg[2*node+1].end(),seg[2*node+2].begin(),seg[2*node+2].end(),back_inserter(seg[node]));
}

ll query(int qlow, int qhigh, int low, int high, int node, ll k)
{
    ///no overlapping
    if(high<qlow || low>qhigh)
        return 0;

    if(low>=qlow && high<=qhigh)        ///total overlapping
    {
        return seg[node].size()-(lower_bound(seg[node].begin(),seg[node].end(),k)-seg[node].begin());
    }

    ///partial overlapping
    ll mid=(low+high)/2;
    ll left=query(qlow,qhigh,low,mid,2*node+1,k);
    ll right=query(qlow,qhigh,mid+1,high,2*node+2,k);

    return left+right;

}

main()
{
    fast;
    int n,q,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];

    builtseg(0,n-1,0);
    cin>>q;
    int l,r;
    ll k;
    while(q--)
    {
        cin>>l>>r>>k;
        cout<<query(l-1,r-1,0,n-1,0,k)<<"\n";
    }

}



























