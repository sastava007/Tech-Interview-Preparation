class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        if(n==1) return 1;
        
        int sum = 0;
        int sumAns=0;
        for(int i=0; i<n; i++){
            sum+=a[i];
        }
        
        for(int i=0; i<n; i++){
            sum -= a[i];
            if(sum==sumAns){
                return i+1;
            }
            
            sumAns += a[i];
        }
        
        return -1;
    }

};
