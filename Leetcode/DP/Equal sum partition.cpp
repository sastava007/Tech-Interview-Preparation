
/* Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets. */


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0 ; 
        
        for ( int i = 0 ; i < nums.size(); i++){
            sum+= nums[i];
        }
        
        if ( sum%2 != 0){
            return false;
        }
        
        int part[sum/2+1];
        
        for ( int i = 0 ; i <= sum/2; i++){
            part[i]=0;
        }
        
        for ( int i = 0 ; i < nums.size(); i++){
            for ( int j = sum/2; j >= nums[i]; j--){
                if ( part[j-nums[i]]==1 or j == nums[i]){
                    part[j]=1;
                }
            }
        }
        
        return part[sum/2];
    }
};