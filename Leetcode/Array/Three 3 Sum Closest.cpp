/*  Given an array of numbers, find three no. whose sum is closest to target value 
    TC: O(N^2)
    Space: O(N) or O(logN) based on sorting algorithm internal implementation.
    But we can get O(1) space complexity using Selection Sort instead of inbuilt sorting function, though this increses the running time but still overall TC remains O(N2)

    We've to return the closest sum possible to target
*/

class Solution {
public:
    
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int n=nums.size(), diff = INT_MAX, ans;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-2; i++)
        {
            int l=i+1, r=n-1;
            while(l<r)
            {
                int sum = nums[i]+nums[l]+nums[r];
                if(abs(target-sum)<diff)
                {
                    diff = abs(target-sum);     // store the minimum diff, and the sum value that led this to diff
                    ans = sum;
                }
                
                if(sum<target)
                    l++;
                else if(sum>target)
                    r--;
                else
                    return sum;
            }
        }
        return ans;
    }
};