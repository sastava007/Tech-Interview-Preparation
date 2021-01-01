/*  Find maximum sum subarray: Kadanes's Algorithm 
    To calculate sum(0,i), you have 2 choices: either adding sum(0,i-1) to a[i], or not. If sum(0,i-1) is negative, adding it to a[i] will only make a smaller sum,
    so we add only if it's non-negative.    sum(0,i) = a[i] + (sum(0,i-1) < 0 ? 0 : sum(0,i-1))
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0], maxsum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            sum = max(nums[i], nums[i]+sum);
            maxsum = max(sum, maxsum);
        }
        return maxsum;
    }
};

/* To print the subarray */
int maxSubArraySum(int a[], int size) 
{ 
    int max_so_far = INT_MIN, max_ending_here = 0, 
       start =0, end = 0, s=0; 
  
    for (int i=0; i< size; i++ ) 
    { 
        max_ending_here += a[i]; 
  
        if (max_so_far < max_ending_here) 
        { 
            max_so_far = max_ending_here; 
            start = s; 
            end = i; 
        } 
  
        if (max_ending_here < 0) 
        { 
            max_ending_here = 0; 
            s = i + 1; 
        } 
    }
    cout << "Maximum contiguous sum is "
        << max_so_far << endl; 
    cout << "Starting index "<< start 
        << endl << "Ending index "<< end << endl; 
}

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