//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int linearSearchApproach(int arr[], int n){
         int diff = (arr[n-1] - arr[0]) / n;
        
        for(int i = 0; i < n; i++){
            if(arr[i+1] - arr[i] != diff){
                return arr[i] + diff;
            }
        }
    }
    
    int binarySearchApproach(int arr[], int n){
        int diff = (arr[n-1] - arr[0]) / n;
        int start = 0;
        int end = n-1;
        
        
        while(start<=end){
            int mid = start + (end-start)/2;
            if(arr[mid] - arr[mid-1] != diff){
                return arr[mid-1] + diff;
            }
            
            if(arr[mid+1] - arr[mid] != diff){
                return arr[mid] + diff;
            }
            
            if(mid > 0 && (arr[mid] - arr[0]) != mid*diff){
                end = mid-1;
            }
            
            else{
                start = mid+1;
                 
             }
            
        }
        return -1;
        
    }
    int findMissing(int arr[], int n) {
        // code here
        
        // Solution1
        // int ans1 = linearSearchApproach(arr, n);
        // return ans1;
        
        // Solution 2
        int ans2 = binarySearchApproach(arr, n);
        return ans2;
       
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMissing(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
