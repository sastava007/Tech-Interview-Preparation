#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    int t;
    ll n,i=0,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        string a,b;
        cin>>a>>b;
        ll c=0;

        if(a[0]==b[0])
            c++;
        if(a[1]==b[1] &&(a[0]==b[0] || b[0]=='N'))
            c++;

        for(i=2;i<n-1;i++)
        {
            if(a[i]==b[i] && (a[i-1]==b[i-1] || b[i-1]=='N'))
                c++;
            else if(a[i]==b[i]&&(a[i-2]!=b[i-2] && b[i-2]=='N'))
                c++;
        }
        if(a[n-1]==b[n-1])
            c++;

        cout<<c<<"\n";
    }

}
