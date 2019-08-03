/*
 Range Minimum Query using Segment Tree: Thanks to Tushar Roy https://www.youtube.com/watch?v=ZBHKZF5w4YU
*/

#include<bits/stdc++.h>
using namespace std;

void builtTree(int *arr, int *seg, int low, int high, int node)
{
    if(low==high)
    {
        seg[node]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    builtTree(arr, seg, low, mid, 2*node+1);
    builtTree(arr, seg, mid+1, high, 2*node+2);
    /// node will store minimum of its child nodes, for minimum range query!
    seg[node]=min(seg[2*node+1], seg[2*node+2]);

}

int rangeQuery(int *seg,int qlow, int qhigh, int low, int high, int node)
{
    ///We have total 3 types of overlapping possible
        /// 1. Partial overlapping: when some part of segment range lies within query range
        /// 2. Total overlapping: when segment range lies completely within query range
        /// 3. No overlapping: when segment range lies totally outside the query range

    if(low>=qlow && high<=qhigh)   ///total overlaping
    return seg[node];

    if(high<qlow || low>qhigh)     /// no overlapping
    return INT_MAX;

    int mid=(low+high)/2;
    return min(rangeQuery(seg,qlow,qhigh,low,mid,2*node+1),rangeQuery(seg,qlow,qhigh,mid+1,high,2*node+2));

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
    builtTree(arr,seg,0,n-1,0);
    cout<<rangeQuery(seg,1,5,0,n-1,0);

}
