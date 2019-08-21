#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll a[n];
        double sum=0.0;
        for(i=0;i<n;i++)
            {
                cin>>a[i];
                sum+=a[i];
            }
        double mean=sum/n;
        int flag=0;
        for(i=0;i<n;i++)
        {
            if((double)(sum-a[i])/(n-1)==mean)
            {
                flag=1;
                break;
            }

        }
        flag==1?cout<<i+1<<"\n":cout<<"Impossible\n";

    }

}
