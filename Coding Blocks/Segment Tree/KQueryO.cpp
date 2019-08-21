
/*     KQueryO Online: Find number of elements which are greter than 'k' in given range. Solved using online segment tree
 *     https://www.spoj.com/problems/KQUERYO/
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define deb(x) cout<<#x<<" "<<x<"\n"

vector<ll> seg[400005];     ///2D vector: to store elements at each node level
vector<ll> a(100000);

void builtTree(int low, int high, int node)
{
    if(low==high)
    {
        seg[node].emplace_back(a[low]);
        return;
    }
    int mid=(low+high)/2;
    builtTree(low,mid,2*node+1);
    builtTree(mid+1,high,2*node+2);
    merge(seg[2*node+1].begin(),seg[2*node+1].end(),seg[2*node+2].begin(),seg[2*node+2].end(),back_inserter(seg[node]));
}

ll query(int qlow, int qhigh, int low, int high, ll node, ll k)
{
    if(qlow>high || low>qhigh)      /// no overlapping
        return 0;

    if(low>=qlow && high<=qhigh)
    {
        return seg[node].size()-(upper_bound(seg[node].begin(),seg[node].end(),k)-seg[node].begin());
    }

    int mid=(low+high)/2;
    ll left=query(qlow, qhigh, low, mid, 2*node+1, k);
    ll right=query(qlow, qhigh, mid+1, high, 2*node+2, k);
    return left+right;
}

main()
{
    fast;
    int n,q,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];

    builtTree(0,n-1,0);
    cin>>q;
    int l,r;
    ll k,prev_ans=0;
    i=0;
    while(i<q)
    {
        cin>>l>>r>>k;

        l^=prev_ans;
        r^=prev_ans;
        k^=prev_ans;

        prev_ans=query(l-1,r-1,0,n-1,0,k);
        cout<<prev_ans<<"\n";

        i++;
    }
}
