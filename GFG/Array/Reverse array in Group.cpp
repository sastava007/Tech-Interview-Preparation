/*
    https://practice.geeksforgeeks.org/problems/reverse-array-in-groups/0
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,i;
        cin>>n>>k;
        ll a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
            
        for(i=0;i<n;i+=k)
        {
            int l=i, r= min(i+k-1,n-1);
            while(l<r)
            swap(a[l++], a[r--]);
        }
        for(i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }
	return 0;
}