#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"

bool absoluteSum(int i, int n, int *a, int sum)
{
    if(i==n)
    {
        max_sum=max(max_sum,)
        cout<<
    }

    for(int j=i;j<n;j++)
    {
        for(int )
    }

}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int sum=0;
        int a[n];
        for(i=0;i<n;i++)
            {
                cin>>a[i];
                if(i&1)
                    a[i]=1;
            }
        for(i=1;i<n;i++)
        {
           sum+=abs(a[i]-a[i-1]);
        }
        cout<<sum<<"\n";
    }

}
