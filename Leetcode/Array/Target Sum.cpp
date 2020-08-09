/*  Given an array of non-negative number. place +/- sign among them to obatin target value. 
    
    Bruteforce: Use a recursive method to place +/- at every location and try if we can reach the target value using this method or not. TC: O(2^n)

    DP: Upon observation we can see that problem is nothing but dividing the array into subsets such that their diff is equal to target.
    sum(P) - sum(N) = target
    sum(P) + sum(N) = sum of array
    sum(P) = (sum(array) + target)/2
    So problem boils down to finding number of subset with given sum, and we can do this using method discussed in `Partition Equal Subset Sum`

    dp[nums.length][s + 1] where, dp[i][j] means number of ways to get sum j with first i elements
    dp[i][j] = dp[i-1][j] + dp[i][j-nums[i]], we can get the sum j either by just repeating all the ways to get sum j by using first (i-1) elements, or add nums[i] on top of each way to get sum j-nums[i] using first i elements

    Above transition always involve two consecutive rows in the 2-d array, so you apply the classic state compression technique for dp and reduce it to dp[j] = dp[j] + dp[j - nums[i]] which equals to dp[j] += dp[j - nums[i]]
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(target>sum || (target+sum)&1)    // if target reqired is greater than total array sum then it's not at all possible OR if (target+sum) is odd then it' not possible it to divide it by 2
            return 0;
        
        return subsetSum(nums, (target+sum)/2);
    }
private:
    int subsetSum(vector<int> &nums, int sum)
    {   
        vector<int> dp(sum+1, 0);   // dp[i] stores the no. of ways to get the sum 'i'
        dp[0] = 1;
        
        for(int i=0; i<nums.size(); i++)        // TC: O(l*N) where N is range of sum possible and Space: O(N)
        {
            for(int j=sum; j>=nums[i]; j--)
                dp[j] += dp[j-nums[i]];
        }
        
        return dp[sum];
    }
};