class Solution{
		
	public:
	int maxSumIS(int arr[], int n){  
	    vector<int>dp(n,0);
	    dp[0]=arr[0];
	    int ans=arr[0];
	    for(int i=1; i<n; i++){
	        for(int j=i-1; j>=0; j--){
	            if(arr[j]<arr[i]){
	                dp[i]=max(dp[i],dp[j]);
	            }
	        }
	        dp[i]+=arr[i];
	        ans=max(ans,dp[i]);
	    }
	    return ans;
}   
};
