#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool isPossible(ll n, ll k)
{
    vector<ll> prime;
    while(n%2==0)
    {
        prime.emplace_back(2);
        n/=2;
    }

    for(ll i=3;i*i<=n;i+=2)
    {
        while(n%i==0)
        {
            prime.emplace_back(i);
            n/=i;
        }
    }

    if(n>2)
        prime.emplace_back(n);

    return ((prime.size()<k)?false:true);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        ll x,k;
        cin>>x>>k;
        if(isPossible(x,k))
        cout<<"1\n";
        else
        cout<<"0\n";
    }

    return 0;
}