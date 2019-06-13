#include<bits/stdc++.h>
using namespace std;
main()
{
    long long int n,i;
    cin>>n;
    long long int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=0;i<n;i++)
    if(a[i]>=*max_element(a+i+1,a+n))
    cout<<a[i]<<" ";

}
