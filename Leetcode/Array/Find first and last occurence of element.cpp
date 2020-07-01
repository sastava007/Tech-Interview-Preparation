/* TC: O(logN) and Space: O(1) */
vector<int> searchRange(int A[], int n, int target) 
{
    int i = 0, j = n - 1;
    vector<int> result(2, -1);
        
    if(n==0)
        return result;

    while (i < j)       // search for the leftmost index
    {
        int mid = i+(j-i) /2;
        if (A[mid] < target) i = mid + 1;
        else j = mid;
    }
    if (A[i]!=target) 
        return result;
    else result[0] = i;
    
    // Search for the rightmost index
    j = n-1;  // We don't have to set i to 0 the second time, becz we know that there is already an occurence of target at 'i' so we don't need to search before that position
    while (i < j)   
    {
        int mid = i+(j-i)/2 + 1;	// Make mid biased to the right
        if (A[mid] > target) j = mid - 1;  
        else i = mid;				// So that this won't make the search range stuck.
    }
    result[1] = j;
    return result; 
}


/* TC: O(logN + K) where K is no. of occurrences of target, which in worst case get linear i.e O(N) */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int l = INT_MAX;
        int r = INT_MIN;
        
        vector<int> ans;
        
        bsearch(nums, 0, nums.size()-1, target, l, r);
        
        if(l==INT_MAX && r==INT_MIN)
        {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(l);
            ans.push_back(r);
        }
        
        return ans;
    }
    
    private:
    
    void bsearch(vector<int> &nums, int low, int high, int key, int &l, int &r)
    {
        if(low<=high)
        {
            int mid = low+(high-low)/2;
            
            if(nums[mid] == key)
            {
                l = min(l, mid);
                r = max(r, mid);
                
                if((mid-1)>=low && nums[mid-1] == key)
                    bsearch(nums, low, mid-1, key, l, r);
                if((mid+1<=high) && nums[mid+1] == key)
                    bsearch(nums, mid+1, high, key, l, r);
            }
            else if(key > nums[mid])
                bsearch(nums, mid+1, high, key, l, r);
            else
                bsearch(nums, low, mid-1, key, l, r);
        }
    }
};