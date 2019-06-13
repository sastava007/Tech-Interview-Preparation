#include<bits/stdc++.h>
using namespace std;
main()
{
    long long int n,i,flag=0;
    cin>>n;
    long long int a[n],s;
    for(i=0;i<n;i++)
    cin>>a[i];
    s=a[0]+a[n-1];
    for(i=1;i<n-1;i++)
    {
        if(a[i]!=s)
        {
            flag=1;
            break;
        }
    }
    if(n!=2&&n!=1)
    {
        if(flag==0)
        cout<<"YES";
        else cout<<"NO";
    }
    else if(n==2&&a[0]==a[1]||n==1&&a[0]==0)
    cout<<"YES";
    else cout<<"NO";
}
