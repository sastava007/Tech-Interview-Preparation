
        /* https://www.geeksforgeeks.org/maximum-subarray-sum-given-range/  */


#include<bits/stdc++.h>
using namespace std;
#define ll long long

class node
{
    public:
        ll prefixSum;
        ll suffixSum;
        ll totalSum;
        ll maxSum;
        node()          ///constructor to initialize all values with int_min
        {
            prefixSum=LLONG_MIN;
            suffixSum=LLONG_MIN;
            totalSum=LLONG_MIN;
            maxSum=LLONG_MIN;
        }
};

ll arr[100005];
vector<node>tree(400020);

node mergeNode(node left, node right)
{
    node current;
    current.prefixSum=max(left.totalSum+right.prefixSum,left.prefixSum);
    current.suffixSum=max(right.totalSum+left.suffixSum,right.suffixSum);
    current.totalSum=left.totalSum+right.totalSum;
    current.maxSum=max(max(left.maxSum,right.maxSum),left.suffixSum+right.prefixSum);

    return current;
}

void buildTree(int low, int high, int index)
{
    if(low==high)
    {

        tree[index].prefixSum=arr[low];
        tree[index].suffixSum=arr[low];
        tree[index].totalSum=arr[low];
        tree[index].maxSum=arr[low];

        return;
    }

    int mid=(low+high)/2;
    buildTree(low,mid,2*index+1);
    buildTree(mid+1,high,2*index+2);

    node left=tree[2*index+1];
    node right=tree[2*index+2];

    tree[index]=mergeNode(left,right);
    return;
}

node rangeQuery(int qlow, int qhigh, int low, int high, int index)
{

    ///NO OVERLAPPING
    if(high<qlow || low>qhigh)
    {
        node temp;
        return temp;
    }

    ///total overlapping
    if(qlow<=low && high<=qhigh)
    return tree[index];

    ///partial overlapping
    int mid=(low+high)/2;

    if(qhigh<=mid) /// Add this case.
       return rangeQuery(qlow,qhigh,low,mid,2*index+1);
    if(qlow>mid)  /// Add this case.
       return rangeQuery(qlow,qhigh,mid+1,high,2*index+2);

    node left=rangeQuery(qlow,qhigh,low,mid,2*index+1);
    node right=rangeQuery(qlow,qhigh,mid+1,high,2*index+2);

    return mergeNode(left,right);

}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q,l,r;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>arr[i];

    buildTree(0,n-1,0);
    cin>>q;

    while(q--)
    {
        cin>>l>>r;
        cout<<rangeQuery(l-1,r-1,0,n-1,0).maxSum<<"\n";
    }
}
