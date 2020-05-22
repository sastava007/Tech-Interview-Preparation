/* Given two sorted arrays, and you have to find intersection of them in O(n) time and O(1) space complexity, you can ignore the array for output 
    The idea is to use something similar to merge() algo of merge sort.
*/

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
{
        sort(nums1.begin(),nums1.begin());
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
                while(nums1[i]==cur)
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
