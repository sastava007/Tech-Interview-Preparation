/*
    https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0
    Approach: Idea is to make a suffix array which stores the maximum element upto index i from back side. So if element is greater than the maximum element
     in suffix array then it must be greater than all other elements also. 
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        ll a[n],maxi[n];
        for(i=0;i<n;i++)
        cin>>a[i];
        
        maxi[n-1]=a[n-1];
        for(i=n-2;i>=0;i--)
            maxi[i]=max(a[i],maxi[i+1]);
        for(i=0;i<n;i++)
        if(a[i]>=maxi[i])
        cout<<a[i]<<" ";
        
        cout<<"\n";
    }
}