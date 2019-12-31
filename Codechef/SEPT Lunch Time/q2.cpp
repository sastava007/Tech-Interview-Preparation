#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n,i,j,q;
    cin>>t
    while(t--)
    {
        cin>>n>>q;
        int b[n-1];
        int sum[n-1];

        for(i=0;i<n-1;i++)
            {
                cin>>b[i];
                if(i==0)
                    sum[i]=b[i];
                else
                    sum[i]=sum[i-1]+b[i];
            }

        int p,q;
        while(q--)
        {
            cin>>p>>q;
            int a=min(p,q);
            int b=max(p,q);
            if(b-a==1)
                cout<<b[a-1]<<"\n";


        }


    }
}

