#include<bits/stdc++.h>
using namespace std;

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

    seg[node]=seg[2*node+1]+seg[2*node+2];

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

    int seg[max_size];

    buildTree(a,seg,0,n-1,0);

    cout<<"Sum of values in given range: "<<rangeQuery(seg,1,3,0,n-1,0)<<"\n";

    updateQuery(seg,1,1,0,n-1,0,10);

    cout<<"Sum of values in given range after upgradation : "<<rangeQuery(seg,1,3,0,n-1,0)<<"\n";





}
