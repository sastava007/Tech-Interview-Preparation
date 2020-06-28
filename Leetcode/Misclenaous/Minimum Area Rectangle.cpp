/* 
    Idea:   is to use a hash-map to collect all the y coordinates for each x coordinate in a sorted order
            Then pick pair of X coordniates, and find the intersection b/w their list of y coordinates, becz a rectangle will be formed only with the help of points which align
            for both pair of x coordinates.

            After finding their intersection, find the area by using the formula area = abs(x[i]-x[j]) * (y_cord[k]-y_cord[k-1]) 
            Since y coords are sorted, you only need to calculate the area for the y[k] - y[k - 1] pairs.

            TC: O(N^2) and Space: O(N)   here N is the total number of points

            It's O(n ^ 2) becz fisrt of all (i & j) loops are running over x coordinates and not total points. Also the total number of steps in the second loop and set intersection is n. 
            Let's say: When all points have a different x, set will include only one element (n * n * 1). If we have 2 points per x, it is n/2 * n/2 * 2 and so on.

 */

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) 
    {
        int area = INT_MAX;
        
        unordered_map<int, set<int>> m;
        for(auto &i: points)
            m[i[0]].insert(i[1]);
        
        for(auto i=m.begin(); i!=m.end(); i++)
        {
            for(auto j=next(i); j!=m.end(); j++)
            {
                if(i->second.size()<2 || j->second.size()<2)
                    continue;
                
                vector<int> y_cord;
                set_intersection(i->second.begin(), i->second.end(), j->second.begin(), j->second.end(), back_inserter(y_cord));
                
                for(int k=1; k<y_cord.size(); k++)
                    area = min(area, abs(i->first - j->first)*(y_cord[k] - y_cord[k-1]));
            }
        }
        return (area == INT_MAX?0:area);
    }
};

/*  Using Diagonal: O(N^2) and O(N) TLE'd

    Consider each pair of coordinates as ends of potential diagonal, then check if we can find other set of diagonal also, this can be done by considering (x1, y1) and (x2, y2) as first diagonal then (x1, y2) and (x2, y1) should also be present.
*/
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) 
    {
        set<pair<int, int> > pts;
        for(vector<int> p : points)
        {
            pts.insert({p[0], p[1]});
        }
        int area = INT_MAX;
        for(auto p : pts)
        {
            for(auto q : pts)
            {
                if(p.first == q.first || p.second == q.second) continue;
                if(pts.count({p.first, q.second}) && pts.count({q.first, p.second})){
                    area = min(area, abs((p.first - q.first) * (p.second - q.second)));
                }
            }
        }
        return (area == INT_MAX?0:area);
    }
};