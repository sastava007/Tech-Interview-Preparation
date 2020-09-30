#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; 
    cin>>t; 
    while(t--){
        int n,w;
        cin>>n>>w;
        
        vector<int> v(n);
        for(auto &itr:v) cin>>itr;
        vector<int> wt(n);
        for(auto &itr:wt) cin>>itr;
        int dp[n+5][w+5];
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int j=0;j<=w;j++) dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=w;j++){
                if(j>=wt[i-1]){
                    //only one change from 0/1 Knapsack which is that if we take the item then we can again take it so v[i-1] + dp[i][j-wt[i-1]] 
                    // i.e. in 0/1 Knapsack -- if 5,6,4,8 is the value array we can take 8 and move to arr with end 4 so dp[i-1][j-wt[i-1]]
                    // in Unbounded Knapsack -- if 5,6,4,8 is the value array we can take 8 and stay at arr with end 8 as again we can take 8 so dp[i][j-wt[i-1]]
                    dp[i][j] = max((v[i-1] + dp[i][j-wt[i-1]]),dp[i-1][j]);
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        cout<<dp[n][w]<<endl;
    }
    return 0;
}