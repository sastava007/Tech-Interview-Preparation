//  Minimum Cost For Tickets

// Problem Statement

// In a country popular for train travel, you have planned some train travelling one year in advance.  The days of the year that you will travel is given as an array days.  Each day is an integer from 1 to 365.

// Train tickets are sold in 3 different ways:

// a 1-day pass is sold for costs[0] dollars;
// a 7-day pass is sold for costs[1] dollars;
// a 30-day pass is sold for costs[2] dollars.
// The passes allow that many days of consecutive travel.  For example, if we get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.

// Return the minimum number of dollars you need to travel every day in the given list of days.

// Approach:
// If a person travels on a particular day, we take the min cost out of the cost of travelling on the previous day, the cost of travelling 7 days before (7 day pass), or the cost of travelling 30 days before (30 day pass).
// Else, we simply use the cost of the previous day.

int mincostTickets(vector<int>& days, vector<int>& costs) {
    
    vector<int> dp(366, 0);
    int k=0;

    for(int i=1; i<=365; i++) {
        
        int d7=0, d30=0;
        
        if((i-7) >= 0) 
            d7=i-7;
        if((i-30) >= 0) 
            d30=i-30;

        if(k<days.size() && i==days[k]) {
            dp[i]=min(dp[i-1]+costs[0], min(dp[d7]+costs[1], dp[d30]+costs[2]));
            k++;
        } else {
            dp[i]=dp[i-1];
        }
    }
    
    return dp[365];

}
