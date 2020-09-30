//https://practice.geeksforgeeks.org/problems/minimum-sum-partition/0

#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(auto &itr:v) cin>>itr;
        int fullsum=0;
        for(auto ele:v) fullsum+=ele;
        
        int sum=fullsum/2;
        bool dp[n+5][(sum)+5];
        for(int j=0;j<=sum;j++) dp[0][j]=false;
        for(int i=0;i<=n;i++) dp[i][0]=true;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(j-v[i-1]>=0){
                    dp[i][j] = dp[i-1][j-v[i-1]] or dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        int s1;
        for(int j=0;j<=sum;j++){
            if(dp[n][j]) s1=j;
        }
        
        cout<<(fullsum - s1) - s1<<endl; 
    }
    return 0;

}