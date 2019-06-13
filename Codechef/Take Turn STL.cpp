#include<bits/stdc++.h>
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n],b[n];
        for(i=0;i<n;i++)
            cin>>a[i];

        for(i=0;i<n;i++)
            cin>>b[i];
            sort(a,a+n);
            sort(b,b+n);

        int c=0,d=0;
        for(i=0;i<(2*n);i++)
        {
            if(i%2==0&&c<n)
            cout<<a[c++]<<" ";
            else
            cout<<b[d++]<<" ";

        }
    }
}
