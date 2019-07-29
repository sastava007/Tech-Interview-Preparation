#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int i;
        cin>>s;
        int n=s.length();
        int c[n+1];
        for(i=1;i<=n;i++)
                c[i]=c[i-1]+s[i-1]-'0';

        int ans=0;
        for(i=0;i<n;i++)
        {
            int x=1;
            while((x*x+x+i)<=n)
            {
                if((c[x*x+x+i]-c[i])==x)
                    ans++;
                x++;
            }
        }
        cout<<ans<<"\n";

    }
}
