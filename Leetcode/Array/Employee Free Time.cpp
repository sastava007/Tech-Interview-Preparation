/*  Similar to Merge Intervals problem, just there we were supposed to find the intersection/operlapping region. Wheras here we have to find the unconnected interval between the merged intervals.
    TC: O(NlogN) and Space: O(N)

    Input = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]  Output = [[5,6],[7,9]]

 */

/* class Interval 
{
     int start;
     int end;
     Interval() { start = 0; end = 0; }
     Interval(int s, int e) { start = s; end = e; }
}; */

bool compare(Interval &a, Interval &b)
{
    return a.start<b.start;
}

class Solution
{
    public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> &schedules)
    {
        vector<Interval> tasks, freeTime;
        if(schedules.size()==0)
            return freeTime;

        for(Interval &schedule: schedules)
            tasks.insert(tasks.end(), schedule.begin(), schedule.end());
        
        sort(tasks.begin(), tasks.end(), compare);

        Interval prev = tasks[0];
        for(int i=1; i<tasks.size(); i++)
        {
            if(tasks[i].start > prev.end)
            {
                freeTime.push_back(Interval(prev.end, tasks[i].start));
                prev = tasks[i];
            }
            else if(tasks[i].end > prev.end)
            {
                prev = tasks[i];
            }
        }
        return freeTime;
    }
};