/* 
    We can easily see that for every no. in nums1, the best possible pair that yield the minimum sum is 0th element of nums2. And for a specific no. in nums1. the next candidate could be 
    (nums1.current_element + nums2.current_element_index+1).

    So idea is to use a minheap to keep track of the next minimum pair sum, and we only need to store the K pairs in heap.
    TC: O(klogK) and Space: O(K)

    Now, you might be thinking when we pop (i,j) pair from the heap why we only added (i,j+1) and not (i+1, j) becz we have already added (i+1, j) when we've initialized the heap, so
    we've already added all the reachable i and now we're just worried abot reaching the j.

*/

class Solution {

class compare       // custom comparator for min-heap
{
    public:
        bool operator()(pair<pair<int,int>, int> &a, pair<pair<int,int>, int> &b)
        {
            return a.first.first+a.first.second > b.first.first+b.first.second;
        }
};
    
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)       // this will return an array of (num1,num2) ans not the exact sum value
    {
        vector<vector<int>> result;
        int n = nums1.size(), m = nums2.size();  
        
        if(n == 0 || m == 0 || k==0)
            return result;
        
        priority_queue<pair<pair<int,int>, int>, vector<pair<pair<int,int>, int>>, compare> q; 
        
        for(int i=0; i<min(n,k); i++)   // add the mapping for first row elements with 0th element of second row
            q.push({{nums1[i], nums2[0]}, 0});
        
        while(!q.empty() && k-- >0)
        {
            auto temp = q.top();
            q.pop();
            
            result.push_back(vector<int>({temp.first.first, temp.first.second}));
            
            if(temp.second==m-1)    // if we're at the end of 2nd array, then we can't add any other element
                continue;
            
            q.push({{temp.first.first, nums2[temp.second+1]}, temp.second+1});
        }
        return result;
    }
};