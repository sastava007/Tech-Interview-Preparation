pair<long long, long long> getMinMax(long long a[], int n) {
    int mn = INT_MAX, mx = INT_MIN;
    
    for(int i = 0; i<n; i++){
        if(a[i] < mn){
            mn = a[i];
        }
        
        if(a[i] > mx){
            mx = a[i];
        }
    }
    
    return {mn, mx};
    
}
