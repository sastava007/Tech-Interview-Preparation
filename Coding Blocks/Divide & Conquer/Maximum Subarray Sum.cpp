#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma gcc optimize("ofast")

ll crossSum(ll *a, int low, int mid, int high)
{
    ll sum=0,left=LONG_MIN,right=LONG_MIN;
    for(int i=mid;i>=low;i--)
    {
        sum+=a[i];
        left=max(sum,left);
    }
    sum=0;
    for(int i=mid+1;i<=high;i++)
    {
        sum+=a[i];
        right=max(right,sum);
    }
    return left+right;
}

ll maxSubarraySum(ll *a, int low, int high)
{
    if(low==high)
        return a[low];
    int mid=(low+high)/2;
    ll left=maxSubarraySum(a,low,mid);
    ll right=maxSubarraySum(a,mid+1,high);
    ll cross=crossSum(a,low,mid,high);
    return max({left,right,cross});
}
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        ll a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        cout<<maxSubarraySum(a,0,n-1)<<"\n";
    }
}
