#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> hash;
        vector<int> ans(2);
        
        for(int i=0; i<nums.size(); i++)
        {
            if(hash.find(target-nums[i]) != hash.end())
            {
                ans[0] = i;
                ans[1] = hash[target-nums[i]];
                return ans;
            }
            else
                hash[nums[i]] = i;
        }
        
        return ans;
    }
};

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v{2, 7, 11, 15},ans;
    int target=9;
    Solution obj;
    ans=obj.twoSum(v,target);
    for(int i=0;i<2;i++)
        cout<<ans[i]<<" ";


}
