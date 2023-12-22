//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


int transitionPoint(int arr[], int n) {
    // code here
    for(int i=0; i<n; i++){
        if(arr[i] == 1){
            return i;
        }
    }
    
    return -1;
}

// efficient solution


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
int transitionPoint(int arr[], int n) {
    // code here
   int start = 0, end = n-1;
   
   while(start<=end){
       int mid = (start + end)/2;
       
       if(arr[mid] == 0){
           start = mid + 1;
       }
       
       else if(arr[mid] == 1){
           if(arr[mid - 1] == 0){
               return mid;
           }
           
           else{
               end = mid - 1;
           }
       }
      
   }
   
    return -1; 
}
