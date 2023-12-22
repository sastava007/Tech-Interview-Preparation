class Solution{
  public:
    vector<int> duplicates(long long arr[], int n) {
        // code here
        vector<int>ans;
        
        for(int i=0; i<n; i++){
            int index = arr[i] % n;
            arr[index] += n;
            
        }
        
        int count = 0;
        for(int i=0; i<n; i++){
            if(arr[i]/n >= 2){
                ans.push_back(i);
                count++;
            }
        }
        
        if(count == 0){
            ans.push_back(-1);
            return ans;
        }
        
        return ans;
    }
};


// 


class Solution{
  public:
    vector<int> duplicates(long long arr[], int n) {
        // code here
        vector<int> ans;
        
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        
        for(auto it: mp){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }
        
        if(ans.size() == 0){
            ans.push_back(-1);
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
