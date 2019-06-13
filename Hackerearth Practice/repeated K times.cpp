#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,i,k,c=0;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    cin>>k;
    for(i=0;i<n-1;i++)
    {
        if(i!=0&&a[i]==a[i-1])
        c=c;
        else
        c=1;
        if(a[i]==a[i+1])
        c++;
        if(c==k)
        {
            cout<<a[i];
            break;
        }
    }
}
