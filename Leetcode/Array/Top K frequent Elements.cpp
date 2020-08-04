/*  It's guaranteed that the answer is unique, in other words the set of the top K frequent elements is unique.
    Which means [2,2,3,3,4] and K = 1 is invalid test case

    TC: O(KlogN), deal the case seperately when K = N in O(N)
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> counts;
        priority_queue<int, vector<int>, greater<int>> max_k;   //min-heap
        for(auto i : nums) 
            ++counts[i];
        for(auto & i : counts) 
        {
            max_k.push(i.second);
            // Size of the min heap is maintained at equal to or below k
            while(max_k.size() > k) 
                max_k.pop();
        }

        vector<int> res;
        for(auto & i : counts) 
        {
            if(i.second >= max_k.top())
                res.push_back(i.first);
        }
        return res;
    }
};

/*  Using QuickSelect: 
    TC: O(N) average and O(N^2) worst time 
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