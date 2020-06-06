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