//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        
        vector<int> vis(leaves+1, 0);
        for(int i=0; i<N; i++){
            int st = frogs[i];
            if(st<=leaves && !vis[st]){
                for(int j=st; j<= leaves; j+=st){
                    vis[j] = 1;
                }
            }
        }
        
        int ans = 0;
        for(int i=1; i<=leaves; i++){
            if(vis[i] == 0){
                ans++;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends
