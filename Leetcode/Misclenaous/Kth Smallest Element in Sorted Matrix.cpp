/* Find the Kth smallest(not Kth distinct) element sorted matrix, we are guranteed that K will lie in [1,n^2]  */

/*  Using min-heap: TC(min(K,N) + KlogN) and Space: O(N) 
    Build the min-heap with elements of first row, this would take O(min(K,N)) time, then remove the top smallest element K-1 times and add the next element in same column.
    This way we end up having Kth Smallest element at the end.
*/

class Solution {

    class compare       // custom comparator for min-heap
    {
        public:
            bool operator()(pair<int,pair<int,int>> &a, pair<int,pair<int,int>> &b)
            {
                return a.first > b.first;
            }
    };
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, compare> q;    // min-heap
        
        int n=matrix.size(), m=matrix[0].size();
        
        for(int i=0; i<m; i++)
            q.push({matrix[0][i], {0,i}});
        
        for(int i=0; i<k-1; i++)    // remove top K elements
        {
            auto temp = q.top();
            q.pop();
            
            int x = temp.second.first, y = temp.second.second;
            if(x==n-1)
                continue;
            
            q.push({matrix[x+1][y], {x+1, y}});
        }
        
        return q.top().first;
    }
};

/* Using binary Search: O(N*log(max-min)) and O(1) space */

class Solution {

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int n = matrix.size(), ans;
        int low = matrix[0][0], high = matrix[n-1][n-1];
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            int num = countLessThanEqual(matrix, mid);
            if(num<k)               // if no. of elements which are less than mid is less than K, then we've to increase our search space towards right
                low = mid+1;
            else                    // we aren't directly returning mid when num==k, becz we aren't sure that mid is present in matrix also we're trying to minimize this number
            {
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
private:
    int countLessThanEqual(vector<vector<int>>& matrix, int mid)   // find the no. of elements which are less than or equal to mid 
    {
        int n = matrix.size();
        int i = n-1, j = 0, count=0;
        while(i>=0 && j<n)
        {
            if(matrix[i][j] > mid)
                i--;
            else
            {
                count += (i+1);     // this means that all the elements in this column will also be <= so add no. of elements in this column to our count
                j++;
            }
        }
        return count;
    }
};