/*  Given an integer array, find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2.
    
    The idea is to basically explore all permutations, with the following constraints:
    Only add elements to permutation vector (cur in my case) if:

    The element is greater than the last element in cur.
    The element has not been previously added (say I have nums = [1, 3, 5, 7, 7], if I have permutation vector cur = [1, 3, 5], I will only add the first 7 and permute, but not the second 7).
    cur is empty.

    The unordered_set is used to avoid [4,6,7(1)] and [4,6,7(2)] in a same level when we dfs. But it will not skip [4,6,7(1),7(2)], because 7(2) is added in the next dfs level of [4,6,7(1)]. Every time we start a "next level dfs", we will initialize a new unordered_set.

    TC: O(2^N) and Space: O(N) due to recursion stack space. We have total N numbers, and we can pick it or not so that's why O(2^N)
    Worst case will occur when the numbers are in increasing order eg [3,4,7,9]

*/

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        vector<vector<int>> result;
        vector<int> seq;
        dfs(nums, seq, result, 0);
        return result;
    }
private:
    void dfs(vector<int>& nums, vector<int> &seq, vector<vector<int>> &result, int pos)
    {
        if(seq.size()>=2)
        {
            result.emplace_back(seq);       //here I'm not resturning after this statement, becz there could be more elements in our subsequence that follow the above property
        }
        
        unordered_set<int> used;        // insetad of using hashset, we can also use visited[201]={0} and visited[nums[i]+100] = 1
        for(int i=pos; i<nums.size(); i++)
        {
            if((seq.empty() || nums[i] >= seq.back()) && used.find(nums[i]) == used.end())  //check if current element should always be >= previous element in sequence, and it should not be used yet
            {
                seq.push_back(nums[i]);
                used.insert(nums[i]);   // mark the current element as used
                
                dfs(nums, seq, result, i+1);
                seq.pop_back();
            }
        }
    }
};