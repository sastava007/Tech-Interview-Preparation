#include<bits/stdc++.h>
using namespace std;
main()
{
    int t,n,k,max,dif,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        long long int a[n],b[n],s=0;
        max=0;
        for(i=0;i<n;i++)
        cin>>a[i];
        for(i=0;i<n;i++)
        cin>>b[i];
        for(i=0;i<n;i++)
        {
            if(a[i]<b[i])
                if(b[i]>max)
                max=b[i];
        }
        max=max+1;
        for(i=0;i<n;i++)
        {
            if(a[i]<max)
            s+=(max-a[i])*k;
        }
        cout<<s<<endl;

    }
}
