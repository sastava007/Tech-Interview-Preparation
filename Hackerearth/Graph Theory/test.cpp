#include<bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(ll i = a; i < b; i++)
#define sz(a) (ll)((a).size())
using namespace std;

main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin>>t;
    while(t--)
    {
        multiset<ll>tree[100009];

        ll k,n;
        cin>>n>>k;
        fr(i,0,n-1)
        {
            ll x,y;cin>>x>>y;
            tree[x].insert(y);
            tree[y].insert(x);
        }


        ll count=0;
        ll visited[100000];

        ll flag=0;
        fr(i,0,k)
        {
            fr(i,1,n+1)
            {
                if(visited[i])
                continue;

                if(sz(tree[i])==1)
                {
                    ll p = *tree[i].begin();
                    tree[p].erase(i);
                    visited[i]=1;
                    count++;
                    if(count==n-1&&i<k-1)
                    {   flag=1;
                        break;
                    }
                }
            }

            if(flag)
            break;
        }

        if(flag) count++;
        cout<<count<<"\n";
    }
    return 0;
}

