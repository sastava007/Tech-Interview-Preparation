#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll a[n];
        bool check[n];

        for(i=0;i<n;i++)
            {
                cin>>a[i];
                check[i]=true;
            }
        ll ans=0,c=0;
        for(int i=n-1;i>=1;i--)
        {
            c=0;
            if(check[i])
            for(int j=i-1;j>=0;j--)
            {
                if(a[j]%a[i]==0)
                {
                    c++;
                    check[j]=false;
                }
                ans=max(ans,c);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
