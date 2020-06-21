/* 2 Pointer approach, maintain a variable that stores position of lastNonZero value ocurred */
class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int lastNonZeroAt = 0;
        for(int i=0; i<nums.size(); i++)
            if(nums[i] != 0)
                nums[lastNonZeroAt++]=nums[i];
        
        for(int i=lastNonZeroAt; i<nums.size(); i++)
            nums[i]=0;
    }
    
};

/* More efficient solu: 1 Pass A simple realization is if the current element is non-0, its' correct position can at best be it's current position or a position earlier. 
If it's the latter one(i.e it's correct position is few places earlier), then the current position will be eventually occupied by a non-0 ,or a 0, which lies at a index greater than 'cur' index.*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int lastNonZeroAt = 0;
        for(int i=0; i<nums.size(); i++)
            if(nums[i] != 0)
                swap(nums[lastNonZeroAt++],nums[i]);
 
    }
    
};