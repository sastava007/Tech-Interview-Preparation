/* 
    We can reach the current position in 1 step by
       - come from left cell
       - come from right cell
       - stay in this cell
    The total number of ways is the sum of these 3 ways for the previous step
    
    Here idea is to use a DP based approach, and we also need to do prunning for faster compution. So if we just closesly observe then if i -> represents current position
    and steps the remaining steps then if i>steps then it's not possible to reach back to 0th step.

    This means we can't go more than steps/2 ahead of origin, as we've to return back also
*/

// We start with just 1 known way (to be in cell 0) and then step by step build up the knowledge.

class Solution {
public:
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, 1+steps/2); // if we're at pos 'i' then we can't go more than step/2 otherwise we can't return
        vector<vector<int>> dp(steps+1,vector<int>(arrLen,0));
        dp[0][0]=1;
        for(int s=1; s<steps+1; s++) 
        {
            int depth = min(arrLen, steps-s+1); // to have time for the way back
            for(int pos=0; pos<depth; pos++) {
                int res = dp[s-1][pos] + (pos>0?dp[s-1][pos-1]:0);
                res+= pos<arrLen-1?dp[s-1][pos+1]:0;
                dp[s][pos] = res;
            }
        }
        return dp[steps][0];
	}
};

// On each step we need knowledge only about the previous step, so we can keep just the previous step

class Solution {
public:
    int numWays(int steps, int arrLen)
    {
        arrLen = min(arrLen, 1+steps/2);
        vector<int> dp(arrLen,0), prev(arrLen,0);   // to store info abot previous step
        prev[0]=1;
        for(int s=1; s<steps+1; s++)
        {
            int depth = min(arrLen, steps-s+1);     // if (i>steps) as we can never reach 0 in that case
            for(int pos=0; pos<depth; pos++)
            {
                int res = prev[pos] + (pos>0?prev[pos-1]:0);
                res+= pos<arrLen-1?prev[pos+1]:0;
                dp[pos] = res;
            }
            swap(dp,prev);
        }
        return prev[0];
    }
};