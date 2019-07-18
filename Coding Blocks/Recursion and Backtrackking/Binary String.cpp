/*
*	Let a[i] represent the no. of such binary strings which don not have any consecutive 1, and ends with 0
*	and b[i] represent the no. of such strings which end with 0. So we can append 0 & 1 to a[i] but only 0 to b[i]
* 	a[i]=a[i-1]+b[i-1] ; b[i]=a[i-1];
*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll binaryString(int n)
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

	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<binaryString(n)<<"\n";
	}
}


/// ANOTHER SOLUTION USING RECURSION, BUT THIS IS GIVING TLE FOR LARGE NUMBERS

/* #include<bits/stdc++.h>
 * using namespace std;
 * #define ll long long
 * #define mod 1000000007
 *
 * ll c=0;
 * bool binaryString(int i, int n, string s)
 * {
 *     if(i==n)
 *     {
 *         c=(c+1)%mod;
 *         // to generate all strings
 *         return false;
 *
 *     }
 *     if(i==0 || s[i-1]!='1')
 *     {
 *         binaryString(i+1,n,s+"1");
 *     }
 *     binaryString(i+1,n,s+"0");
 * }
 * main()
 * {
 * 	ios_base::sync_with_stdio(false);
 * 	cin.tie(0);
 *
 * 	int t,n;
 * 	cin>>t;
 * 	while(t--)
 * 	{
 * 		cin>>n;
 * 		string s="";
 * 		binaryString(0,n,s);
 * 		cout<<c<<"\n";
 * 		c=0;
 * 	}
 * }
 */
