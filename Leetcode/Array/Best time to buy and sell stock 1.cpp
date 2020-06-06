/* If current price is less than minimum stock price so far, then update the minimum stock price and check for profit */
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

/* Keep on iterating from back, and maintain the maximumStockPrice so far, similarly we can start from first and maintain minimum stock price */

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.size() == 0)
            return 0;
        
        int n = prices.size();
        int maxStockPrice=prices[n-1], maxProfit=0;
        
        for(int i = n-2; i>=0; i--)
        {
            maxStockPrice = max(maxStockPrice, prices[i]);
            
            maxProfit = max(maxProfit, maxStockPrice-prices[i]);
        }
    
        return maxProfit;
    }
};