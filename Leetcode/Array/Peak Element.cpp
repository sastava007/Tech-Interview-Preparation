/*  Peak element: which is greater than it's both the neighbours */

// TC: O(logN) and Space: O(logN) due to call recursion stack
class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        return binarySearch(nums, 0, nums.size()-1);
    }
    
private:
    int binarySearch(vector<int> &nums, int low, int high)
    {
        if(low==high)
            return low;
        
        int mid1 = (low+high)/2;
        int mid2 = mid1+1;
        
        if(nums[mid1]>nums[mid2])
            return binarySearch(nums, low, mid1);
        else
            return binarySearch(nums, mid2, high);
    }
};

/* Iterative Version  TC: O(logN) & Spcae: O(1) */
class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int low=0, high=nums.size()-1;
        while(low<high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>nums[mid+1])
                high=mid;
            else
                low=mid+1;
        }

        return low;
    }
};