/* Peak element: which is greater than it's both the neighbours
    Intution: can be derived from finding bitonic point in an array.
 */

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