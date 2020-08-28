/* 
    Find the minimum no. of coins required to get that amount. It is similar to Perfect Squares problem.
    
    Input: coins = [1, 2, 5], amount = 11
    Output: 3 
    Explanation: 11 = 5 + 5 + 1
*/

int coinChange(vector<int>& coins, int amount) 
{
    int n = coins.size();
    vector<int> leastNoCoins(amount+1, amount+1);
    leastNoCoins[0] = 0;
    
    sort(coins.begin(), coins.end());   // Not necessary, but doing for pruning
    
    for(int i=1; i<=amount; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(coins[j] <= i)
                leastNoCoins[i] = min(leastNoCoins[i], leastNoCoins[i-coins[j]]+1);
            else break;     // Pruning, becz if coins[j] is not less than amount_i then further coins has no chance becz they are greater than current one
        }
    }
    
    if(leastNoCoins[amount] > amount)
        return -1;
    
    return leastNoCoins[amount];
}