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

/* 
    Given a staircase, where ith step has cost[i]. Once you pay the cost, you can either climb 1 or 2 steps. You need to find minimum cost to reach the top of the floor,
    and you can either start from the step with index 0, or the step with index 1.

    dp[i] = min(dp[i-1], dp[i-2]) + i==n?0:cost[i]  Becz when we're at nth step, then we don't need to pay any cost as we've already reached the destination

*/
int minCostClimbingStairs(vector<int>& cost) 
{
    int n = cost.size();
    int pre1 = cost[0], pre2 = cost[1], currCost;
    
    for(int i=2; i<=n; i++)
    {
        currCost = min(pre1, pre2) + (i==n?0:cost[i]);
        
        pre1 = pre2;
        pre2 = currCost;
    }
    return currCost;
}