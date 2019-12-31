#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"

bool islesser(int *a, int x, int y)
{
    for(int i=x;i<y;i++)
        if(a[i]<=a[y])
        return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n;
    cin>>t;
    while(t--)
    {
        int ans=1;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];

        for(int i=1;i<n;i++)
        {
            if(islesser(a,max(0,i-5),i))
                ans++;
        }
        cout<<ans<<"\n";
    }

    return 0;
}

