/* 
    leastPerfectSquare[i] = the least number of perfect square numbers which sum to i. Note that leastPerfectSquare[0] is 0.
    For each no. "i" it can be represented as a sum of some perfect square number + some remaining number
    
    leastPerfectSquare[i] = min(leastPerfectSquare[i], leastPerfectSquare[i-j*j]+1)
    We're adding +1 for the current perfect square number 'j*j'
*/

class Solution {
public:
    int numSquares(int n) {
        
        vector<int> leastPerfectSquare(n+1, INT_MAX);
        leastPerfectSquare[0] = 0;
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j*j<=i; j++)
            {
                leastPerfectSquare[i] = min(leastPerfectSquare[i], leastPerfectSquare[i-j*j]+1);
            }
        }
        return leastPerfectSquare[n];
    }
};