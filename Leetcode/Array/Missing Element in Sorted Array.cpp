/*  
    Note: No. of missing elements in a range can be calculated by (nums[nums.size()-1]-nums[0]+1)-nums.size() 
    i.e total range of elements - length of range

    A = [4,7,9,10]
        K = 1, Output: 5
        K = 3, Output: 8
    A = [1,2,4]
        K = 3, Output: 6
    
    index:  0   1   2   3   4   5   6   7   8
    number: 4   7   9   10  13  15  16  18  19
no_missing: 0   2   3   3   5   6   6   7   7

    So if K = 4, then we'll stop at number = 13
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
        while(left < right) //lower bound of K
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