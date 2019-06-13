#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,i,k=1;
    long long int sum_so_far=0,max_sum=0;
    cin>>n;
    long long int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=0;i<n;i++)
    {
        sum_so_far+=a[i];
        if(sum_so_far<0)
        sum_so_far=0;
        else if(sum_so_far>max_sum)
        {
            k=1;
            max_sum=sum_so_far;
        }
        else if(sum_so_far==max_sum)
        k++;
    }
    if(max_sum>0)
    cout<<max_sum<<" "<<k;
    else
    cout<<"0"<<" "<<k-1;
}
