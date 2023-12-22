class Solution {
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums){
	    // Code here
	    vector<pair<int, int>>v;
	    int ans = 0;
	    int n=nums.size();
	    
	    for(int i=0; i<n; i++){
	        v.push_back({nums[i], i});
	    }
	    
	    // sort the array of pairs
	    sort(v.begin(), v.end());
	    
	    for(int i=0; i<n; i++){
	        if(i==v[i].second){
	            continue;
	        }
	        
	        else{
	            ans++;
	            swap(v[i], v[v[i].second]);
	            
	            i--;
	        }
	    }
	    
	    return ans;
	}
};
