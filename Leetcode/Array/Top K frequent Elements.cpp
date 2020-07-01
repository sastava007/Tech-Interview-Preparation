/*  It's guaranteed that the answer is unique, in other words the set of the top K frequent elements is unique.
    Which means [2,2,3,3,4] and K = 1 is invalid test case
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
                ees.push_back(i.first);
        }
        return res;
    }
};