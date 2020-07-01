/* 
    The other two possible approaches
    Sorting: O(nlogn)
    Max Heap: O(nlogK) to find Kth smallest element, and then add all the points which has distance <= this value

    Note: Here we're guranteed that top K closest points will be unique
 */

/*  Quickselect Algorithm: O(N) in average and O(N^2) in worst case 
    For O(N), we need to have a median of median as the pivot element, which in the worst case can lead to O(N^2)

    Idea is to partially sort the subarray (points[i], points[i+1], ..., points[j]) so that the smallest K elements of this subarray occur in the first K positions (i, i+1, ..., i+K-1)
*/


/* Instead of returning the Kth smallest value, we can partially sort the array itself */

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
{
    vector<pair<int, int>> distance;
    vector<vector<int>> ans;
    
    if(points.size() ==0)
        return ans;
    if(K>points.size())
        return points;
    
    for(int i=0; i<points.size(); i++)
    {
        auto point = points[i];
        
        int temp = point[0]*point[0]+point[1]*point[1];
        distance.push_back({temp, i});
    }
    
    KthSamllest(distance, 0, distance.size()-1, K);     // this will basically partition the points, such that K closest points will come in front and from there we can directly pick
                                                       // first K elements
    
    for(int i=0; i<K; i++)
    {
        ans.push_back(points[distance[i].second]);
    }
    return ans;
}
int partition(vector<pair<int, int>>  &distance, int l, int r)
{
    int pivot = distance[r].first;
    int j = l-1;
    for(int i=l; i<r; i++)
    {
        if(distance[i].first<pivot)
        {
            j++;
            swap(distance[i], distance[j]);
        }
    }
    swap(distance[j+1], distance[r]);
    
    return (j+1);
}
void KthSamllest(vector<pair<int, int>> &dist, int l, int r, int k)
{
    if(k>=0 && k<=r-l+1)
    {
        int index = partition(dist, l, r);
        if(index-l+1 == k)
            return;
        else if(index-l+1 > k)
            KthSamllest(dist, l, index-1, k);
        else
            KthSamllest(dist, index+1, r, k-(index-l+1));
    }
}

/* Using a Max-Heap */

struct myComp
{
    bool operator()(vector<int>& p1, vector<int>& p2)
    {
        return (pow(p1[0], 2) + pow(p1[1], 2)) < (pow(p2[0], 2) + pow(p2[1], 2));   //custom comparator for max-heap
    }
};    
    
vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
{
    priority_queue<vector<int>, vector<vector<int>>, myComp> pq;
    for(auto& point: points)
    {
        pq.push(vector<int> {point[0], point[1]});
        
        if(pq.size() > K) pq.pop();
    }
    
    vector<vector<int>> res;
    while(!pq.empty())
    {
        res.push_back(pq.top());
        pq.pop();
    }
    
    return res;
}