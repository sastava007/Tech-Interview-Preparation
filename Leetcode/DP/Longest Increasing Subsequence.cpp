/* 
    For each element we've 2 options, either we take it or not which lead to longest increasing subsequence which will be max of both the lengths. But in this approach many sub-problems
    will be solved multiple times which we can avoid by memoizing the result.

    memo[i][j] represent the length of LIS, using/not using nums[i] as previous element and using/not using nums[j] as current element

    TC & Space: O(N^2) with memoization
*/

int lengthOfLIS(int[] nums)
{
    vector<vector<int>> memo(nums.size()+1, vector<int>(nums.size()+1, -1));
    return lengthofLIS(nums, -1, 0, memo);
}
int lengthofLIS(int[] nums, int previndex, int curpos, int[][] memo)
{
    if (curpos == nums.length) {
        return 0;
    }
    if (memo[previndex + 1][curpos] >= 0) {     // If we've already computed this, then just return it
        return memo[previndex + 1][curpos];
    }
    int taken = 0;
    if (previndex < 0 || nums[curpos] > nums[previndex]) {
        taken = 1 + lengthofLIS(nums, curpos, curpos + 1, memo);
    }

    int nottaken = lengthofLIS(nums, previndex, curpos + 1, memo);
    memo[previndex + 1][curpos] = Math.max(taken, nottaken);
    return memo[previndex + 1][curpos];
}

/* 
    DP Approach:  TC: O(N^2) and Space: O(N) 

    Input  : arr[] = {3, 10, 2, 11}
    LIS[] = {1, 1, 1, 1} (initially)
    Iteration-wise simulation :

    arr[2] > arr[1] {LIS[2] = max(LIS[2], LIS[1]+1)=2}
    arr[3] < arr[1] { No change }
    arr[3] < arr[2] { No change }
    arr[4] > arr[1] {LIS[4] = max(LIS [4], LIS[1]+1)=2}
    arr[4] > arr[2] {LIS[4] = max(LIS [4], LIS[2]+1)=3}
    arr[4] > arr[3] {LIS[4] = max(LIS [4], LIS[3]+1)=3}

    dp[i] represents length of the longest increasing subsequence ending at index 'i'

*/

int lengthOfLIS(vector<int>& nums)
{
    int ans = 0;
    if(nums.empty())
        return ans;
    
    vector<int> dp(nums.size(),1);
    for(int i=0; i<nums.size(); i++)
    {
        for(int j=0; j<i; j++)
        {
            if(nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j]+1);    // Extra +1 for current element(nums[i]) which is greater than nums[j] 
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

/* Using Binary Search: O(NlogN) */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> res;
        for(int i=0; i<nums.size(); i++)
        {
            auto it = lower_bound(res.begin(), res.end(), nums[i]);
            if(it==res.end())   // this means that nums[i] is greater than all the elements which are current present inside the res[]
                res.push_back(nums[i]);
            else
                *it = nums[i];  // otherwise if that's not the case, then just update the element to it's corrent position
        }
        return res.size();
    }
};