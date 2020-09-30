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
        int sum=0;
        for(auto ele:v) sum+=ele;
        if(sum&1) {
            cout<<"NO"<<endl;
            continue;
        }
        sum/=2;
        bool dp[n+5][sum+5];
        memset(dp,false,sizeof(dp));
        for(int j=0;j<=sum;j++) dp[0][j]=false;
        for(int i=0;i<=n;i++) dp[i][0]=false;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if((j-v[i-1])==0) dp[i][j] = true;
                else if((j-v[i-1])>0){
                    dp[i][j] = (dp[i-1][j-v[i-1]] | dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        if(dp[n][sum]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    return 0;
}