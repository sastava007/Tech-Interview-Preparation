#include<bits/stdc++.h>
using namespace std;
main()
{
    long long int n,q,r,c,s;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        q=n,c=0,r=0,s=0;
        while(q!=0)
        {
            r=q%10;
            s+=r;
            q/=10;
            c++;
        }
        if(s==(c*(c+1)/2))
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;

    }
}
