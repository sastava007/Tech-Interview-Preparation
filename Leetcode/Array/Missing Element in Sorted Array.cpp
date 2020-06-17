/*  
    Note: No. of missing elements in a range can be calculated by (nums[nums.size()-1]-nums[0]+1)-nums.size() 
    i.e total range of elements - length of range

    https://strstr.io/Leetcode1060-Missing-Element-in-Sorted-Array/
*/

class Solution {
public:
    int missingElement(vector<int>& nums, int k) 
    {
        // assume nums is not empty
        int left = 0;
        int right = nums.size()-1;
        int count = missingCount(nums, right);
        
        if(k > count) {
            return nums[right] + k - count;     //(k-count) is the number of remaining missing element outside this range
        }
        
        while(left < right) //lower bound on missingCount
        {                     
            int mid = left + (right - left) /2 ;
            count = missingCount(nums, mid);
            if(count >= k){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left-1] + k - missingCount(nums, left-1);
    }
    
    int missingCount(vector<int>& nums, int idx)
    {
        return (nums[idx] - nums[0] - idx);     //here we'are not adding 1 for finding range, which is compensated by not adding length
    }
};