//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long A[], int len)
{
    // Your code goes here
    
    long long ans=0;
    int low=0, high= len-1;
    
    while(low<high){
        long long water = (high-low)* min(A[low], A[high]);
        if(A[low] < A[high]){
            low++;
        }
        
        else{
            high--;
            
        }
        
        ans = max(ans, water);
        
    }
    
    return ans;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends
