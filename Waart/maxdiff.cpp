#include <bits/stdc++.h> 
using namespace std; 
#define ll long long 

ll maxAbsDiff(ll arr[], ll n) 
{ 
    ll minEle = arr[0]; 
    ll maxEle = arr[0]; 
    for (ll i = 1; i < n; i++) 
    { 
        minEle = min(minEle, arr[i]); 
        maxEle = max(maxEle, arr[i]); 
    } 
  
    return (maxEle - minEle); 
} 
int main() 
{ 
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0; i<n; i++)
            cin>>a[i];

        cout << maxAbsDiff(a, n)<<"\n"; 
    }
    return 0; 
}