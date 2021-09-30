/*

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.


*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int nn = prices.size();
        vector<int>dp(nn , 0);
        dp[0] = 0;
        for(int i = 1 ; i < prices.size() ; i++)
        {
            dp[i] = max(prices[i] - prices[i - 1] + dp[i - 1] , dp[i]);
        }
        
        return *max_element(dp.begin() , dp.end());
    }
};
