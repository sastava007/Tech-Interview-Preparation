#include<bits/stdc++.h>
using namespace std;
main()
{
    int t,n,k,i,res;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        k++;
        int a[n+1];
        a[0]=0;
        for(i=1;i<n+1;i++)
        {
            cin>>a[i];
            a[i]+=a[i-1];
        }
        sort(a,a+(n+1));
        res=(n+1)*(n+1);
        for(i=0;i<n+1;i++)
        res-=(lower_bound(a,a+n,a[i]+k)-a);
        cout<<res<<endl;
    }
}
