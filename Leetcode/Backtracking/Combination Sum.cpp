/* Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target. */
// TC:  Every time you have N choice (since you can use number repeatedly), and you can choose at most target times (actually it's smaller than target), so we can assume the worst-case time complexity is O(N^target). Space:O(target)

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> result;
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

/*  Combination Sum 2: We can't use the same number again & again and there will be duplicates 
    Time Complexity: There are (2^n) such elements and hence the time complexity is O(2^n)
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