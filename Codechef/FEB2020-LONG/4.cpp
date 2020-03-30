#include <iostream>
#define ll long long 
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t ;
	while(t--){
    ll c=0, n, p;
	bool b = false;
	cin >> n >> p;
	ll d[n], a[n];
	for(int i = 0 ; i < n ; i++)
	    cin >> d[i] ;
   for(int i = 0 ;i < n-1; i++){
        if(d[i+1]%d[i] == 0 && p%d[i]==0)
        continue;
        b=true;
    }
    if(p%d[n-1]!=0)
      b=true;
    if(b==false)
      cout<<"NO"<<endl;
    else if(b==true){
        if(p<d[n-1]){
            for(int i=0;i<n-1;i++)
            a[i]=0;
            a[n-1]=1;
           goto label;
        }
        for(int i=0;i<n;i++){
            if(p%d[n-1-i]==0 && p/d[n-1-i]>=1)
            a[n-1-i]=p/d[n-1-i]-1;
            else if(p%d[n-1-i]!=0 && p/d[n-1-i]>0)
            a[n-1-i]=p/d[n-1-i]+1;
            else
            a[n-1-i]=0;
            p-=d[n-i-1]*a[n-i-1];
        }
        for(int i = 0;i < n ;i++){
            if(d[i] <= p)
              continue;
            else
              c = i;
            break;
        }
        if(p > 0){
            a[c]++;
        }
        label:
        cout<<"YES ";
        for(int i = 0;i < n;i++)
        cout << a[i] << " ";
        cout << endl;
      }
    }
	return 0;
}
