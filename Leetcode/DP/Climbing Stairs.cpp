/* 
    You're given N steps in a stair case, and each time either you can move either 1 or 2 steps at a time.
    dp[i] = dp[i-1] + dp[i-2]
    I've optimized the space without using array.
    
*/

class Solution {
public:
    int climbStairs(int n) 
    {
        if(n<2)
            return 1;
        
        int prev1 = 1, prev2 = 1, curr;
        for(int i=2; i<=n; i++)
        {
            curr = prev2 + prev1;
            prev1 = prev2;
            prev2 = curr;
        }
        return curr;
    }
};