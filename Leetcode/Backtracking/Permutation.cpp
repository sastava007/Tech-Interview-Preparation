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
        
        dfs(nums, 0, result);
        return result;
    }
    
private:
    void dfs(vector<int>& nums, int pos, vector<vector<int>> &result)
    {
        if(pos==nums.size())    //base case
        {
            result.emplace_back(nums);
            return;
        }
        for(int i=pos; i<nums.size(); i++)
        {
            swap(nums[i], nums[pos]);
            dfs(nums, pos+1, result);   // fix the first element, and recursively call permutations on remaining elements
            swap(nums[i], nums[pos]);   // reset the swap, back to original placement of elements
        }
    }
};




/* If list has duplicates */
List<List<Integer>> permuteUnique(int[] nums) 
{
    List<List<Integer>> list = new ArrayList<>();
    Arrays.sort(nums);
    backtrack(list, new ArrayList<>(), nums, new boolean[nums.length]);
    return list;
}

private void backtrack(List<List<Integer>> list, List<Integer> tempList, int [] nums, boolean [] used)
{
    if(tempList.size() == nums.length){
        list.add(new ArrayList<>(tempList));
    }
    else
    {
        for(int i = 0; i < nums.length; i++){
            if(used[i] || i > 0 && nums[i] == nums[i-1] && !used[i - 1]) continue;
            used[i] = true; 
            tempList.add(nums[i]);
            backtrack(list, tempList, nums, used);
            used[i] = false; 
            tempList.remove(tempList.size() - 1);
        }
    }
}