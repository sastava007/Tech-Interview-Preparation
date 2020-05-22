class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int low = 0, high = nums.size()-1;
        
        while(low<high)
        {
            int mid = (low+high)/2;
        
            if(nums[mid] > nums[high])  //if mid lies on first line
                low = mid+1;
            else if(nums[mid] < nums[high])    //if mid lies on second line
                high = mid;
        }
        
        return nums[low];
    }   
};