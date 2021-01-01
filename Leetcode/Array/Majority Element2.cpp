/* 
    Given an array of size n, find all elements that appear more than ⌊n/3⌋ times.

    Idea: Modified version of Boyer-moore's voting algorithm, here at max we can have at max 2 majority candidates which has freq > n/3
    TC: O(N) & Space: O(1)
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
    
        vector<int> result;    
        int candidate1 =  0, candidate2 = 1, count1 = 0, count2 = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == candidate1)
                count1++;
            else if(nums[i] == candidate2)
                count2++;
            else if(count1 == 0)
                candidate1 = nums[i], count1 = 1;
            else if(count2 == 0)
                candidate2 = nums[i], count2 = 1;
            else
            {
                count1--;
                count2--;
            }
        }
        
        count1 = 0, count2 = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == candidate1)
                count1++;
            else if(nums[i] == candidate2)
                count2++;
        }
        
        if(count1>nums.size()/3)
            result.push_back(candidate1);
        if(count2>nums.size()/3)
            result.push_back(candidate2);
        
        return result;
    }
};