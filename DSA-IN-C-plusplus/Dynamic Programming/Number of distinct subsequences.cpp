//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    #define ll long long
    const ll mod=1e9+7;
    
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int n = s.size();
	    vector<ll> pos(26, n);
	    vector<ll> dp(n+1, 0);
	    ll ans = 1;
	    
	    for(int i=n-1;i>=0;i--){
	        ll cur = dp[i+1];
	        if(pos[s[i]-'a'] < n)
	            cur=(cur-dp[pos[s[i]-'a']+1]+mod)%mod;
	        else
	            cur=(cur+1)%mod;
	        dp[i]=(cur+dp[i+1])%mod;
	        pos[s[i]-'a']=i;
	    }
	    return dp[0]+1;
	}
};


//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends
