#include<bits/stdc++.h>
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t,i,j,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int a[n];
        for(i=0;i<n;i++)
        cin>>a[i];

        vector<int> v;
        int sum;

        for(i=0;i<n;i++)
        {
            sum=0;
            for(j=i;j<(i+k);j++)
            sum+=a[j%n];
            cout<<sum<<"\n";
            v.emplace_back(sum);

        }

        cout<<"\n\n";
        int min_ele=*min_element(v.begin(),v.end());
        cout<<min_ele<<"\n\n";
        for(auto it:v)
        cout<<it<<" ";
        //cout<<count(v.begin(),v.end(), min_ele)<<"\n";

    }

}
