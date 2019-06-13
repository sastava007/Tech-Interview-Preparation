#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,k,i;
    cin>>n>>k;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=0;i<=n-k;i++)
    cout<<*max_element(a+i,a+i+k)<<" ";
}
