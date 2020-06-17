/*  */

class Solution {
public:
    int firstBadVersion(int n) 
    {
        int low =1, high = n;
        while(low<=high)
        {
            if(low==high)
                return low;
            int mid = low + (high-low)/2;
            if(isBadVersion(mid))
                high = mid;
            else
                low = mid+1;
        }
        
        return low;
    }
};