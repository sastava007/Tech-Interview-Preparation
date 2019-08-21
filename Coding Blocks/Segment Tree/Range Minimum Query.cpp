/*
 Range Minimum Query using Segment seg: Thanks to Tushar Roy https://www.youtube.com/watch?v=ZBHKZF5w4YU
*/

#include<bits/stdc++.h>
using namespace std;

void builtseg(int *arr, int *seg, int low, int high, int node)
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

void updateQuery(int *seg, int qlow, int qhigh, int low, int high, int node, int value)
{
    if(high<qlow || low>qhigh)     /// no overlapping
    return;

    if(low==high)           ///we are updating the tree bottom to top
    {
        seg[node]+=value;
        return;
    }
    int mid=(low+high)/2;
    updateQuery(seg,qlow,qhigh,low,mid,2*node+1,value);
    updateQuery(seg,qlow,qhigh,mid+1,high,2*node+2,value);

    seg[node]=min(seg[2*node+1], seg[2*node+2]);
}

void updateLazyQuery(int* seg, int *lazy, int qlow, int qhigh, int low, int high, int node, int value)
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
    int mid=(low+high)/2;
    updateLazyQuery(seg,lazy,qlow,qhigh,low,mid,2*node+1,value);
    updateLazyQuery(seg,lazy,qlow,qhigh, mid+1,high,2*node+2,value);
    seg[node]=min(seg[2*node+1],seg[2*node+2]);

}
int rangeQuery(int *seg,int qlow, int qhigh, int low, int high, int node)
{
    ///We have total 3 types of overlapping possible
        /// 1. Partial overlapping: when some part of segment range lies within query range
        /// 2. Total overlapping: when segment range lies completely within query range
        /// 3. No overlapping: when segment range lies totally outside the query range

    if(low>=qlow && high<=qhigh)   ///total overlapping
    return seg[node];

    if(high<qlow || low>qhigh)     /// no overlapping
    return INT_MAX;

    int mid=low+(high-low)/2;         ///this is a top-bottom approach
    return min(rangeQuery(seg,qlow,qhigh,low,mid,2*node+1),rangeQuery(seg,qlow,qhigh,mid+1,high,2*node+2));

}

int rangeLazyQuery(int *seg, int *lazy, int qlow, int qhigh, int low, int high, int node)
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
    return INT_MAX;

    if(low>=qlow && high<=qhigh)   ///total overlapping
    return seg[node];

    int mid=low+(high-low)/2;
    return min(rangeLazyQuery(seg,lazy,qlow,qhigh,low,mid,2*node+1),rangeLazyQuery(seg,lazy,qlow,qhigh,mid+1,high,2*node+2));


}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i,n;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    cin>>arr[i];

    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;

    int seg[max_size];
    int lazy[max_size]={0};

    builtseg(arr,seg,0,n-1,0);
    cout<<"Without Update\n";
    cout<<rangeQuery(seg,1,n-1,0,n-1,0)<<"\n";

//    updateLazyQuery(seg, 0, n-1, 0, n-1, 0, 10);
//    cout<<"After update\n";
//    cout<<rangeLazyQuery(seg,0,n-1,0,n-1,0)<<"\n";

    for(i=0;i<n;i++)
    updateQuery(seg,i, i, 0, n-1, 0, 10);
    cout<<"After Lazy update\n";
    cout<<rangeQuery(seg,0,n-1,0,n-1,0)<<"\n";

    for(i=0;i<n;i++)
    cout<<rangeQuery(seg,i,i,0,n-1,0)<<" ";

}
