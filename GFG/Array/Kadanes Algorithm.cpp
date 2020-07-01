/* Find maximum sum subarray: Kadanes's Algorithm */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0], maxsum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            sum=max(nums[i],nums[i]+sum);
            maxsum=max(sum,maxsum);
        }
        return maxsum;
    }
};

/*  Maximum Subarray Sum using D&C 
    TC: O(NlogN) and Space: O(logN)
*/

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