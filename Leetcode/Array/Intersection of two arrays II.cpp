/* Using hashmap */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int, int> m;
        for(auto it: nums1)
            m[it]++;
        
        vector<int> ans;
        
        for(auto it: nums2)
        {
            if(m.find(it)!=m.end() && --m[it]>=0)
                ans.emplace_back(it);
        }
        
        return ans;
    }
};

/* Intutions: Similar to merging two sorted arrays */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = (int)nums1.size(), n2 = (int)nums2.size();
        int i1 = 0, i2 = 0;
        vector<int> res;
        while(i1 < n1 && i2 < n2){
            if(nums1[i1] == nums2[i2]) {
                res.push_back(nums1[i1]);
                i1++;
                i2++;
            }
            else if(nums1[i1] > nums2[i2]){
                i2++;
            }
            else{
                i1++;
            }
        }
        return res;
    }
};