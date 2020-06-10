/* Find the maximum number of 1s */

int findMaxConsecutiveOnes(vector<int>& nums) 
{
        int max_cnt = 0, cnt = 0;
        for (auto n : nums) 
        {
            if (n == 1) max_cnt = max(++cnt, max_cnt);
            else cnt = 0;
        }
        return max_cnt;
}

/*  Sliding Approach: Find the length of the longest (contiguous) subarray that contains only 1s. We can convert atmost K 0s to 1s.
    As the no. of 1s is fixed(we can't flip them) so the basically problem boil down to finding the subarray with atmost K zeroes. 
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