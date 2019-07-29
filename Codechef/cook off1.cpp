#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n;
    cin>>t;
    while(t--)
    {

        cin>>n;
        string s,r;
        cin>>s>>r;
        int a1=0,a2=0,b1=0,b2=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
                a1++;
            else if(s[i]=='0')
                b1++;

            if(r[i]=='1')
                a2++;
            else if(r[i]=='0')
                b2++;
        }
        if(a1==a2 && b1==b2)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}

