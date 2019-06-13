#include<bits/stdc++.h>
using namespace std;
#define ll long long

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t,i;
    cin>>t;
    int z,n;
    while(t--)
    {
        cin>>z>>n;
        ll a[n];

        for(i=0;i<n;i++)
        {
            cin>>a[i];
            z&=a[i];
        }
        if(z)
        cout<<"No\n";
        else
        cout<<"Yes\n";

    }
}
