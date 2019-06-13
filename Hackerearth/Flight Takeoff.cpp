#include<bits/stdc++.h>
using namespace std;
int find(int a,int b,int n)
{
    int c=0;
    if(a%b==0||b%a==0)
        c=a%b==0?a/b:b/a;
    else if(a*b<=n)
        c++;
    return c;
}
main()
{
    int t,c,n,p,q,r;
    cin>>t;
    while(t--)
    {

        cin>>n>>p>>q>>r;
        c=0;
        if(p==q||q==r||r==p)
        {
            cout<<"0"<<endl;
        }
        else{
            int tot=n/p+n/q+n/r;
        c+=find(p,q,n);
        c+=find(q,r,n);
        c+=find(r,p,n);
        cout<<tot-2*c<<endl;
        }
    }
}
