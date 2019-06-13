#include<bits/stdc++.h>
using namespace std;
main(){
    int n,i,j,c=0;
    cin>>n;
    string s;
    cin>>s;
    vector<int> v;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(s[i]==s[j])
            {
                v.push_back(j-i);
                break;
            }
        }
    }
    n=v.size();
    for(i=0;i<n-1;i++)
    if(v[i+1]>=v[i])
    c++;
    cout<<c;
}
