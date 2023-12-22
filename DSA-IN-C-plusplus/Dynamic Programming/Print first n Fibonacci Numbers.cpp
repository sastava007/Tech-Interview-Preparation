//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        //code here
        
        vector<long long>ans;
        if(n<=0){
            return ans;
        }
        
        ans.push_back(1);
        
        if(n==1){
            return ans;
        }
        
        
        ans.push_back(1);
        
        for(int i=2; i<n; i++){
            long long fib = ans[i-1]+ans[i-2];
            ans.push_back(fib);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends
