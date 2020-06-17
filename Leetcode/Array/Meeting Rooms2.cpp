/* The idea is to store start and end times in an auxiliary array with an additional marker to indicate whether the time is starting or ending. Now sort the array. Process the sorted array, for every starting increment rooms. And for every ending, decrement. Keep track of maximum active rooms 

    TC: O(nlogn) and Space: O(N)
*/

class Solution {
public:
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

/* Using Priority Queue TC: O(NlogN) and Space: O(N) in worst case, where N is the number of intervals */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.size() == 0) {
            return 0;
        }
        
        sort(intervals.begin(), intervals.end(), [](const Interval& i1, const Interval& i2) -> bool {       // lmbda function sorts based on starting time of 2 intervals 
            return i1.start < i2.start;
        });
        
        priority_queue<int, vector<int>, greater<int>> heap;        // minheap
        int rooms = 0;
        heap.push(intervals[0].end);
        rooms++;
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < heap.top()) {
                rooms++;
            } else {
                heap.pop();
            }
            heap.push(intervals[i].end);
        }
        
        return rooms;   // or heap.size()
    }
};

/*  */
class Solution {
  public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int num[1001000];
    int minMeetingRooms(vector<Interval> &intervals) {
        // Write your code here
        int mx = 0;
        for(int i = 0; i <= 1000000; i++) {
            num[i] = 0;
        }
        for(int i = 0; i < intervals.size(); i++) {
            num[intervals[i].start] += 1;
            num[intervals[i].end] -= 1;
            mx = max(mx, intervals[i].end);
        }
        int ans = 0;
        for(int i = 0; i <= mx; i++) {
            if(i != 0) {
                num[i] += num[i - 1];
            }
            ans = max(ans, num[i]);
        }
        return ans;

    }
};