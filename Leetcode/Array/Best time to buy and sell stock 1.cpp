/* 
    V1: We can just buy & sell 1 stock i.e(1 transaction).
    If current price is less than minimum stock price so far, then update the minimum stock price and check for profit 
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.size() == 0)
            return 0;
        
        int n = prices.size();
        int minStockPrice=prices[0], maxProfit=0;
        
        for(int i = 1; i<n; i++)
        {
            if(prices[i]<minStockPrice)
                minStockPrice = prices[i];
            else if(prices[i]-minStockPrice > maxProfit)
                maxProfit = prices[i]-minStockPrice;
        }
    
        return maxProfit;
    }
};

/*  Best to Buy & Sell Stock Prices 2: You can make as many transactions(Buy & Sell) as you want. 

    So here we can buy and sell on consecutive day, i.e we can check if the price at current day is greater than  what it was yesterday then we can sell the stock today and still can get the maximum profit. This can be proved by Peak Valley exaplaination [1,2,3,4,5,6] => 5 Buy & Sell on each consecutive day.

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit = 0;
        for(int i=1; i<prices.size(); i++)
        {
            if(prices[i]>prices[i-1])
                profit += prices[i]-prices[i-1];
        }
        
        return profit;
    }
};