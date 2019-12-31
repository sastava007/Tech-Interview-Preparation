#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"

struct t
{
    ll a,b,c;
    t()
    {
        a=-1,b=-1,c=-1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t,i;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        for(i=0;i<n;i++)
            cin>>arr[i];
        vector<struct t> v(n);

        for(ll i=0;i<min(k,n);i++)
        {
            if((n&1) &&(i==n/2))
            {
                v[i].a=0,v[i].b=0,v[i].c=0;
            }
            else
            {
                v[i].a=arr[i];
                arr[i]=arr[i]^arr[n-(i%n)-1];
                v[i].b=arr[i];
                v[i].c=arr[n-(i%n)-1];
            }
        }

        ll cnt[n]={0},temp1=k/n;
        ll temp2=k%n;
           for(ll i=0;i<min(k,n);i++)
            {
                cnt[i]=temp1;
                if(temp2!=0 && i<=(temp2-1))
                    cnt[i]+=1ll;
                cnt[i]%=3ll;
            }
        for(ll i=0;i<n;i++)
        {
            if(v[i].a!=-1)
            {
                if(cnt[i]==0)
                    cout<<v[i].a<<" ";
                else if(cnt[i]==1)
                    cout<<v[i].b<<" ";
                else
                    cout<<v[i].c<<" ";
            }
            else
                cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

