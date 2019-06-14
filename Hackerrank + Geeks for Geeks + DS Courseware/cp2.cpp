#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,q,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    int nq,c=0;
    cin>>nq;
    sort(a,a+n);
    while(nq--)
    {
        cin>>q;
        c=0;
        if(q>a[n-1])
        {

            cout<<n;
        }
        int m=n/2;
        while(1)
        {
            if(a[m]==q)
            {
                cout<<m;
                break;
            }
        else if(a[m]>q)
           {
               m=(n-m)/2;
           }
        else
            {
                m=(n+m)/2;
            }
        }
    }

}
