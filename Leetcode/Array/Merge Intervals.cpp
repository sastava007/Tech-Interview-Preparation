/* Using sorting: O(nlogn) complexity*/

class Solution {
public:
    
    static bool comp(const vector<int>& a, const vector<int>& b)
    {
        return a[0]<b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> merged;
        
        if(intervals.size() == 0)
            return merged;
        
        sort(intervals.begin(), intervals.end(), comp);
        
        merged.emplace_back(intervals[0]);
        
        for(int i = 1; i<intervals.size(); i++)
        {
            int n = merged.size();
            if(intervals[i][0]<=merged[n-1][1])     //if staring of current interval is smaller or equal than ending of our previous one, then it will be intersected 
                merged[n-1][1] = max(intervals[i][1], merged[n-1][1]);
            else
                merged.emplace_back(intervals[i]);
        }
        return merged;
    }
};

/* Follow Up:   How do you add intervals and merge them for a large stream of intervals, basically you don't have access to all the intervals in beginning and they keep on coming with time
                in form of the stream?
*/

Approach 1: We can use a priority queue here. As we have an incoming stream of intervals, we just need to keep them sorted and pop the smallest two intervals and check if we can merge them.
            to keep them sorted, use a min-heap() build on starting value of interval