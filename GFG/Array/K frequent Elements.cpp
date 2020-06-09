/*  One way is to map the frq of elements and then find the K most frquent elements using a min_heap this requires a TC of O(NlogK) 
    But we can do something better than this, by finding the frquency of Kth most occuring element using a quick_select() algorithm which runs in O(N) average and O(N2) worst case
    
    So total TC: O(N) and O(N) space 

*/

class Solution {
    
private:
    unordered_map<int, int> m;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        for(int &i: nums)
            m[i]++;
        
        vector<int> frq, ans;
        
        for(auto &it: m)
            frq.emplace_back(it.second);
        
        int threshold = topKFrequent(frq, 0, frq.size()-1, k);
        
        for(auto &it: m)
        {
            if(it.second>=threshold)
                ans.emplace_back(it.first);
        }
        
        return ans;
    }
    
private:
    int partition(vector<int> &v, int l, int r)
    {
        int j=l-1;
        int pivot = v[r];
        for(int i=l; i<r; i++)
        {
            if(v[i]>pivot)
            {
                j++;
                swap(v[i], v[j]);
            }
        }
        swap(v[r], v[j+1]);
        
        return (j+1);
    }
    
    int topKFrequent(vector<int> &v, int l, int r, int k)
    {
        if(k>=0 && k<=r-l+1)
        {
            int index = partition(v, l, r);
            if(index-l+1==k)
                return v[index];
            if(index-l+1>k)
                return topKFrequent(v, l, index-1, k);
            else
                return topKFrequent(v, index+1, r, k-(index-l+1));
        }
        
        return INT_MIN;
    }
};