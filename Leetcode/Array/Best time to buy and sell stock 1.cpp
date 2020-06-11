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

/*  Best to Buy & Sell Stock Prices 2: You can make as many transactions as you want. 
    Here we can buy and sell on consecutive day, i.e we can check if the price at current day is greater than  what it was yesterday then we can sell the stock today and still can get the maximum profit. This can be proved by Peak Value exaplaination [1,2,3,4,5,6] => 5 Buy & Sell on each consecutive day

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

/*  When we can make only 2/K transactions, then here we'll use DP becz there are lot of subprobelsm like what if I've made just 1 transaction or what if I have buy and sell on a prtiular day. 
    
    Assume we are in state S
    If we buy, we are spending money but we can also choose to do nothing
    Doing nothing means going from S->S
    Buying means going from some state X->S, losing some money in the process
    S = max(S, X-prices[i])

    Similarly, for selling a stock
    S = max(S, X+prices[i])

    https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/149383/Easy-DP-solution-using-state-machine-O(n)-time-complexity-O(1)-space-complexity
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.empty())
            return 0;
        
        int s1 = -prices[0], s2=INT_MIN, s3 = INT_MIN, s4 = INT_MIN;
        
        for(int i=1; i<prices.size(); i++)
        {
            s1 = max(s1, -prices[i]);
            s2 = max(s2, s1+prices[i]);
            s3 = max(s3, s2-prices[i]);
            s4 = max(s4, s3+prices[i]);
            
        }
        
        return max(0, s4);
    }
};


/* For K transaction */
private int maxProfit(int[] array, int t) 
{
    int[] stock = new int[t * 2];
    Arrays.fill(stock, Integer.MIN_VALUE);
    stock[0] = -array[0];
    for(int i = 1; i < array.length; ++i) 
    {
      stock[0] = Math.max(stock[0], -array[i]);
      for (int j = 1; j < 2 * t; j += 2) 
      {
        stock[j] = Math.max(stock[j], stock[j - 1] + array[i]);
        if (j + 1 < 2 * t) 
        {
          stock[j + 1] = Math.max(stock[j + 1], stock[j] - array[i]);
        }
      }
    }
    return Math.max(0, stock[2 * t - 1]);
  }




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