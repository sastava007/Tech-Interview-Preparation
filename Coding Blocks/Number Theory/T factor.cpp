/*
        A perfect square always have odd number of divisors
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isprime(ll n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll sq=(ll)sqrt(n);
        if(sq*sq!=n)
        {
            cout<<"No\n";
        }
        else
        {
            if(isprime(sq))
            cout<<"Yes\n";
            else
            cout<<"No\n";
        }
    }
}
