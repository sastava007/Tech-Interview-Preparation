// Naive solution

//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        int l_sum , r_sum;
        
        for(int i = 0; i<n; i++){
            l_sum=0, r_sum=0;
            for(int j=i-1; j>=0; j--){
                l_sum += a[j];
            }
            
            for(int k = i+1; k<n; k++){
                r_sum += a[k];
            }
            
            if(l_sum == r_sum){
                return i+1;
            }
            
        }
        
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends


// Efficient solution


//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
       long sum = 0, rightSum = 0;
       for(int i=0; i<n; i++){
           sum += a[i];
       }
       
       for(int i = 0; i<n; i++){
           sum -= a[i];
           
           if(sum == rightSum){
               return i+1;
           }
           
           rightSum += a[i];
       }
       
       return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
