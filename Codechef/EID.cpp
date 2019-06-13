#include<bits/stdc++.h>
using namespace std;
main()
{
    int t;
    cin>>t;
    long long int n,i,min_diff,diff;

    while(t--)
    {
      cin>>n;
        vector<long long int> v(n);
        for(i=0;i<n;i++)
            scanf("%lld",&v[i]);
        sort(v.begin(),v.end());
        min_diff=INT_MAX,diff=INT_MAX;

        for(i=0;i<n-1;i++)
        {
            diff=fabs(v[i]-v[i+1]);
            min_diff=min(min_diff,diff);
        }
        printf("%lld\n",min_diff);

    }

}
