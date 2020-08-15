/* 
    The value of each element represents the maximum jump length from that position. We've to find whether it's possible to reach the last index of array or not.  
    Ex: [2,3,1,1,4] here arr[0] = 2 represents that we can make a maximum jump of 2. So either we can jump1 or jump2 but we're not sure which one will work out. So we've to
    try to explore all the possible combinations hence backtracking + DP.

    TC: O(N^2) becz for every element, we're looking at the next nums[i] elements to its right side for finding the good index(i.e from which we can reach the end)
*/

class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        vector<int> memo(nums.size(), -1);
        memo[nums.size()-1] = 1;
        return util(nums, memo, 0);
    }
private:
    bool util(vector<int>&nums, vector<int> &memo, int pos)
    {   
        if(memo[pos] != -1)
        {
            return memo[pos]==1?true:false;
        }
        int farthestJump = (pos+nums[pos]<nums.size()-1)?(pos+nums[pos]):nums.size()-1;
        for(int i=pos+1; i<=farthestJump; i++)
        {
            if(util(nums, memo, i))
            {
                memo[pos] = 1;
                return true;
            }
        }
        memo[pos] = 0;
        return false;
    }
};

/* Bootom Up: Eliminating the space due to recursion stack */

class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        vector<int> memo(nums.size(), -1);
        memo[nums.size()-1] = 1;    // this means that we can always reach memo[nums.size()-1] starting from last position

        for(int i=nums.size()-2; i>=0; i--)
        {
            int farthestJump = min(i+nums[i], nums.size()-1);      // We only look for the index right of our current position that whether they are good/bad index. Starting from last index
                                                                  // which is always good. So once we find a good index we can simply break there & don't need to check further.
            for(int j = i+1; j<=farthestJump; j++)
            {
                if(memo[j]==1)
                {
                    memo[i] = 1;
                    break;
                }
            }
        }
        return (memo[0] == 1);
    }
};

/*  Greedy Approach:
    If we observe we can find that for each index we've to check if we can reach the last index or not. And for this we only check whether if we're to reach a good index, becz from there
    we can ultimately reach the last position. So we need to maintain the nearest(left most) one good index, this can be seen from above bottom-up approach as well where we break the loop
    once we find a good index.

    Iterating right-to-left, for each position we check if there is a potential jump that reaches a GOOD index (currPosition + nums[currPosition] >= leftmostGoodIndex)
*/

bool canJump(vector<int>& nums) 
{
    int lastPos = nums.size()-1;
    for(int i=nums.size()-2; i>=0; i--)
    {
        if(i+nums[i]>=lastPos)
            lastPos = i;
    }
    
    return lastPos == 0;
}