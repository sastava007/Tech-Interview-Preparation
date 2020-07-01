/* A variation of finding rain water trapping problem, where instead of finding total water trapped we've to find the maximum amount of water b/w two end or maximum capacity of a container */

class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int maxWater = 0;
        int left = 0, right = height.size()-1;
        
        while(left<right)
        {
            maxWater = max(maxWater, min(height[left], height[right])* (right-left));

            if(height[left]<height[right])   //we're here moving the shorter line, becz the amt. of water is responsible on minimum or smaller which will basically compesate
                left++;                     // for the decrease in width 
            else
                right--;
            
        }
        
        return maxWater;
    }
};