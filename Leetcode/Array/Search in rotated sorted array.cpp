/*  Represent the two lines on number line for better understanding 
    We're given an array of no. sorted in asscending order, and rotated at some point. Then here unlike simple sorted array, we'll have 2 range of sorted values
    
    [0,1,2,4,5,6,7] => [4,5,6,7,0,1,2]  & target = 0 return 4

    It should also work for simple array as well:  [4,5,6,7,8,9,11]  target  = 6 return 2
    
    PS: There are no duplicates
*/

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        return binarySearch(nums, 0, nums.size()-1, target);
    }
    
private:
    
    int binarySearch(vector<int> &nums, int s, int e, int key)
    {
        if(s>e)
            return -1;
        
        int mid = (s+e)/2;
        if(nums[mid] == key)
            return mid;
        
        if(nums[s] <= nums[mid])    //if mid lies on first line 
        {
            if(key>=nums[s] && key<=nums[mid])
                return binarySearch(nums, s, mid-1, key);
            else
                return binarySearch(nums, mid+1, e, key);
        }
        else    //else mid lies on 2nd line, so check if present in sorted part or not
        {
            if(key<=nums[e] && key>=nums[mid])
                return binarySearch(nums, mid+1, e, key);
            else
                return binarySearch(nums, s, mid-1, key);  
        }
    }
};


/* Follow Up: handling duplicates Worst case O(n) time */

bool search(int[] nums, int target) 
{
    int left= 0;
    int right= nums.length - 1;
    while (left<= right) 
    {
        int mid = (left+ right) / 2;
        if (target == nums[mid]) {
            return true;
        }
        if(nums[left] < nums[mid])
        {
            if (target >= nums[left] && target < nums[mid]) {
                right= mid - 1;
            } else {
                left = mid + 1;
            }
        }else if(nums[left] == nums[mid])
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