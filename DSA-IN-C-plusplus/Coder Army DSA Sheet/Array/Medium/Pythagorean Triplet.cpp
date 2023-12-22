// Brute force solution

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    // code here
	    for(int i=0; i<n; i++){
	        for(int j=i; j<n; j++){
	            for(int k=j+1; k<n; k++){
	                int x = arr[i] * arr[i];
	                int y = arr[j] * arr[j];
	                int z = arr[k] * arr[k];
	                
	                if((x == y+z) || (y == x + z) || (z == x + y)){
	                    return true;
	                }
	            }
	        }
	    }
	    
	    return false;
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

// } Driver Code Ends


// Better solution

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    // code here
	    for(int i=0; i<n; i++){
	        arr[i] = arr[i] * arr[i];
	    }
	    
	   sort(arr, arr+n);
	   
	   for(int i=n-2; i>=0; i--){
	       int left=0, right = i-1;
	       
	       while(left < right){
	           if(arr[left] + arr[right] == arr[i]){
	               return true;
	           }
	           
	           else if(arr[left] + arr[right] < arr[i]){
	               left++;
	           }
	           
	           else{
	               right--;
	           }
	       }
	   }
	   
	   return false;
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

// } Driver Code Ends

// Efficient solution

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    // code here
	    int maximum = 0;
	    
	    for(int i=0; i<n; i++){
	        maximum = max(maximum, arr[i]);
	    }
	    
	    vector<int> hash(maximum + 1, 0);
	    
	    for(int i=0; i<n; i++){
	        hash[arr[i]]++;
	    }
	    
	    for(int i=1; i<maximum + 1; i++){
	        if(hash[i] == 0) continue;
	        for(int j=1; j< maximum + 1; j++){
	        if((i == j && hash[i] ==1) || hash[j] == 0) continue;
	        
	        int val = sqrt(i*i + j*j);
	        
	        if((val * val) != (i*i + j*j)) continue;
	        
	        if(val > maximum) continue;
	        
	        
	        if(hash[val]){
	            return true;
	        }
	    }
	        
	    }
	    
	    
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

// } Driver Code Ends
