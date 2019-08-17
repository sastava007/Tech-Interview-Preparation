#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<double> temp(nums1.size()+nums2.size());
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),temp.begin());

        int n=temp.size();
        if(n&1)
        {
            double ans=(double)(temp[n/2]*1.0);
            return ans;
        }
        else
        {
            double ans=(double)(temp[(n-1)/2]+temp[(n+1)/2])/2;
            return ans;
        }

    }
};

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution obj;
    vector<int> a{1,2},b{3};
    cout<<obj.findMedianSortedArrays(a,b);
}
