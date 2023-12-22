class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        int mx = a[n-1];
        vector<int>ans;
        ans.push_back(mx);
        
        for(int i=n-2; i>=0; i--){
            if(a[i]<mx) continue;
            mx=a[i];
            ans.push_back(mx);
            
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};
