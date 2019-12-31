#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m,q;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>q;
        ll row[n+1]={0},col[m+1]={0};
        while(q--)
        {
            int x,y;
            cin>>x>>y;
            row[x]+=1;
            col[y]+=1;
        }
        ll ans=0,odd=0,even=0;
        for(int i=1;i<=m;i++)
            if(col[i]&1)
                odd++;
            else
                even++;

        for(int i=1;i<=n;i++)
        {
            if(row[i]&1)    //if that row is odd, then ans+=no of even column
                ans+=even;
            else
                ans+=odd;
        }
        cout<<ans<<"\n";
    }

    return 0;
}

