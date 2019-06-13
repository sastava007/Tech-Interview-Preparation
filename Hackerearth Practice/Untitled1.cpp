#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,q,k,j;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i!=0)
        a[i]+=a[i-1];

    }
    while(q--)
    {
        cin>>k;
        j=binary_search(a,a+n,k);
        cout<<j+1<<"\n";
    }
}
