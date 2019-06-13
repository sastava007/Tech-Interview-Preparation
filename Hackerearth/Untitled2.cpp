#include<bits/stdc++.h>
using namespace std;
main()
{
    long long int n,q,i,j;
    cin>>n;
    long long int a[n],avg[n],k;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(i!=0)
            a[i]+=a[i-1];
    }
    cin>>q;

    for(i=0;i<n;i++)
        avg[i]=a[i]/double(i+1);

    while(q--)
    {
        cin>>k;
        j=lower_bound(avg,avg+n,k)-avg;
        cout<<j<<"\n";
    }

}
