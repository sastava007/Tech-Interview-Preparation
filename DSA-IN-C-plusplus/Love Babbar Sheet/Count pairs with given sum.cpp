//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        int count = 0;
        unordered_map<int, int>mp;
        
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        
        for(int i=0; i<n; i++){
            if(mp[k - arr[i]]>0){
                mp[arr[i]]--;
                count+=mp[k-arr[i]];
            }
        }
        
        return count;
    }
};
