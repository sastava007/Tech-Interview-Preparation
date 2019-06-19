#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>b;
vector<ll>c;
ll t,k,x,N,m,p;


vector<vector<ll>> multiply(vector<vector<ll>>A, vector<vector<ll>>B){
    vector<vector<ll>>X(k+1,vector<ll>(k+1));

    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            for(int l=1;l<=k;l++){
                X[i][j] = (X[i][j] + (A[i][l]*B[l][j])%p)%p;
            }
        }
    }

    return X;
}
vector<vector<ll>> power(vector<vector<ll>>T, ll n){
    if(n==1)
        return T;
    if(n&1)
        return multiply(T,power(T,n-1));
    else{
        vector<vector<ll>>X = power(T,n/2);
        return multiply(X,X);
    }
}
ll compute(ll n){
    if(n==0)
      return 0;
    if(n<=k)
       return b[n-1];
    else{
        vector<ll>F1(k+1);

        for(int i=1;i<=k;i++){
            F1[i]=b[i-1];
        }

        vector<vector<ll>>T(k+1,vector<ll>(k+1));
        for(int i=1;i<=k;i++){
             for(int j=1;j<=k;j++){
                 if(i<k){
                        if(i==j-1){
                            T[i][j]=1;
                        }
                        else{
                            T[i][j]=0;
                        }
                 }
                 else{
                     T[i][j]=c[k-j];
                 }
             }
        }

        T = power(T,n-1);
        ll ans=0;

        for(int i=1;i<=k;i++){
            ans = (ans + (T[1][i]*F1[i])%p)%p;
        }
        return ans;
    }
}
int main() {

    	vector<int> v(5);
    	v[1]=56;
    	v[2]=8;
    	v[3]=980;
    	v.push_back(463);
    	cout<<v[5-1];
    	return 0;
}
