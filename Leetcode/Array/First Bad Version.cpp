/* 
    Given n = 5, and version = 4 is the first bad version.

    call isBadVersion(3) -> false
    call isBadVersion(5) -> true
    call isBadVersion(4) -> true

    Then 4 is the first bad version
    TC: O(logN) and PSpace: O(1) 
*/

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