/*  As each row is sorted, and first element of each row is greater than last element of previous row. So we can treat the given matrix as a 2D array and apply simple binary search 
    TC: O(logm+logn) or O(log(mn))

    (n*m) matrix convert to an array => matrix[x][y] => a[x * m + y]. An array convert to n * m matrix => a[x] =>matrix[x / m][x % m];
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if(matrix.empty() || matrix[0].empty())
            return false;
        
        int n = matrix.size(), m = matrix[0].size();
        
        int low = 0, high = m*n-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int midEle = matrix[mid/m][mid%m];      //divide by the column
            
            if(midEle==target)
                return true;
            else if(target<midEle)
                high = mid-1;
            else
                low = mid+1;
        }
        
        return false;
    }
};

/* 
    Given a matrix, in which rows are sorted from left to right and also column are sorted from top to bottom. And we have to search an element, this problem is similar to 
    left most column with  atleast a one. 
    O(m+n) : start from (o,m-1) and keep traversing accordingly.
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if(matrix.empty() || matrix[0].empty())
            return false;
        
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m-1;
        
        while(i<n && j>=0)
        {
            if(matrix[i][j]==target)
                return true;
            else if(target<matrix[i][j])
                j--;
            else
                i++;
        }
        
        return false;
    }
};
