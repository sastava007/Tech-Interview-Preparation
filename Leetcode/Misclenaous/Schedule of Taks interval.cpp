/* 
    You're given schedule of tasks in form of intervals, find out schedule in which you are:
        1. working(at least 1 task going) basically union
        2. working(at least 2 task going) basically intersection
    
    I/P: [1, 10], [2, 6], [9, 12], [14, 16], [16, 17]
    Union: [[1, 12], [14, 17]]
    Intersection: [[2, 6], [9, 10]]
*/

vector<interval> intersection(vector<interval> v)
{
    sort(v.begin(), v.end(), compare);
    vector<interval> ans;

    interval prev = v[0];
    for(int i=1; i<v.size(); i++)
    {
        interval curr = v[i];
        int low = max(curr.start, prev.start);
        int high = min(curr.end, prev.end);

        if(low<high)
        {
            int n = ans.size();
            if(!ans.empty() && ans[n-1].end == low)
                ans[n-1].end = high;
            else
                ans.push_back({low, high});

            prev = ({high, max(curr.end, prev.end});
        }
        else
        {
            prev = curr;
        }
    }
    return ans;
}