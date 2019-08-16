#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int n=numbers.size();
        vector<int> ans(2);
        int i=0,j=n-1;
        while(i<j)
        {
            if(numbers[i]+numbers[j]==target)
            {
                ans[0]=i+1;ans[1]=j+1;
                break;
            }
            else if(numbers[i]+numbers[j]>target)
                j--;
            else
                i++;
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
