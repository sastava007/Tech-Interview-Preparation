#include<bits/stdc++.h>
using namespace std;
main()
{
    int t,n,i,start,k,curr_sum,c;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        long long int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
            start=0,curr_sum=0,c=0;
        for(i=0;i<n;i++)
        {
            curr_sum+=a[i];
            while(curr_sum>=k)
            {
                curr_sum-=a[start++];
                c++;
            }
        }
        cout<<c<<endl;
    }

}

