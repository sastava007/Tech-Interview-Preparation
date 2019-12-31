#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
        {
            int pos=upper_bound(a,a+n,a[i])-a;
            cout<<n-pos<<" ";
        }
        cout<<"\n";

    }


}
