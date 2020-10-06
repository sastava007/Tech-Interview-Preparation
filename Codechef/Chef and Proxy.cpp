#include <bits/stdc++.h>

using namespace std;

int countAttendance(string s){
    int count=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='P'){
            count++;
        }
    }
    return count;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        int attn=countAttendance(s);
        int count=0;

        for(int i=2;i<n-2;i++){
            if((double)(attn+count)/(double)n>=0.75){
                break;
            }
            if(s[i]!='P' && (s[i-1]=='P' || s[i-2]=='P') && (s[i+1]=='P' || s[i+2]=='P')){
                count++;
            }
        }

        if((double)(attn+count)/(double)n>=0.75){
            cout<<count<<"\n";
        }
        else{
            cout<<"-1\n";
        }
    }

    return 0;
}
