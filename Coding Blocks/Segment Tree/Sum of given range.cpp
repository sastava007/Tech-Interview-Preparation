#include<bits/stdc++.h>
using namespace std;
#define ll long long

void buildTree(int *a, int *seg, int low, int high, int node)
{
    if(low==high)
    {
        seg[node]=a[low];
        return;
    }

    int mid=(low+high)/2;
    buildTree(a,seg,low,mid,2*node+1);
    buildTree(a,seg,mid+1,high,2*node+2);

    ll t1=seg[2*node+1]+seg[2*node+2];
    ll t2=max(seg[2*node+1],seg[2*node+2]);
    seg[node]=max(t1,t2);

}

void updateQuery(int *seg, int qlow, int qhigh, int low, int high, int node, int value)
{
    ///no overlapping
    if(high<qlow || low>qhigh)
    return;

    if(low==high)
    {
        seg[node]+=value;
        return;
    }

    int mid=(low+high)/2;
    updateQuery(seg,qlow,qhigh,low,mid,2*node+1,value);
    updateQuery(seg,qlow,qhigh,mid+1,high,2*node+2,value);

    seg[node]=seg[2*node+1]+seg[2*node+2];

}

void lazyUpdateQuery(int *seg, int *lazy, int qlow, int qhigh, int low, int high, int node, int value)
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

    if(qlow<=low && high<=qhigh)
    {
        seg[node]+=value;
        if(low!=high)
        {
            lazy[2*node+1]+=value;
            lazy[2*node+2]+=value;
        }
        return ;
    }
    int mid=(low+high)/2;
    lazyUpdateQuery(seg,lazy,qlow,qhigh,low,mid,2*node+1,value);
    lazyUpdateQuery(seg,lazy,qlow,qhigh,mid+1,high,2*node+2,value);

}

int rangeQuery(int* seg, int qlow, int qhigh, int low, int high, int node)
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
    return seg[node];

    ///partial overlapping
    int mid=(low+high)/2;
    return (rangeQuery(seg,qlow,qhigh,low,mid,2*node+1)+rangeQuery(seg,qlow,qhigh,mid+1,high,2*node+2));

}

int lazyRangeQuery(int* seg, int * lazy, int qlow, int qhigh, int low, int high, int node)
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

    /// no overlapping
    if(high<qlow || low>qhigh)
        return 0;
    /// total overlapping
    if(low>=qlow && high<=qhigh)
        return seg[node];

    ///partial overlapping

    int mid=(low+high)/2;
    return lazyRangeQuery(seg,lazy,qlow,qhigh,low,mid,2*node+1)+lazyRangeQuery(seg,lazy,qlow,qhigh,mid+1,high,2*node+2);
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i,n;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];

    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;

    int seg[max_size],lazy[max_size];

    buildTree(a,seg,0,n-1,0);

    //cout<<"Sum of values in given range: "<<lazyRangeQuery(seg,lazy,1,3,0,n-1,0)<<"\n";

    //lazyUpdateQuery(seg,lazy,1,1,0,n-1,0,10);

    //cout<<"Sum of values in given range after upgradation : "<<lazyRangeQuery(seg,lazy,1,3,0,n-1,0)<<"\n";

    cout<<rangeQuery(seg,3,3,0,n-1,0);





}
