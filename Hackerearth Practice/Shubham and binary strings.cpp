#include<bits/stdc++.h>
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t,l,n;

    cin>>t;
    while(t--)
    {
        cin>>l;
        char s[l+1];
        cin>>s;
        n=atoi(s);
        cout<<"\n"<<n;
        cout<<"\n"<<__builtin_popcount(n);
    }
}
