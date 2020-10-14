#include <bits/stdc++.h>
using namespace std;
int main()
 {  
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        int res=0;
        int l,r,lsum=0,rsum=0;
        for(int i=0;i<s.length();i++){
            lsum=0, rsum=0;
            l=i,r=i+1;
            while(l>=0 && r<s.length()){
                lsum+=(s[l]-'0');
                rsum+=(s[r]-'0');
                if(rsum==lsum)res=max(res,r-l+1);
                l--;
                r++;
            }
        }
        cout<<res<<"\n";
	//code
    }
	return 0;
}