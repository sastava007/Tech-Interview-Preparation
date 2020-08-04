/*  Given a collection of distinct integers, return all possible permutations.
    Okay, so the first thing that jumps into my mind, upon seeing the pattern is that, we can fix one number and call to our recursive funtion to get the permutation of remaining elements

    [1,2,3] => [1] + permute[2,3] => [[1,2,3], [1,3,2]]

    Start with an index...
    Traverse to the end of the array...
    Swap each index (including the start index) with the start index...
    Recurse one slot beyond the start index...
    Swap back...
    
    TC: O(n!)
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> result;
        if(nums.size()==0)
            return result;
        
        backtrack(nums, 0, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& nums, int pos, vector<vector<int>> &result)
    {
        if(pos==nums.size())    //base case
        {
            result.emplace_back(nums);
            return;
        }
        for(int i=pos; i<nums.size(); i++)
        {
            swap(nums[i], nums[pos]);
            backtrack(nums, pos+1, result);   // fix the first element, and recursively call permutations on remaining elements
            swap(nums[i], nums[pos]);   // reset the swap, back to original placement of elements
        }
    }
};



/* If list has duplicates */

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector<vector<int>> result;
        if(nums.size()==0)
            return result;
        
        sort(nums.begin(), nums.end());
        
        dfs(nums, 0, result);
        return result;    
    }
    
private:
    void dfs(vector<int> nums, int pos, vector<vector<int>> &result)
    {
        if(pos==nums.size())    //base case
        {
            result.emplace_back(nums);
            return;
        }
        for(int i=pos; i<nums.size(); i++)
        {
            if(i!=pos && nums[i]==nums[pos])
                continue;
            
            swap(nums[i], nums[pos]);
            dfs(nums, pos+1, result);   // fix the first element, and recursively call permutations on remaining elements
        }
    }
};