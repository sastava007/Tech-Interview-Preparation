// Solution using Hashing

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int hash[n+1] = {0};
        
        for(int i=0; i<n; i++){
            hash[arr[i]]++;
        }
        
        int repeating = -1, missing = -1;
        
        for(int i=1; i<=n; i++){
            if(hash[i] == 2) repeating = i;
            else if(hash[i] == 0) missing = i;
            
            if(repeating != -1 && missing != -1){
                break;
            }
            
    }
            
            return {repeating, missing};
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int num1 = -1, num2 = -1, sum1 = 0, sum2 = 0;
        
        for(int i=0; i<n; i++){
            int ele = abs(arr[i]);
            
            if(arr[ele-1] < 0){
                num1 = ele;
            }
            
            else{
                arr[ele-1] *= (-1);
                
            }
            
            sum1 += ele;
            sum2+=i+1;
        }
        
        num2 = (sum2 - sum1) + num1;
        
        return {num1, num2};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
