/*  All the numbers exists in pair, except one find that number O(logN) time. Ofcourse we can't use bitwise XOR 
    If all the element occurs twice then the new number will start from even position, but when we have 1 singular(lone) number, then this property get breaks, and we can use binary search
    based on this rule.

    So each time we check, if our mid isn't even then made it even by decrementing one place back. And now we can check if out nums[mid] != nums[mid+1] then the lone number must exists before
    mid, so we change our high acordingly. Else if nums[mid] == nums[mid+1] then change mid = mid+2

*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int low = 0, high = nums.size()-1;

        while (low < high) 
        {
            int mid = (low + high) / 2;
            if (mid % 2 == 1)   // if current position isn't even, then new digit always start from even position, so change it too even
                mid--;

            if (nums[mid] != nums[mid + 1])
                high = mid;
            else 
                low = mid + 2;
        }
        return nums[low];
    }
};