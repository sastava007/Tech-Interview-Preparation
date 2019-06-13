#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll power(ll A,ll B,int C)
{
	// Base cases
	if (A == 0)
		return 0;
	if (B == 0)
		return 1;

	// If B is even
	ll y;
	if (B % 2 == 0) {
		y = power(A, B / 2, C);
		y = (y * y) % C;
	}

	// If B is odd
	else {
		y = A % C;
		y = (y * power(A, B - 1, C) % C) % C;
	}

	return (ll)((y + C) % C);
}
main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		ll a,b;
		cin>>a>>b;
		ll ans=power(a,b,10);
		cout<<ans<<"\n";
	}


}
