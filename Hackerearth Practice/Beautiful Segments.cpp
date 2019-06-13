#include<bits/stdc++.h>
using namespace std;
main()
{
    int t,n,i,j,k,c,flag;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long int a[n];
        for(i=0;i<n;i++)
        cin>>a[i];
        c=0;

        for(i=3;i<n;i+=2)
        {
            for(k=0;k<n;k++)
            {
                flag=0;
                for(j=k;j<=i/2;j++)
                {
                    if(j!=0&&a[j]<a[j-1])
                    {
                        flag=1;
                        break;
                    }
                }
                for(j=i/2;j<i&&flag==0;j++)
                {
                    if(a[j]>a[j-1])
                    {
                        flag=1;
                        break;
                    }
                }

                if(flag==0)
                c++;
            }
        }
        cout<<c<<"\n";
    }


}
