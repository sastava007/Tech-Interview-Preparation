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
            if(intervals[i][0]<=merged[n-1][1])
                merged[n-1][1] = max(intervals[i][1], merged[n-1][1]);
            else
                merged.emplace_back(intervals[i]);
        }
        
        return merged;
    }
};