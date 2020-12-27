#include <bits/stdc++.h> 
#define ll long long
using namespace std; 

// ll binary_lower(ll value, ll arr[], ll n) 
// { 
// 	ll start = 0; 
// 	ll end = n - 1; 
// 	ll ans = -1; 
// 	ll mid; 

// 	while (start <= end) { 
// 		mid = (start + end) / 2; 
// 		if (arr[mid] >= value) { 
// 			end = mid - 1; 
// 			ans = mid; 
// 		} 
// 		else { 
// 			start = mid + 1; 
// 		} 
// 	} 
// 	return ans; 
// } 

ll countTriplet(ll arr[], ll n, ll k) 
{
	ll count = 0; 
	sort(arr, arr + n); 

	for (ll i = 2; i < n; i++) 
    {
        ll cur = lower_bound(arr, arr+n, arr[i]-k)-arr;
        if(cur==n)
            cur = -1;

		if (cur <= i - 2)
        {
			count += ((i - cur) * (i - cur - 1)) / 2; 
		} 
	} 

	return count; 
} 

int main() 
{ 
	ll t;
    cin>>t;
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        ll a[n];
        for(ll i=0; i<n; i++)
            cin>>a[i];

        cout<<countTriplet(a, n, k)<<"\n";
    }
    
	return 0; 
} 
