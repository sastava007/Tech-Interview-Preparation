#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll power(ll x, ll y, ll p) 
{ 
    ll res = 1; 
    x = x % p;  
  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p; 
    } 
    return res; 
} 
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    
    cin >> t;
    while (t--)
    {
        ll n, mod = 1e9 + 7;
        cin >> n;
        cout << (power(2, n, 1e9 + 7) - 2 + mod)%mod << endl;
    }
    return 0;
}