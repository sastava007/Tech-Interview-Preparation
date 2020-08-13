/*
    This is similar to maximum sum subarray solved using Kadane's Algorithm where we've 2 variables, one to maintain the curent maximum, and other one for maximum obtained so far.
    


    And in case, -ve numbers are present even no. of times the overall swapping get nullifies and we end up getting maximum value in maxval by the end of array. 
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int ans = nums[0], minProd = nums[0], maxProd = nums[0];    // max-minProd represents the maximum & minimum product of subarray that ends with nums[i]
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]<0)       // When multiplied by a negative no, the bigger no. will become smaller and the smaller one become bigger.
                swap(maxProd, minProd);     // so we've to redfine the extreme values by swapping them
            
            maxProd = max(nums[i], nums[i]*maxProd);    // We can either add the new element to the existing product, or start fresh the product from current index.
            minProd = min(nums[i], nums[i]*minProd);    
            
            ans = max(ans, maxProd);
        }
        return ans;
    }
};