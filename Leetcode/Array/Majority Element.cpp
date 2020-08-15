/* 
    Moore's Voting Algorithm 
        1. Find the most probable candidate
        2. Verify if candidate is majority element or not

    Basic idea is if each occurence of an element E can be cancelled with all other elements that are different from E, but still if E exists in last then it is the majority element
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int candidate = 0, count = 1;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]==nums[candidate])
                count++;
            else
                count--;
            
            if(count==0)
            {
                candidate = i;
                count = 1;
            }
        }
        if(verify(nums, candidate))     // check with your interviewer that whether we're sure about the existence of majority element or not
            return nums[candidate];
        else
            return -1;
    }
    bool verify(vector<int>& nums, int major)
    {
        int count = 0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]==nums[major])
                count++;
        
        return (count>nums.size()/2);
    }
};

/* 
    General form for freq > N/K then in such case there will be at max (K-1) elements at max.
    TC: O(N*K) and Space: O(K)
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        unordered_map<int,int> mp;
        int k;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])!=mp.end())  // if number already exist in array, then simply keep on increasing it's frequency
            {
                mp[nums[i]]++;
            }
            else    // otherwise if it doesn't exist already in array
            {
                if(mp.size() == k-1)    // if we're already full, and we need to store a new candidate then reduce the frequency of elements and if someone's become 0 then simply delete it
                {
                    for(auto j=mp.begin();j!=mp.end();)
                    {
                        j->second--;
                        if(j->second==0)
                            j=mp.erase(j);
                        else 
                            j++;
                    }
                }
                else
                {
                    mp[nums[i]] = 1;    // if we still have place, then insert the new one
                }
            }
        }
        for(auto &i:mp)
            i.second=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(mp.find(nums[i])!=mp.end())
                mp[nums[i]]++;  // store the correct frequency of majority candidates
        }
        vector<int> ans;
        for(auto i:mp)
            if(i.second>nums.size()/k)
                ans.push_back(i.first);
        return ans;
    }
};