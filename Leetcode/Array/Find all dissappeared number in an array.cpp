/*  All elements of array are from 1-N where N is size of array, find elements which doesn't appeared even once.
    Idea is to do a 2 pass, in first pass mark all the seen elements as negative, and in the second pass elements which aren't -ve are the ones which aren't discovered yet.
    And hence those are the answers.
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        vector<int> ans;
        int n=nums.size();
        
        for(int i=0; i<n; i++)  {
            
            int val = abs(nums[i])-1;   // elements lie in range of [1-N], but index are from (0 - n-1), so that's why
            if(nums[val]>0)   {     // mark elements which aren't yet been marked as negative 
                nums[val] = -nums[val];
            }
        }
        
        for(int i=0; i<n; i++)  {
            if(nums[i]>0)   {
                ans.push_back(i+1);
            }
        }
        
        return ans;
    }
};