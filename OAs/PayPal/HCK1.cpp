#include <bits/stdc++.h>
 
using namespace std;
 
string ltrim(const string &);
string rtrim(const string &);
 
 
#define ll long long
/*
 * Complete the 'connectedSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY edges
 */

const ll N=100050;
ll c=0;
ll V[N]={0};
 
void dfs(vector<ll> A[], ll x){
    V[x]=1;
    c++;
    for(auto y:A[x]){
        if(!V[y]){
            dfs(A,y);
        }
    }
}
int connectedSum(int n, vector<string> edges) {
    ll m= edges.size();
    vector<ll> A[n+1];
    for(auto it:edges){
        stringstream str(it);
        ll x,y;
        str>>x;
        str>>y;
        A[x].push_back(y);
        A[y].push_back(x);
    }
    int ans=0;
 
    for(ll i=1;i<=n;i++){
        if(!V[i]){
            c=0;
            dfs(A,i);
            ans+=ceil(1.0*sqrt(c));
        }
    }
    return ans;
 
}
 
int main()