/*  Kth Largest using QuickSelect

    The algorithm is similar to QuickSort. The difference is, instead of recurring for both sides (after finding pivot), it recurs only for the part that contains the K-th smallest element. The logic is simple, if index of partitioned element is more than k, then we recur for left part. If index is same as k, we have found the k-th smallest element and we return. If index is less than k, then we recur for right part.

    TC: O(N)
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        return KthLargest(nums, 0, nums.size()-1, k);
    }
private:
    
    int partition(vector<int> &nums, int s, int e)
    {
        int j = s-1;
        int pivot = nums[e];
        
        for(int i =s;i<e; i++)
        {
            if(nums[i]>pivot)
            {
                j++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[e], nums[j+1]);
        
        return j+1;
    }
    
    int KthLargest(vector<int> &nums, int s, int e, int k)
    {
        if(k>0 && k<=e-s+1)
        {
            int index = partition(nums, s, e);
            
            if(index - s +1 ==k)
                return nums[index];
            
            else if(index - s +1 > k)
            {
                return KthLargest(nums, s, index-1, k);
            }
            
            else
            {
                return KthLargest(nums, index+1, e, k-(index-s+1));
            }
        }
        return INT_MIN;
    }
};

/*  Using Min-Heap 
    TC: O(NlogK)
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
     
        priority_queue<int, vector<int>, greater<int>> p;
        for(auto it: nums)
        {
            p.push(it);
            
            if(p.size()>k)
                p.pop();
        }
        return p.top();
    }
};