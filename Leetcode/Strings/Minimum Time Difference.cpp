/* 
    GIven a list of timings in 24hr format, find the minimum minutes difference b/w any two times. 
    Valid time: 00:00 to 23:59

    Idea: Here we can use to concept that total time in minutes is limited to just 24*40 = 1440 min, becz there will be atmax 24 hrs in a day. So we can map the time to its
    minute value and then sort the timings. After which we start iterating  

    TC: O(N), but we're iterating till 1440 even when array is let's say small, to which we can optimize if we iterate from [first - last]
*/


int findMinDifference(vector<string>& timePoints) 
{
    vector<int> time(1440, 0);
    for(string s: timePoints)
    {
        int hr = stoi(s.substr(0, 2));
        int min = stoi(s.substr(3));
        
        min += 60*hr;
        if(time[min])   // if a particular bucket is already filled which means that a timestamp is repeated and hence min time is 0
            return 0;
        time[min] = 1;
    }
    
    int prev = -1, minTime = 1440, first = INT_MAX, last = INT_MIN;
    
    for(int i=0; i<1440; i++)
    {
        if(time[i])
        {
            if(prev!=-1)
                minTime = min(minTime, i-prev);
            
            prev = i;
            first = min(first, i);  // we're maintaining the leftmost & rightmost point becz it only calculates (i-prev) during the above loop
            last = max(last, i);   // At last, we need to take care the last and first time points. i.e. [00:00, 10:00, 23:00]. The smallest gap is between 23:00 and 00:00.
        }
    }
    return min(minTime, 1440-(last-first)); // one thing to consider is that if ["00:00", "10:00"] then we'll be considering time b/w mid night 12 and morning 10 => 10 hrs,
                                            // and not just night 12, and night 10 just to minimize the difference 
}

/* TC: O(NlogN) */
int findMinDifference(vector<string>& timePoints) 
{
    vector<int> times;
    for(string time: timePoints)
    {
        times.push_back(stoi(time.substr(0,2))*60 + stoi(time.substr(3)));
        if(times.size() > 1440)   // according to piegon hole priciple, if there are more than 1 piegon in a hole which means duplicate values are present
            return 0;
    }
    
    sort(times.begin(), times.end());
    times.push_back(1440 + times[0]);
    
    int ans = INT_MAX;
    
    for(int i=1; i<times.size(); i++)
    {
        ans = min(ans, times[i]-times[i-1]);    
    }
    
    return ans;
    
}