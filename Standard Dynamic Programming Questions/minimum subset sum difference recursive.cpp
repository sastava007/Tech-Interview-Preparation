//https://practice.geeksforgeeks.org/problems/minimum-sum-partition/0

#include<bits/stdc++.h>

using namespace std;

int dp[55][10001];
int arr[200001];
int solve(int ind,int x,int y,int n){
    if(ind==n) return abs(x-y);
    
    if(dp[ind][y]!=-1) return dp[ind][y];
    
    return dp[ind][y]=min(solve(ind+1,x+arr[ind],y,n),solve(ind+1,x,y+arr[ind],n));
    
}


int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++) cin>>arr[i];
        memset(dp,-1,sizeof(dp));
        cout<<solve(0,0,0,n)<<endl;
    }
	return 0;
}