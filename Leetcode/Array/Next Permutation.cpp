
class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        
        int i = nums.size()-2;
        while(i>=0 && nums[i]>=nums[i+1])   // find the first element from right which is not in descending order a[i]<a[i+1]
            i--;
        
        if(i>=0)
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