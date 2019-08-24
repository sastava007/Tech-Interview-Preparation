#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a[100005];
ll tree[400020],lazy[400020]={0};
int k,n;

ll compute(int low, int k)
{
    ll ans=0;
    for(int i=1;i<=k;i++)
    {
        int temp=(low+n-i)%n+1;
        ans+=a[temp];
    }
    return ans;
}
void builtTree(int low, int high, int node)
{
    if(low=high)
    {
        tree[node]=compute(low,k);
        return;
    }
    int mid=low+(high-low)/2;
    builtTree(low, mid, 2*node);
    builtTree(mid+1,high,2*node+1);

    tree[node]=tree[2*node]+tree[2*node+1];
    return;
}

void update(int low, int high, int qlow, int qhigh, int node, int value)
{
    if(lazy[node]!=0)
    {
        tree[node]+=lazy[node];
        if(low!=high)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }

    if(qlow<=low && high<=qhigh)
    {
        tree[node]=value;
        if(low!=high)
        {
            lazy[2*node]+=value;
            lazy[2*node+1]+=value;
        }
        return ;
    }
    int mid=low+(high-low)/2;
    update(low,mid,qlow,qhigh,2*node,value);
    update(low,mid,qlow,qhigh,2*node+1,value);

    tree[node]=tree[2*node]+tree[2*node+1];
    return;

}

ll query(int low, int high, int qlow, int qhigh, int node)
{
    if(lazy[node]!=0)
    {
        tree[node]+=lazy[node];
        if(low!=high)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(high<qlow || low>qhigh)          /// no overlapping
        return 0;

    if(low>=qlow && high<=qhigh)        ///total overlapping
        return tree[node];

int mid=low+(high-low)/2;
    ll left=query(low, mid,qlow, qhigh, 2*node);
    ll right=query(mid+1, high, qlow, qhigh, 2*node+1);
    return left+right;
}


int main()
{
    int i,q;
    cin>>n>>k>>q;
    for(i=0;i<n;i++)
    cin>>a[i];
    builtTree(0,n-1,1);
    int t,l,r;
    while(q--)
    {
        cin>>t>>l>>r;
        if(t==1)
            update(0,n-1,l-1,l-1,1,r);
        else
            cout<<query(0,n-1,l-1,r-1,1)<<"\n";
    }

}

