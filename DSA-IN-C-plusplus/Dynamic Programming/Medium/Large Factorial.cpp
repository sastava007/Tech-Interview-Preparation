//User function template for C++


class Solution{
public:
    long long fact(long long n, vector<long long>&dp){
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = (n*fact(n-1, dp))%1000000007; 
    }
    vector<long long> factorial(vector<long long> a, int n) {
        vector<long long> dp(1000009, -1);
        dp[0]=dp[1] = 1;
        long long m = fact(100009, dp);
        vector<long long> v(a.size());
        for(int i = 0; i<a.size(); i++){
          v[i] = dp[a[i]];
        }
        
        return v;
        
        
    }
};
