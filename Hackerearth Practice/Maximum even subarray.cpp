#include<bits/stdc++.h>
using namespace std;
main()
{
    int t,n,i,c=0,max=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        max=0,c=0;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        if(a[0]%2==0)
            c++;
        for(i=1;i<n;i++)
        {
            if(a[i-1]%2==0)
                c=c;
            else
                c=0;
            if(a[i]%2==0)
            {
                c++;
                if(c>max)
                    max=c;
            }
        }
        cout<<max<<endl;
    }
}
