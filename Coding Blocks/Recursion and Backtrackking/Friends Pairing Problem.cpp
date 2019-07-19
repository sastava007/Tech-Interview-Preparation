/*
*   Let f(n) represent the no of ways in which nth person can be paired up or remain single
*   case 1: if nth person wants to remain single then he have just 1 choice and remaining (n-1) ppl can be paired up or remain single in f(n-1) ways. SO total for this case: 1*f(n-1)
*   case 2: if nth person want to pair up then he can pair up with any of the (n-1) ppl AND rest (n-2) ppl can be paired up or remain single in f(n-2) ways so total for this case: (n-1)*f(n-2)
*   So total solu: f(n)= 1*f(n-1) + (n-1)*f(n-2)
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll friendPairing(int n)
{
    ll dp[n+1];
    dp[0]=0;dp[1]=1;dp[2]=2;
    for(int i=3;i<=n;i++)
        dp[i]=dp[i-1]+(i-1)*dp[i-2];

    return dp[n];
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
        cout<<friendPairing(n)<<"\n";
    }
}

