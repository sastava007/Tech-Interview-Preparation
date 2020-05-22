/* 
    The maximum subarray sum is max(Maximum subarray sum in non circular array, Maximum subarray sum in circular array)
    first one can be simply computed using Kadane's algorithm, and for the second part 
    maximum sum in circular array = totalSum - minimum subarray sum

 */

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& a) 
    {
        int noncircularsum = kadanes(a, true);
        
        int totalsum = 0;
        for(int i =0; i<a.size(); i++)
            totalsum += a[i];
        
        int circularsum = totalsum - kadanes(a, false);
        
        if(circularsum == 0)    //in case of all negative numbers
            return noncircularsum;
        
        return max(circularsum, noncircularsum);
        
    }
    
private:
    
    int kadanes(vector<int> &a, bool maximum)
    {
        int sum = a[0], maxsum = a[0];
        for(int i = 1;i<a.size(); i++)
        {
            if(maximum)
            {
                sum = max(a[i], sum+a[i]);
                maxsum=max(sum, maxsum);
            }
            else
            {
                sum = min(a[i], sum+a[i]);
                maxsum = min(maxsum, sum);
            }
        }
        
        return maxsum;
    }
};