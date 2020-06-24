/*   
    Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]...
    Example: nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4]

    Here we can clearly observe that A[even] <= A[odd] and A[odd] >= A[even]. So we can just iterate over the array, and whenever we find any of these coditions not following then simmply swap 
    the adjacent values. 

*/

void wiggleSort(vector<int> &nums)
{
    int n = nums.size();
    if(n==0 || n<=1)
        return;

    for(int i=0; i<n-1; i++)
    {
        if(i%2==0)
        {
            if(nums[i]>nums[i+1])
                swap(nums[i], nums[i+1]);
        }
        else
        {
            if(nums[i]<nums[i+1])
                swap(nums[i], nums[i+1]);
        }
    }
}