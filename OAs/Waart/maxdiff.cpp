#include <bits/stdc++.h> 
using namespace std; 
#define ll long long 

ll getSum(ll bit[], ll index) 
{ 
	ll sum = 0;
	while (index > 0) { 
		sum += bit[index]; 
		index -= index & (-index); 
	} 
	return sum; 
} 

void updateBIT(ll bit[], ll n, ll index, ll val) 
{ 
	while (index <= n) { 
		bit[index] += val;
		index += index & (-index); 
	} 
} 

void convert(ll arr[], ll n) 
{ 
	ll temp[n]; 
	for (ll i = 0; i < n; i++) 
		temp[i] = arr[i]; 
	sort(temp, temp + n); 

	for (ll i = 0; i < n; i++) { 
		arr[i] = lower_bound(temp, temp + n, arr[i]) - temp + 1; 
	} 
} 

ll max_diff(ll arr[], ll n) 
{
	convert(arr, n); 
	ll BIT[n + 1]; 
	for (ll i = 1; i <= n; i++) 
		BIT[i] = 0; 

	ll smaller_right[n], greater_left[n]; 

	for (ll i = n - 1; i >= 0; i--) 
    { 
		smaller_right[i] = getSum(BIT, arr[i] - 1); 
		updateBIT(BIT, n, arr[i], 1); 
	} 

	for (ll i = 1; i <= n; i++) 
		BIT[i] = 0; 

	for (ll i = 0; i < n; i++)
    { 
		greater_left[i] = i - getSum(BIT, arr[i]); 
		updateBIT(BIT, n, arr[i], 1); 
	} 

    ll ans = 0;
    for(ll i=0;i<n;i++)
        ans = max(ans, abs(greater_left[i]-smaller_right[i]));
    return ans;
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

        cout << max_diff(a, n)<<"\n"; 
    }
    return 0; 
}