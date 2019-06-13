#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(string s)
{
    ll range=(1<<s.length());
    ll i;
    set<string> ans;
    for(i=1;i<range;i++)
    {
        ll j=i,idx=0;
        map<char,ll> m;
        string t="";
        while(j>0)
        {
            if(j&1)
            {
               m[s[idx]]++;
               t+=s[idx];
            }
            idx++;
            j=j>>1;
        }
        int flag=0;
        for(auto it:m)
        {
            if(it.second%2!=0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        ans.insert(t);
    }
    return ans.size;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;

        cout<<solve(s)<<"\n";
    }
}
