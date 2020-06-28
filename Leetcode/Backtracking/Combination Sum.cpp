/* Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target. */
/* 
    TC:  Every time you have N choice (since you can use number repeatedly), and you can choose at most target times (actually it's smaller than target), 
    so we can assume the worst-case time complexity is O(N^target) Space:O(target)

    Clarifying questions to ask:
        - all positive number ?
        - will the set contains duplicates ?

    Backtracking Approach
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> result;
        // sort(candidates.begin(), candidates.end())  we can sort to optimize it for few cases, becz we reach to the target slowly slowly using this method rather than uneven jumps
        util(result, vector<int>{}, candidates, 0, target);
        
        return result;
    }
private:
    void util(vector<vector<int>> &result, vector<int> temp, vector<int> &candidates, int start, int target)
    {
        if(target<0)
            return;
        else if(target==0)
            result.emplace_back(temp);
        else
        {
            for(int i = start; i<candidates.size(); i++)
            {
                temp.emplace_back(candidates[i]);
                util(result, temp, candidates, i, target-candidates[i]);    //here we aren't using i+1 becz we can use the same element again
                
                temp.pop_back();    //remove the last inserted element
            }
        }
    }
};

/* DP Solution */
Let me help illustrate the idea.
/*
    We consider, what targets will be yielded, every time a candidate is appended to all the existing combinations.

    Here is my more understandable code using the same idea. 
*/

vector<vector<int>> Solution::combinationSum_dp_increment(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());

    vector<vector<vector<int>>> dp(target + 1, vector<vector<int>>());
    dp[0].push_back(vector<int>());

    for (const int &candidate : candidates) {
        // all the existing combinations, except for those whose sum exceeds target
        for (int sub_target = 0; sub_target + candidate <= target; ++sub_target){  
            vector<vector<int>> new_combinations = dp[sub_target];
            for (vector<int> &new_combination: new_combinations) {  // append a candidate
                new_combination.push_back(candidate);
            }
            int target_yielded = sub_target + candidate;  // the target yielded
            dp[target_yielded].insert(dp[target_yielded].end(), new_combinations.begin(), new_combinations.end());
        }
    }

    return dp[target];
}

/*  Combination Sum 2: We can't use the same number again & again and there will be duplicates 
    Time Complexity: O(2^N) and Space: O(N)
*/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());     // sort to get the same elements adjacent, this will help in removing the duplicates 
        
        util(result, vector<int>{}, candidates, 0, target);
        
        return result;
    }
private:
    void util(vector<vector<int>> &result, vector<int> temp, vector<int> &candidates, int start, int target)
    {
        if(target<0)
            return;
        else if(target==0)
            result.emplace_back(temp);
        else
        {
            for(int i = start; i<candidates.size(); i++)
            {
                if(i>start && candidates[i]==candidates[i-1])       //skip the dupliactes
                    continue;
                
                temp.emplace_back(candidates[i]);
                util(result, temp, candidates, i+1, target-candidates[i]);
                
                temp.pop_back();
            }
        }
    }
};