/*   
    As we've to pick exactly one element from each row, so it would be better if we visualize this problems as a combination/pair of rows, such that we find the K pairs with smallest sum.
    So idea is to pick two adjacent rows and for them find the K pairs with smallest sum, and keep on doing the same (m-1) times.

    TC: O((m-1)*(KlogK)) and O(min(N,K)) Space

*/

class Solution {
    
class compare       // custom comparator for min-heap
{
    public:
        bool operator()(pair<pair<int,int>, int> &a, pair<pair<int,int>, int> &b)
        {
            return a.first.first+a.first.second > b.first.first+b.first.second;
        }
};
    
public:
    int kthSmallest(vector<vector<int>>& mat, int k) 
    {
            vector<int> temp = mat[0];
            for(int i=1; i<mat.size(); i++)
                temp = kSmallestPairs(temp, mat[i], k);
        
        return temp[k-1];
    }
    
    private:            
    vector<int> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<int> result;
        int n = nums1.size(), m = nums2.size();  
        
        if(n == 0 || m == 0 || k==0)
            return result;
        
        priority_queue<pair<pair<int,int>, int>, vector<pair<pair<int,int>, int>>, compare> q; 
        
        for(int i=0; i<min(n,k); i++)   // add the mapping for first row elements with 0th element of second row
            q.push({{nums1[i], nums2[0]}, 0});
        
        while(!q.empty() && k-- >0)
        {
            auto temp = q.top();
            q.pop();
            
            result.push_back(temp.first.first + temp.first.second);
            
            if(temp.second==m-1)
                continue;
            
            q.push({{temp.first.first, nums2[temp.second+1]}, temp.second+1});
        }
        return result;
    }
};