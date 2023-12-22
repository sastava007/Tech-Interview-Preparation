class Solution{
    public:
    int firstElementKTime(int a[], int n, int k)
    {
        unordered_map<int, int>mp;
        
        int res = -1;
        
        for(int i=0; i<n; i++){
            mp[a[i]]++;
            
            if(mp[a[i]] == k){
                res = a[i];
                break;
            }
        }
        return res;
        
    }
};
