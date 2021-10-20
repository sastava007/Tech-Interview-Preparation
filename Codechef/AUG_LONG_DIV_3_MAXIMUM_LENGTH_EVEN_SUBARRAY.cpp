#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 1e5 + 1;
int pf[N];

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  pf[0]=0;
  for(int i=1; i<N; i++){
    pf[i]=pf[i-1]+i;
  }
  while(t--){
     int n;
     cin>>n;
     int m=n;
     int ans;
     int a1;
     while(n>=0){
       if(pf[n]%2==0){
         a1=n;
         break;
       }
       n--;
     }
    //  for(int i=1; i<21; i++){
    //    cout<<pf[i]<<" ";
    //  }
    //  cout<<endl;
    
     int a2;
     
     if(pf[m]%2!=0 and pf[m-1]!=0){
       a2=m-1;
     }else{
       a2=m-2;
     }
     
     ans=max(a1,a2);
     cout<<ans<<"\n";
  }
}