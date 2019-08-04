#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<<"\n";
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll a[n];
        int i,j,k,c=0;

        for(i=0;i<n;i++)
        cin>>a[i];

        ll xore1=0,xore2=0;
        for(k=0;k<n-1;k++)
        {
        	xore1=0;
        for(i=k;i<n-1;i++)
        {
            xore1^=a[i];
            xore2=0;
            for(j=i+1;j<n;j++)
            {
                xore2^=a[j];
                if(xore1==xore2)
                {
                    c++;
                }

            }
        }
        }
        cout<<c<<"\n";
    }
}
