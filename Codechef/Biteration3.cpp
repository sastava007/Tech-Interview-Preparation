#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,x;
        cin>>n;
        double c[n];
        for(i=0;i<n;i++)
            cin>>c[i];
        cin>>x;
        double a[n],b[n];
        for(i=0;i<n;i++)
        {
            if(i==0)
            {
                a[i]=c[i]/x;
                b[n-i-1]=c[n-i-1];
            }
            else
            {
                a[i]=c[i]/x+a[i-1];
                b[n-i-1]=c[n-i-1]+b[n-i];
            }
        }

        ll a_box=0,b_box=0;

        for(i=0;i<n;i++)
        {
            if(i!=0 && i!=(n-1))
            {
                if(a[i-1]==b[i+1])
                {
                    if(a_box>=b_box)
                        a_box++;
                    else
                        b_box++;
                }
                else if(a[i]<b[i])
                a_box++;
                else
                    b_box++;
            }
            else if(a[i]<b[i])
                a_box++;
            else
                b_box++;
        }
        cout<<a_box<<" "<<b_box<<"\n";

//        for(i=0;i<n;i++)
//        {
//            cout<<a[i]<<" ";
//
//        }
//        cout<<"\n\n";
//        for(i=0;i<n;i++)
//        {
//            cout<<b[i]<<" ";
//
//        }

    }

}
