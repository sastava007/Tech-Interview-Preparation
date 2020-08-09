/* Sort an array of 0s, 1s, and 2s */

void sortColors(vector<int>& nums) 
{
    int n = nums.size();
    if(n==0)
        return;
    
    int low = 0, mid = 0, high = n-1;
    
    while(mid <= high)
    {
        if(nums[mid]==0)
            swap(nums[low++], nums[mid++]);
        else if(nums[mid]==2)
            swap(nums[mid], nums[high--]);
        else
            mid++;
    }
}