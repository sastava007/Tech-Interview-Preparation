/*  We've to find the no. of intervals that we should remove such that all remaining intervals are non-overlapping. We can do this by first finding the count of non-overalapping and
    then subtracting them from total number of intervals.

    https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/discuss/93735/A-Concise-Template-for-%22Overlapping-Interval-Problem%22
    
 */

class Solution {
    
static bool comp(const vector<int>&a, const vector<int>&b)
{
    return a[0]<b[0];
}
    
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        if(intervals.size()==0)
            return 0;
        
        sort(intervals.begin(), intervals.end(), comp);
        int minEnd = INT_MAX;

        int count = 0;
        
        for(auto &interval: intervals)
        {
            if(interval[0]>=minEnd)
            {
                count++;
                minEnd = interval[1];
            }
            else
            {
                minEnd = min(minEnd, interval[1]);
            }
        }
        
        return (intervals.size()-(count+1));
    }
};