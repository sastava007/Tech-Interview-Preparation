
class Solution
{
    int mod = 1e9+7;
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        // your code here
        vector<long long> dp(n+1, 0);
        
        dp[n] = 1;
        int x[] = {1, 2, 3};
        
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<3; j++){
                if(i+x[j] <= n){
                    dp[i] = (dp[i] % mod + (dp[i+x[j]] % mod)) % mod;
                    
                }
            }
        }
        
        return dp[0];
        
        
    }
};

// Solution 2


class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        // your code here
        int mod = 1e9+7;
        vector<long long> dp(n+1, 0);
        
        dp[1] = 1;
        
        if(n>=2) dp[2] = 2;
        
        if(n>=3) dp[3] = 4;
        
        for(int i=4; i<=n; i++){
            dp[i] = (dp[i-1] % mod + dp[i-2]%mod + dp[i-3]%mod)%mod;
        }
        
        return dp[n]%mod;
        
    }
};
