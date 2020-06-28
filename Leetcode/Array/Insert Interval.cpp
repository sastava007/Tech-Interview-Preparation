/*  TC: O(N) and Space: O(N) 
    Input = [1,2],[3,5],[6,7],[8,10],[12,16] and insertInterval = [4,9]
    Output = [1,2],[3,10],[12,16]

    TC: O(N)
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
       vector<vector<int>> merged;
        int i=0, n = intervals.size();
        
        while(i<n && intervals[i][1] < newInterval[0])  //add all the intervals that are left of inserted interval i.e they do not intersect or overlap
            merged.push_back(intervals[i++]);
        
        while(i<n && intervals[i][0] <= newInterval[1])         //if they overlap, then merge them to newInterval
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            
            i++;
        }
        merged.push_back(newInterval);
                    
        while(i<n)       //add all the intervals, that are right of inserted interval
            merged.push_back(intervals[i++]);      
        return merged;
    }
};


/*  Using Binary Search: Idea is to find the rightmost interval with starting smaller than newInterval's starting, and find the leftmost interval with ending larger than that of newInterval's     ending 
    
    Intervals = [1, 2], [3, 5], [6, 7], [8, 10], [12, 16] and newInterval = [4, 9]
    rightmost interval with smaller starting point = [3, 5]
    leftmost interval with larger ending point = [8, 10]

    TC: O(N) in worst case, if we've to add an interval and delete all the interval from starting
    Intervals = [[2,3],[5,7],[9,11],[12,15]]  New Intervals = [1,16]

*/

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int n = intervals.size(), leftEnd, rightEnd, l, r;
        vector<Interval> res;

        for (l = 0, r = n - 1; l <= r; ) {
            int mid = l + ((r - l) >> 1);
            if (intervals[mid].start > newInterval.start)
                r = mid - 1;
            else l = mid + 1;
        } 
        leftEnd = r;

        for (l = 0, r = n - 1; l <= r; ) {
            int mid = l + ((r - l) >> 1);
            if (intervals[mid].end < newInterval.end)
                l = mid + 1;
            else r = mid - 1;
        }
        rightEnd = l;

        // Merge newInterval with intervals[leftEnd] and intervals[rightEnd] if necessary
        if (leftEnd >= 0 && intervals[leftEnd].end >= newInterval.start)
            newInterval.start = intervals[leftEnd--].start;

        if (rightEnd < n && intervals[rightEnd].start <= newInterval.end)
            newInterval.end = intervals[rightEnd++].end;

        // Save the intervals sequentially
        for (int i = 0; i <= leftEnd; i++)
            res.push_back(intervals[i]);
        res.push_back(newInterval);
        for (int i = rightEnd; i < n; i++)
            res.push_back(intervals[i]);
        return res;
    }
};