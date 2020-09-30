//https://practice.geeksforgeeks.org/problems/number-of-coins/0/

//2D dp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int sum,n;
        cin>>sum>>n;
        vector<int> v(n);
        for(auto &itr:v) cin>>itr;
        int dp[n+1][sum+1];
        for(int j=0;j<=sum;j++) dp[0][j] = INT_MAX - 1;
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(j>=v[i-1]){
                    dp[i][j] = min(1 + dp[i][j-v[i-1]],dp[i-1][j]);
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        if(dp[n][sum] == INT_MAX - 1) cout<<-1<<endl;
        else 
        cout<<dp[n][sum]<<endl;
    }
    return 0;
}


//1D dp

ll n,sum;
cin>>n>>sum;
vector<ll> v(n);
for(auto &itr:v) cin>>itr;
ll dp[sum+1];
for(ll i=0;i<=sum;i++) dp[i] = INT_MAX-1;
dp[0]=0;

for(ll i=1;i<=sum;i++){
    for(ll j=1;j<=n;j++){
        if(i>=v[j-1])
        dp[i] = min(1+ dp[i-v[j-1]] , dp[i]);
    }
}
if(dp[sum]==INT_MAX-1) cout<<-1;
else    
cout<<dp[sum];