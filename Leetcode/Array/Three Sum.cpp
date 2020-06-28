/* O(n2) AC Leetcode Solution: Remove/skip the duplicates */

vector<vector<int>> threeSum(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    
    for(int i=0;i<(int)nums.size()-1;i++)
        {
            int low=i+1, high=nums.size()-1;
        
            if(nums[i] > 0)    // if current element is >0, then all the elements after this point will be in increasing order so we can't get 0 sum
                break;
        
            while(low<high)
            {
                if(nums[low]+nums[high]+nums[i] < 0)
                    low++;
                else if(nums[low]+nums[high]+nums[i] > 0)
                    high--;
                else
                {
                    vector<int> triplet{nums[i], nums[low], nums[high]};
                    
                    while(low<high && nums[low]==triplet[1])    //skip duplicates for second element
                        low++;
                    while(low<high && nums[high]==triplet[2])   //skip duplicates for third element
                        high--;
                    ans.emplace_back(triplet);
                }
            }
            while((i+1)<nums.size() && (nums[i]==nums[i+1]))  //skip duplicates for the first element, also check for the bound before comparing
                i++;
        }
    return ans;
}


/* Without removing duplicates: Not Yet Tested */

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
                    int x =-(nums[i]+nums[j]);
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

/* Using 2 pointers algo */
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,k;
	    cin>>n>>k;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
            
        sort(a,a+n);
        bool found=false;
        for(i=0;i<n-1;i++)
        {
            int l=i+1, r=n-1;
            while(l<r)
            {
                if(a[i]+a[l]+a[r] == k)
                {
                    found =true;
                    break;
                }
                else if(a[i]+a[l]+a[r]<k)
                l++;
                else 
                r--;
            }
        }
        
        found?cout<<"1\n":cout<<"0\n";
	}
	return 0;
}