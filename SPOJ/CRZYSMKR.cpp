
/*    Note: (34^n)%11 always yields 1*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll temp=(30*n)%11;
        if(temp==0)
            cout<<"0\n";
        else
        cout<<11-temp<<"\n";
    }
}
