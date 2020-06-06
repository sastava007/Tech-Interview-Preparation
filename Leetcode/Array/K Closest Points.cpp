/* 
    The other two possible approaches
    Sorting: O(nlogn)
    Max Heap: O(nlogK) to find Kth smallest element, and then add all the points which has distance <= this value

 */

/* Quickselect Algorithm: O(n) */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
    {
        vector<int> distance;
        vector<vector<int>> ans;
        
        if(points.size() ==0)
            return ans;
        if(K>points.size())
            return points;
        
        for(auto point: points)
        {
            int temp = point[0]*point[0]+point[1]*point[1];
            distance.emplace_back(temp);
        }
        
        int border = KthSamllest(distance, 0, distance.size()-1, K);
        
        for(auto point: points)
        {
            int temp = point[0]*point[0]+point[1]*point[1];
            if(temp <= border)
                ans.emplace_back(point);
        }
        return ans;
    }
    
    int partition(vector<int> &distance, int l, int r)
    {
        int pivot = distance[r];
        int j = l-1;
        for(int i=l; i<r; i++)
        {
            if(distance[i]<pivot)
            {
                j++;
                swap(distance[i], distance[j]);
            }
        }
        swap(distance[j+1], distance[r]);
        
        return (j+1);
    }
    
    int KthSamllest(vector<int> &dist, int l, int r, int k)
    {
        if(k>=0 && k<=r-l+1)
        {
            int index = partition(dist, l, r);
            if(index-l+1 == k)
                return dist[index];
            else if(index-l+1 > k)
                return KthSamllest(dist, l, index-1, k);
            else
                return KthSamllest(dist, index+1, r, k-(index-l+1));
        }
        return INT_MAX;
    }
};

int main()
{
    vector<vector<int>> points = {{3,3},{5, -1},{-2, 4}};
    Solution obj;

    vector<vector<int>> ans = obj.kClosest(points, 2);

    for(auto it: ans)
    {
        cout<<it[0]<<" "<<it[1]<<"\n";
    }

    return 0;
}