/*
    Find number of subarrays such that the sum of their elements is divisible by N/K depending on question
    Using pigeonhole principle and prefix sum
    https://www.geeksforgeeks.org/count-sub-arrays-sum-divisible-k/
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(x) push_back(x)
main()
{
   ll t,i;
   ll n;
   ios_base::sync_with_stdio(false);
   cin.tie(0);

   cin>>t;
   while(t--)
   {
       cin>>n;
       ll a[n],sum[n+1],fr[n]={0};
       sum[0]=0;

       for(i=0;i<n;i++)
       {
           cin>>a[i];
           sum[i+1]=sum[i]+a[i];
       }

       for(i=0;i<(n+1);i++)
       {
           fr[((sum[i]%n)+n)%n]++;
       }

       ll ans=0;
       for(i=0;i<n;i++)
       {
           ans+=(fr[i]*(fr[i]-1))/2;
        }
       cout<<ans<<"\n";
   }
}

