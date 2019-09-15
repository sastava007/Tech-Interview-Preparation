#include<bits/stdc++.h>
using namespace std;

int sum=INT_MIN;
int max_sum_subarray(int low, int high, int *a)
{

    if(low==high)
    {
        return a[low];

    }

    int mid=(low+high)/2;
    int left=max_sum_subarray(low,mid,a);
    int right=max_sum_subarray(mid+1,high,a);

    if((left+right)>sum)
    sum=left+right;
    return sum;
}

main()
{
    int a[]={3,-1,-1,10,-3,-2,4};
    cout<<max_sum_subarray(0,6,a);


}
