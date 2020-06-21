/* Find length of the longest continious increasing subsequence(subarray) */

/* by recording length */
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        if(nums.size()==0)
            return 0;
        
        int ans = 1, count=1;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]>nums[i-1])
            {
                count++;
                ans = max(ans, count);
            }
            else
                count=1;   
        }
        return ans;
    }
};

/* Using 2 Pointer */
class Solution {
public:
    int findLengthOfLCIS(vector<int>& a) 
    {
        int mx = 0;
        for (int i = 0, j = 0; j < a.size(); j++) 
        {
            if (j == 0 || a[j] <= a[j - 1]) 
                i = j;
            mx = max(mx, j - (i - 1))
        }
        return mx;
    }
};
