/* 
    GIven a list of timings in 24hr format, find the minimum minutes difference b/w any two times. 
    Valid time: 00:00 to 23:59

    Idea: Here we can use to concept that total time in minutes is limited to just 24*40 = 1440 min, becz there will be atmax 24 hrs in a day. So we can map the time to its
    minute value and then sort the timings. The required min difference must be a difference between two adj. elements in the circular array (so the last element is "adjacent" to the first)
    We take the minimum value of all of them.

    TC: O(NlogN) in general, but we can see here that when N>1440 then we go atmost 1440 instructions which can be considered as constant
*/

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) 
    {
        vector<int> times;
        for(string time: timePoints)
        {
            times.push_back(stoi(time.substr(0,2))*60 + stoi(time.substr(3)));
            if(times.size() > 1440)     // COnsider pigeonhole priniciple, i.e total no. of buckets that we can have in this problem is 1440 so if there are more than 1440 time
                                        // then it means that we've repeated entries which led to minimum diff b/w them as 0.
                return 0;
        }
        sort(times.begin(), times.end());
        times.push_back(1440 + times[0]);   // To consider the circular case
        
        int ans = INT_MAX;
        
        for(int i=1; i<times.size(); i++)
        {
            ans = min(ans, times[i]-times[i-1]);    
        }
        return ans;
    }
};