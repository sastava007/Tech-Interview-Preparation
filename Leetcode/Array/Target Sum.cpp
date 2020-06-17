/*  Given an array of no. place +/- sign among them to obatin target value. 
    
    Bruteforce: Use a recursive method to place +/- at every location and try if we can reach the target value using this method or not. TC: O(2^n)

    DP: Upon observation we can see that problem is nothing but dividing the array into subsets such that their diff is equal to target.
    sum(P) - sum(N) = target
    sum(P) + sum(N) = sum of array

    sum(P) = (sum(array) + target)/2
    So problem boild down to finding number of subset with given sum, and we can do this using menthod discussed in `Partition Equal Subset Sum`
    
    https://leetcode.com/problems/target-sum/discuss/97334/Java-(15-ms)-C%2B%2B-(3-ms)-O(ns)-iterative-DP-solution-using-subset-sum-with-explanation
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
        vector<int> dp(sum+1, 0);
        dp[0] = 1;
        
        for(int i=0; i<nums.size(); i++)        // TC: O(l*N) where N is range of sum possible and Space: O(N)
        {
            for(int j=sum; j>=nums[i]; j--)
                dp[j] += dp[j-nums[i]];
        }
        
        return dp[sum];
    }
};