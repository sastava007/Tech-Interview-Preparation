/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) 
    {
        multimap<int, char> order;
        for(auto it: intervals)
        {
            order.insert({it.start, 's'});
            order.insert({it.end, 'e'});
        }
        
        int maxRooms=0, rooms=0;
        
        for(auto it: order)
        {
            if(it.second=='s')
                rooms++;
            else
                rooms--;
            maxRooms=max(maxRooms, rooms);
        }
        
        return maxRooms;
    }
};