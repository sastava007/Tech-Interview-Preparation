/* Return whether a person would be able to attend all the meetings or not */

/**
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
   
   static bool comp(const Interval &a, const Interval &b)
   {
       return a.start<b.start;
   }
   
    bool canAttendMeetings(vector<Interval> &intervals) 
    {
        sort(intervals.begin(), intervals.end(), comp);
        
        for(int i=0; i<(int)intervals.size()-1; i++)
        {
            if(intervals[i+1].start < intervals[i].end) //here we are assuming that when start==end, then also he can attend the meeting, which sounds weird though, so confirm with your interviewer
                return false;
        }
        
        return true;
    }
};