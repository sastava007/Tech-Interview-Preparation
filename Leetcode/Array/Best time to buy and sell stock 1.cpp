class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.size() == 0)
            return 0;
        
        int n = prices.size();
        
        vector<int> suffix(n);
        suffix[n-1] = prices[n-1];
        for(int i = n-2; i>=0; i--)
        {
            suffix[i] = max(prices[i], suffix[i+1]);
        }
        
        int ans = 0;
        for(int i=0; i<n; i++)
            ans = max(ans, suffix[i]-prices[i]);
        
        return ans;
    }
};