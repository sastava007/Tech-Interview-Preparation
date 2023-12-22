class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(), a.end());
        long long int mini = INT_MAX;
        int i=0;
        int j=m-1;
        while(j<n){
            long long int diff = a[j] - a[i];
            mini = min(mini, diff);
            i++, j++;
        }
        
        return mini;
    
    }   
};

