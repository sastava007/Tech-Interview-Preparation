class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        int ans=0;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {                                                   
            if(m[nums[i]])                                                  //if nums[i] is present
            {
                if(k==0)                                                                
                {
                    if(m[nums[i]]==1)
                    {
                        ans++;                                             //consider a=b when k=0
                        m[nums[i]]++;
                    }
                }
                continue;
            }
            if(m[k+nums[i]])                                               //if we consider nums[i]=a
            {
                ans++;
            }
            if(m[nums[i]-k])                                               //if we consider nums[i]=b
            {
                ans++;
            }
            m[nums[i]]=1;
        }
        return ans;
    }
};