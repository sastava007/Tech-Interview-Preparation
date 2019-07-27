/*
*   Let a[i] refers to number of such numbers which ends with 'a', and b[i] refers to number of such numbers which are ending with 'b'
*   So a/b can be appended to a[i] but only a can be appended to b[i]
*   a[i]=a[i-1]+b[i-1] ; b[i]=a[i-1];
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll compute(int n)
{
    ll a[n+1],b[n+1];
	a[1]=b[1]=1;
	for(ll i=2;i<=n;i++)
	{
		a[i]=a[i-1]+b[i-1];
		b[i]=a[i-1];
	}
	return a[n]+b[n];
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        cout<<"#"<<i<<" : "<<compute(n)<<"\n";

    }
}
