#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,q,i,flag=0;
    int a,x,b=-1;
    cin>>n>>q;
    int s[n];
    for(i=0;i<n;i++)
    cin>>s[i];
    while(q--)
    {
        flag=0;
        cin>>a>>x;
        if(a==0)
        cin>>b;

       if(a==0)
       s[x-1]=b;
       else if(a==1)
        {
            for(i=0;i<n;i++)
            if(s[i]>=x)
            {
                cout<<i+1<<endl;
                flag=1;
                break;
            }
            if(flag==0)
            cout<<"-1"<<endl;
        }
    }
}
