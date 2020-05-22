/* Represent the two lines on number line for better understanding */

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        return binarySearch(nums, 0, nums.size()-1, target);
    }
    
private:
    
    int binarySearch(vector<int> &nums, int s, int e, int key)
    {
        //base case
        if(s>e)
            return -1;
        
        int mid = (s+e)/2;
        
        if(nums[mid] == key)
            return mid;
        
        //if mid lies on first line 
        if(nums[s] <= nums[mid])
        {
            if(key>=nums[s] && key<=nums[mid])
                return binarySearch(nums, s, mid-1, key);
            else
                return binarySearch(nums, mid+1, e, key);
        }
        //else mid lies on 2nd line, so check if present in sorted part or not
        if(key<=nums[e] && key>=nums[mid])
            return binarySearch(nums, mid+1, e, key);
        else
            return binarySearch(nums, s, mid-1, key);
    }
};


/* Handling duplicates : Worst case O(n) time */

public boolean search(int[] nums, int target) 
{
    int left= 0;
    int right= nums.length - 1;
    while (left<= right) 
    {
        int mid = (left+ right) / 2;
        if (target == nums[mid]) {
            return true;
        }
        if (nums[left] < nums[mid])
        {
            if (target >= nums[left] && target < nums[mid]) {
                right= mid - 1;
            } else {
                left = mid + 1;
            }
        } else if(nums[left] == nums[mid])
        {
            left++;
        }
        else
        {
            if (target > nums[mid] && target <= nums[right]) {
                left= mid + 1;
            } else {
                right= mid - 1;
            }
        }
    }
    return false;
}