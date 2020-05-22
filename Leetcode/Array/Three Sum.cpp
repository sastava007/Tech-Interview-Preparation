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