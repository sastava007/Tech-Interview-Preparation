/*  Given an array, find triplets (i,j,k) such that sum of 4 segments in array is equal.

    Representation  _a_[i]_b_[j]_c_[k]_d_

    Efficient Solu: Hashing + Cummulative Sum
    
    So idea is to first compute the cumullative sum, and then iterate over the array to find the middle point 'j' around which both of sides we have to find 'i' and 'j'
    For each value of middle point 'j' we've to check find 1 point to it's left such that (sum[i-1]==sum[j-1]-sum[i]) and also store this sum in hash-set
    Similarly we'll do for right side, 'k' where (sum[n-1]-sum[k]==sum[k-1]-sum[j]) and this sum should be present in left part

    TC: O(N^2) and O(N) Space

    Example: [1,2,1,2,1,2,1]   Ans: (1,3,5)

*/

class Solution {
public:
    bool splitArray(vector<int> &nums) 
    {
        int n = nums.size();
        if(n<7)
            return false;
        
        vector<int> sum(n);
        sum[0] = nums[0];
        for(int i=1; i<n; i++)
            sum[i] = sum[i-1]+nums[i];
            
        for(int j=3; j<n-3; j++)
        {
            unordered_set<int> hash;
            for(int i=1; i<j-1; i++)
            {
                if(sum[i-1]==sum[j-1]-sum[i])
                    hash.insert(sum[i-1]);
            }
            
            for(int k=j+2; k<n-1; k++)
            {
                if(sum[n-1]-sum[k]==sum[k-1]-sum[j] && hash.find(sum[n-1]-sum[k]) != hash.end())
                    return true;
            }
        }
        return false;
    }
};