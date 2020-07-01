/* Base Problem: Using O(n+m)time and O(n) space */

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        unordered_set<int> hash;
        for(int it: nums1)
            hash.insert(it);
        
        for(int it: nums2)
        {
            if(hash.find(it) != hash.end())
            {
                ans.emplace_back(it);
                hash.erase(it);     // remove it so that, we don't need to add it next time
            }
        }
        return ans;
    }
};

/*  Follow Up: Given two sorted arrays, and you have to find intersection of them in O(n) time and O(1) space complexity, you can ignore the array for output 
    the idea is to use something similar to merge() algo of merge sort.
*/

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
{
        sort(nums1.begin(),nums1.begin());  //no need, already given sorted
        sort(nums2.begin(),nums2.begin());
        
        int i=0,j=0;
        int cur=0;
        vector<int> ans;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]==nums2[j])
            {
                ans.push_back(nums1[i]);
                cur=nums1[i];
                while(nums1[i]==cur)        // skip all the duplicate/same elements
                    i++;
                while(nums2[j]==cur)
                    j++;
            }
            else if(num1[i]<nums2[j])
                i++;
            else
                j++;
        }
        return ans;
}
