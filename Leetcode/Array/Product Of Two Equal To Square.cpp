/*Two arrays are given,return the number of triplets formed by type1 and type2
 Type1 : Triplet (i, j, k) if nums1[i]^2 == nums2[j] * nums2[k] where 0 <= i < nums1.length and 0 <= j < k < nums2.length.
 Type2 : Triplet (i, j, k) if nums2[i]^2 == nums1[j] * nums1[k] where 0 <= i < nums2.length and 0 <= j < k < nums1.length.
 
 Consider Example
 nums1 = [7,7,8,3], nums2 = [1,2,9,7]
 Output: 2
 Explanation: There are 2 valid triplets.
 Type 1: (3,0,2).  nums1[3]^2 = nums2[0] * nums2[2].
 Type 2: (3,0,1).  nums2[3]^2 = nums1[0] * nums1[1].
*/

class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums1.size();
        int m = nums2.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            double a = nums1[i];    //Store the frequencies of nums1[i]^2
            unordered_map<double,int>mp;    
            for(int j=0;j<m;j++)
            {
                double b = nums2[j];    //Number of results for Type1,
                double f = a*a/b;
                if(mp.find(f) != mp.end())ans+=mp[f];    //if f is present in the map we add the frequency to the ans othherwise increment its frequency in map
                mp[b]++;
            }
        }
        for(int i=0;i<m;i++)
        {
            double a = nums2[i];    //Store the frequencies of nums2[i]^2
            unordered_map<double,int>mp;
            for(int j=0;j<n;j++)
            {
                double b = nums1[j];    //Number of results for Type1,
                double f = a*a/b;
                if(mp.find(f) != mp.end())ans+=mp[f];     //if f is present in the map we add the frequency to the ans othherwise increment its frequency in map
                mp[b]++;
            }
        }
        return ans;
    }
};