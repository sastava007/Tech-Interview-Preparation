// https://practice.geeksforgeeks.org/problems/reach-a-given-score/0

#include<bits/stdc++.h>
using namespace std;
int dp[1001][10];
int solve(int arr[],int n,int i){
    if(i<0 or n<0) return 0;
    if(n==0) return 1;
    if(dp[n][i]!=-1) return dp[n][i];
    
    return dp[n][i] = solve(arr,n-arr[i],i) + solve(arr,n,i-1);
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(dp,-1,sizeof(dp));
        int arr[3] = {3,5,10};
        cout<<solve(arr,n,2)<<endl;
    }
    
    return 0;
}