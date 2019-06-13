#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll l=stoll(s,nullptr,2);
        cout<<__builtin_popcountll(l)<<"\n";
    }
}
