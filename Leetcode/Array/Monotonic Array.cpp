/* Simple one pass solution to check monotonically increasing or decreasing array */

class Solution 
{
    public:
    bool isMonotonic(vector<int> &A) {
        bool increasing = true;
        bool decreasing = true;
        
        for (int i = 0; i < A.size() - 1; ++i) {
            if (A[i] > A[i+1])
                increasing = false;
            if (A[i] < A[i+1])
                decreasing = false;
        }

        return increasing || decreasing;
    }
};