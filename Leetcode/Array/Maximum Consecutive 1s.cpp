/* Find the maximum number of 1s */

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int ans = 0, count = 0;
        for(int &n: nums)
        {
            if(n==1)
                count++;
            else
                count = 0;
            ans = max(ans, count);
        }
        return ans;
    }
};

/*  Sliding Approach: Find the length of the longest (contiguous) subarray that contains only 1s. We can convert atmost K 0s to 1s.
    As the no. of 1s is fixed(we can't flip them) so the basically problem boils down to finding the longest subarray with atmost K zeroes. 
*/

class Solution 
{
public:
    int longestOnes(vector<int>& A, int K) 
    {
        int zeroCount = 0, maxlen=0;
        int l=0, r=0;
        while(r<A.size())
        {
            if(A[r]==0)
                zeroCount++;
            while(zeroCount>K)
            {
                if(A[l]==0)
                    zeroCount--;
                l++;
            }
            maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};

/*  Follow Up: Incase we'va an infinite stream of numbers, such that we can't store all the numbers in memory. Here we can use queue<> for this purpose, 
    which basically stores the indices of current window of size K 
    TC: O(N) and Spcae: O(K)    
*/
public int findMaxConsecutiveOnes(int[] nums) 
{                 
    int max = 0, k = 1; // flip at most k zero
    Queue<Integer> zeroIndex = new LinkedList<>(); 
    for (int l = 0, h = 0; h < nums.length; h++) 
    {
        if (nums[h] == 0)
            zeroIndex.offer(h);
        if (zeroIndex.size() > k)                                   
            l = zeroIndex.poll() + 1;
        max = Math.max(max, h - l + 1);
    }
    return max;                     
}