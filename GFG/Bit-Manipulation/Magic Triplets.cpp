/*
    https://practice.geeksforgeeks.org/problems/magic-triplets/0
*/

#include <bits/stdc++.h>
using namespace std;

int smallerThan(int a[], int val, int i)
{
    int c=0;
    for(int j=0;j<i;j++)
    if(a[j]<val)
    c++;
    return c;
}

int greaterThan(int a[], int val, int i, int n)
{
    int c=0;
    for(int j=i+1;j<n;j++)
    if(a[j]>val)
    c++;
    return c;
}

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,ans=0;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=1;i<n-1;i++)
        {
            ans +=(smallerThan(a,a[i],i)*greaterThan(a,a[i],i,n));
        }
        cout<<ans<<"\n";
    }
	return 0;
}