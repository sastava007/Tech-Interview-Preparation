#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,s1=0,s2=0;
    cin>>n>>m;
    int a[n],max_sum[n],min_sum[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        max_sum[i]=a[i];
        min_sum[i]=a[i];
    }
    sort(min_sum,min_sum+n);
    sort(max_sum,max_sum+n,greater<int>());
    for(i=0;i<n-m;i++)
    {
        s1+=max_sum[i];
        s2+=min_sum[i];
    }
    cout<<s1-s2;
}
