#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n;
int main(){
    int t;
    cin>>t;
    while(t--){
        v.clear();
        cin>>n;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            v.push_back(temp);
        }
        int k;
        cin>>k;
        int sum=k;
        int dp[n+5][sum+5];
        
        for(int j=0;j<=sum;j++) dp[0][j]=0;
        for(int i=0;i<=n;i++) dp[i][0]=1;
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                
                if((j-v[i-1])>=0){
                    dp[i][j] = (dp[i-1][j-v[i-1]] + dp[i-1][j]); 
                    //only change or of subset sum to + here to count the number of subsets

                    
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        cout<<dp[n][sum]<<endl;
        
    }
    return 0;
}