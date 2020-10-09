class Solution {
public:
    void find( vector<int>& candidates, int target, vector<vector<int>>&ans, vector<int>v ,int start )
    {
        if(target==0)
        {
            ans.push_back(v);
            return;
        }
        for(int i=start;i<candidates.size();i++)
        {
            if(target>=candidates[i])
            {
                v.push_back(candidates[i]);
                find(candidates,target-candidates[i],ans,v,i);
                v.pop_back();
            }
            else
            {
                break;
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        vector<int>v;
        find(candidates,target,ans,v,0);
        return ans;
    }
};