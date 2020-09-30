// https://practice.geeksforgeeks.org/problems/coin-change/0

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sum;
        vector<int> v(n);
        for(auto &itr:v) cin>>itr;
        cin>>sum;
        int dp[n+1][sum+1];
        for(int j=0;j<=sum;j++) dp[0][j]=0;
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(j>=v[i-1]){
                    dp[i][j] = dp[i][j-v[i-1]] + dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        cout<<dp[n][sum]<<endl;
    }
    return 0;
}