#include<bits/stdc++.h>
using namespace std;
main()
{
    int q,n,i,j,x,y;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);

    cin>>q;
    while(q--)
    {
        cin>>x>>y;
        if(x==0)
        {
            j=lower_bound(a,a+n,y)-a;
            if(j!=n)
            cout<<n-j<<"\n";
            else
            cout<<"0\n";
        }
        else if(x==1)
        {
            j=upper_bound(a,a+n,y)-a;
            if(j!=n)
            cout<<n-j<<"\n";
            else
            cout<<"0\n";
        }

    }
}
