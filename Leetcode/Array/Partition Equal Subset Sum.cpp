/*  This is 0/1 knapsack problem for each no. we can pick it or not. dp[i][j] represents whether its possible to get sum j from the set of first i numbers. 
    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]

    This is different from Split Array with equal sum, where we have to find a point around which we can just split both the arrays.
 */

public boolean canPartition(int[] nums) 
{
    int sum = 0;    
    for (int num : nums) {
        sum += num;
    }
    
    if ((sum & 1) == 1) {
        return false;
    }
    sum /= 2;

    int n = nums.length;
    boolean[][] dp = new boolean[n+1][sum+1];
    for (int i = 0; i < dp.length; i++) {
        Arrays.fill(dp[i], false);
    }
    
    dp[0][0] = true;    // coz it is possible to get sum 0, with first 0 elements
    
    for (int i = 1; i < n+1; i++) {
        dp[i][0] = true;    // it's also possible to get sum 0 with first i characters, if we don't pick any character
    }
    for (int j = 1; j < sum+1; j++) {   //not possible to obtain sum 'j' without picking any character
        dp[0][j] = false;
    }
    
    for (int i = 1; i < n+1; i++) 
    for (int j = 1; j < sum+1; j++) 
    {
        dp[i][j] = dp[i-1][j];  // if we don't pick nums[i] character
        if (j >= nums[i-1]) 
        {
            dp[i][j] = (dp[i][j] || dp[i-1][j-nums[i-1]]);      //if we pick nums[i]
        }
    }
    
    return dp[n][sum];
}

/*  1D DP: Bottom Up(tabulation)  
    TC: O(N*S)
    Space: O(S)
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(sum&1)           //not possible to divide sum into 2 equal parts, if they are odd
            return false;
        
        sum /= 2;
        
        vector<bool> dp(sum+1, false);
        dp[0] = true;
        
        for(int i=0; i<nums.size(); i++)
        {
            for(int j =sum; j>=nums[i]; j--)
                dp[j] = dp[j] || dp[j-nums[i]];
        }
        
        return dp[sum];
    }
};