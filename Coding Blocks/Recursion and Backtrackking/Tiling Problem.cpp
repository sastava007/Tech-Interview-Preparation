/*
    Simple Tiling Problem https://practice.geeksforgeeks.org/problems/number-of-ways
    Using linear DP f(n)=f(n-1)+f(n-4)

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll compute(int n)
{
    ll res[n+1];
    res[1]=1;res[2]=1;res[3]=1;
    res[4]=2;

    if(n<5)
    return res[n];
    for(int i=5;i<=n;i++)
    res[i]=res[i-1]+res[i-4];
    return res[n-1]+res[n-4];
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<compute(n)<<"\n";
    }
}
