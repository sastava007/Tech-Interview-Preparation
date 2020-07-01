/*  As we have to find the next largest number so idea is to iterate from the back, and once we find a no. which is not in descending order then it will be the required point. 
    So we have to find the largest no. from the right side which is just gretaer than this(point) & swap both values, 
    Now our point is at correct position and all we have to do it fix the remaining portion.

    Consider example: [1,2,4,5,3] => here 4 is that reqired point/no. So start finding the no which is greter than it from right [1,2][5][4,3] => reverse/sort the remaing portion => [1,2,5,3,4]

*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {   
        int i = nums.size()-2;
        while(i>=0 && nums[i]>=nums[i+1])   // find the first element from right which is not in descending order nums[i]<nums[i+1]
            i--;
        
        if(i>=0)    // Note: that here if no. are sorted in descending order then it will get reversed. so [5,4,3,2,1] => [1,2,3,4,5]
        {
            int j = nums.size()-1;
            while(j>=0 && nums[j]<=nums[i])     //swap that value with smallest greater element that it
                j--;
            swap(nums[i], nums[j]);
        }
        
        reverse(nums, i+1);     //and now sort the remaining array after that
    }
    
private:
    void reverse(vector<int> &nums, int i)
    {
        int j = nums.size()-1;
        while(i<j)
            swap(nums[i++], nums[j--]);
    }
};