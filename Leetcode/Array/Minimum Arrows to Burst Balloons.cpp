/*  Idea - so basically we need to find the minimum number of such unique points upon hiting at which we burst the balloon.

    Intution: Can be derived similar to finding number of non overlapping intervals, becz then only we need to fire a new arrow for each new interval, 
    as the overlapping one's will be covered in a single shot.
    
    1. Sort balloons in increasing order of the start position.
    2. Scan the sorted pairs, and maintain a pointer for the minimum end position for current "active balloons", whose diameters are overlapping.
    3. 

    https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/discuss/93735/A-Concise-Template-for-%22Overlapping-Interval-Problem%22
 */

class Solution {

static bool comp(const vector<int>&a, const vector<int>&b)
{
    return a[0]<b[0];
}
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        sort(points.begin(), points.end(), comp);
        int minEnd = INT_MAX;

        int arrows = 0;
        
        for(auto &point: points)
        {
            if(point[0]>minEnd)     // when non overlapping interval is found, then increment the arrow counter
            {
                arrows++;
                minEnd = point[1];
            }
            else
                minEnd = min(minEnd, point[1]);
        }
        
        return arrows + !points.empty();
        
    }
};