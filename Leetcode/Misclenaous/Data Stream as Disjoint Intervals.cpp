/* TC: for addNUM O(logN) and that for getIntervals O(N) as we have to explicitly copy from map to resultant vector */

class SummaryRanges {
public:
    SummaryRanges() {

    }
    void addNum(int val) 
    {
        if(m.find(val) != m.end())
            return;
        
        int l = lower(val);     //  no. smaller than val
        int r = upper(val);     //  no. greater than val
        
        if(l!=-1 && r!=-1 && m[l].second+1==val && r==val+1)    // if (l.second, val, r) all are consecutive then update the ending interval
        {
            m[l].second = m[r].second;
            m.erase(r);
        }
        else if(l!=-1 && m[l].second+1>=val)    // if val is bounded by our closing interval, then update it with maximum of both
        {
            m[l].second = max(m[l].second, val);   
        }
        else if(r!=-1 && r==val+1)      // this means start a new interval from (val, ending interval of right)
        {
            m[val] = {val, m[r].second};
            m.erase(r);
        }
        else        // if disjoint
        {
            m[val] = {val, val};
        }
    }
    
    vector<vector<int>> getIntervals() 
    {
        vector<vector<int>> result;
        for(auto &it: m)
            result.push_back(vector<int>({it.second.first, it.second.second}));
        return result;
    }
private:
    map<int, pair<int, int>> m;
    
    int lower(int val)
    {
        auto it = m.lower_bound(val);
        if(it == m.begin())
            return -1;
        return (--it)->first;
    }
    int upper(int val)
    {
        auto it = m.upper_bound(val);
        if(it == m.end())
            return -1;   
        return it->first;
    }
};