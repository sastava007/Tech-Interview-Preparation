/* 
    We begin at state 0, where we can either rest (i.e. do nothing) or buy stock at a given price.

    If we choose to rest, we remain in state 0
    If we buy, we spend some money (price of the stock on that day) and go to state 1
    From state 1, we can once again choose to do nothing or we can sell our stock.

    If we choose to rest, we remain in state 1
    If we sell, we earn some money (price of the stock on that day) and go to state 2
    This completes one transaction for us. Remember, we can only do atmost 2 transactions.

    From state 2, we can choose to do nothing or buy more stock.

    If we choose to rest, we remain in state 2
    If we buy, we go to state 3
    From state 3, we can once again choose to do nothing or we can sell our stock for the last time.

    If we choose to rest, we remain in state 3
    If we sell, we have utilized our allowed transactions and reach the final state 4

    To reach s1, we either stay in s1 or we buy stock for the first time.
    To reach s2, we either stay in s2 or we sell from s1 and come to s2
    Similarly for s3 and s4.

    DP Eq: s2[i] = max(s2[i-1], s1[i-1]+prices[i])

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
    int[] stock = new int[t * 2];       //check here if NULL then only proceed
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