/*  Subset: Given a set of integers, nums, return all possible subsets (the power set).

    Power Set is basically all possible combinations of all possible lengths, from 0 to n.
    
    TC & Space: O(N*2^N) where 2^N to generate all subsets as we can either pick/drop each element and N to copy them into output set
*/



class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> result;
        backtrack(nums, result, vector<int>{}, 0);
        return result;
    }
private:
    void backtrack(vector<int>& nums, vector<vector<int>> &result, vector<int> set, int start)
    {
        result.emplace_back(set);
        for(int i=start; i<nums.size(); i++)
        {
            set.emplace_back(nums[i]);
            backtrack(nums, result, set, i+1);
            set.pop_back();
        }
    }
};

/* Subsets2: Contains duplicates integer  */
public List<List<Integer>> subsetsWithDup(int[] nums) {
    List<List<Integer>> list = new ArrayList<>();
    Arrays.sort(nums);      // sort to get the duplicate elements togeter
    backtrack(list, new ArrayList<>(), nums, 0);
    return list;
}

private void backtrack(List<List<Integer>> list, List<Integer> tempList, int [] nums, int start){
    list.add(new ArrayList<>(tempList));
    for(int i = start; i < nums.length; i++){
        if(i > start && nums[i] == nums[i-1]) continue; // skip duplicates
        tempList.add(nums[i]);
        backtrack(list, tempList, nums, i + 1);
        tempList.remove(tempList.size() - 1);
    }
} 