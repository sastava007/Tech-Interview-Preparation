/*  Given an array of integer, find the pivot index such that the sum of the elements to it's left is equal to the sum of the elements to it's right. Here we're assuming that
    sum beyond the boundaries are zero. 
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(totalSum-leftSum-nums[i] == leftSum)
                return i;
            
            leftSum += nums[i];
        }
        return -1;
    }
};