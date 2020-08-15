/*
    So basically, idea is to maintain a monotonous queue that stores all the useful elements, a element is useful if it lies in current winodw and is is greater than all all elements on its left
    In this way, we end up with maximum element of each window at front of queue.

    TC: O(N) & Space: O(K)
*/

/* 
    Most sliding window questions uses this same template all the time. The only difference is the data structure used for the window.
    If the question asks about the unique element in window -> use set
    If the question asks about the frequency of element in window -> use map/ unordered_map
    If the question asks about window sum -> use prefix sum array
    If the question asks about min/max element -> use monotonous queue
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        if(k==1 || nums.empty())
            return nums;
        
        deque<int> q;
        vector<int> ans;
        int i;
        for(i=0;i<k;i++)
        {
            while((!q.empty()) && nums[q.back()]<=nums[i])
                q.pop_back();
            q.push_back(i);
        }

        for(;i<nums.size();i++)
        {
            ans.push_back(nums[q.front()]);

            while((!q.empty()) && q.front()<=i-k)      // remove elements outside of this window
                q.pop_front();
    
            while((!q.empty()) && nums[q.back()]<=nums[i])      // remove element which are not useful, i.e elements which are less than current element
                q.pop_back();

            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);
        return ans;
    }
};