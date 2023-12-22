class Solution{
	public:
   	int  minimum_difference(vector<int>nums){
   	    // Code here
   	    int mini = INT_MAX;
   	    sort(nums.begin(), nums.end());
   	    for(int i=0; i<nums.size()-1; i++){
   	        if(mini > abs(nums[i+1]-nums[i])){
   	            mini = abs(nums[i+1] - nums[i]);
   	        }
   	        
   	    }
   	    
   	    return mini;
   	}    
};
