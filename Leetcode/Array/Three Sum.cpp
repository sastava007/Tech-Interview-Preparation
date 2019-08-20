#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {

        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-1;i++)
            {
                unordered_set<int> s;
                for(int j=i+1;j<nums.size();j++)
                {
                    int x=-(nums[i]+nums[j]);
                    if(s.find(x)!=s.end())
                    {
                        vector<int> v;
                        v.emplace_back(nums[i]);
                        v.emplace_back(nums[j]);
                        v.emplace_back(x);
                        ans.emplace_back(v);
                    }
                    else
                        s.insert(nums[j]);

                }
            }
        return ans;

    }
};

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v{-1,0,1,2,-1,4};
    Solution obj;
    vector<vector<int>> ans=obj.threeSum(v);
    for(int i=0;i<ans.size();i++)
    {
        for(auto it:ans[i])
        cout<<it<<" ";
        cout<<"\n";
    }

}
