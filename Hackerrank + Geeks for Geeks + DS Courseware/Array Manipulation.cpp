/*
 *     Simple Array Manipulation problem that can be solved using lazy segment tree which store maximum of each of it's children node.
 *     And finally call the query() over entire range to get the maximum of these elements.
 *     Hackerrank: https://www.hackerrank.com/challenges/crush/problem
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"

ll seg[40000005]={0}, lazy[40000005]={0};

void update(ll qlow, ll qhigh, ll low, ll high, ll node, ll value)
{
    if(lazy[node]!=0) ///it means it's some previous updates need to be done so first finish them then move forward
    {
        seg[node]+=lazy[node];

        if(low!=high) /// if it is not a leaf node so propogate the values to its child node for future update
        {
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
        lazy[node]=0;   ///reset that node, bcoz now its updated & no past update is left for that node

    }

    if(high<qlow || low>qhigh)     /// no overlapping
    return;

    if(low>=qlow && high<=qhigh) ///total overlapping
    {
        seg[node]+=value;
        if(low!=high)
        {   lazy[2*node+1]+=value;
            lazy[2*node+2]+=value;
        }
        return;
    }
    ll mid=(low+high)/2;
    update(qlow,qhigh,low,mid,2*node+1,value);
    update(qlow,qhigh, mid+1,high,2*node+2,value);
    seg[node]=max(seg[2*node+1],seg[2*node+2]);

}

ll query(ll qlow, ll qhigh, ll low, ll high, ll node)
{
    if(lazy[node]!=0)
    {
        seg[node]+=lazy[node];
        if(low!=high)
        {
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];

        }
        lazy[node]=0;
    }

    if(high<qlow || low>qhigh)     /// no overlapping
    return LLONG_MIN;

    if(low>=qlow && high<=qhigh)   ///total overlapping
    return seg[node];

    ll mid=low+(high-low)/2;
    ll left=query(qlow,qhigh,low,mid,2*node+1);
    ll right=query(qlow,qhigh,mid+1,high,2*node+2);

    return max(left,right);


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n;
    int m;
    cin>>n>>m;
    ll l,r,k;
    while(m--)
    {
        cin>>l>>r>>k;
        update(l-1,r-1,0,n-1,0,k);
    }
    cout<<query(0,n-1,0,n-1,0);
    return 0;

}
