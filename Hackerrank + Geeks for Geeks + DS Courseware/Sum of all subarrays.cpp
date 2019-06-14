/*
    Find sum of all subarrays
    Note: Subarrays means contigious subarrays and there are n(n+1)/2 subarrays having array of size n
    Geeks for Geeks: https://www.geeksforgeeks.org/sum-of-all-subarrays/
*/

#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,i;
    cin>>n;
    int a[n];
    int ans=0;
    for(i=0;i<n;i++)
       {
           cin>>a[i];
           ans+=a[i]*(n-i)*(i+1);
       }
    cout<<ans;
}
