#include<bits/stdc++.h>
using namespace std;
main()
{
    long long int n,i,max;
    cin>>n;
    long long int a[n];
    vector<int>v;
    for(i=0;i<n;i++)
    cin>>a[n-1-i];
    max=a[0];
    for(i=0;i<n;i++)
    if(a[i]>=max)
    {
        max=a[i];
        v.push_back(a[i]);
    }
    for(auto it=v.rbegin();it!=v.rend();it++)
    cout<<*it<<" ";
}
