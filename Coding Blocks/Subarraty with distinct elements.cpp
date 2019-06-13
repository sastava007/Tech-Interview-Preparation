#include<bits/stdc++.h>
using namespace std;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n,i,j=0;
    cin>>n;
    long long int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    long long int l=0,mod =1000000007;

    unordered_set<long long int> s;
    for(i=0;i<n;i++)
    {

        while(j<n && s.find(a[j])==s.end())
            {
                s.insert(a[j]);
                j++;
            }
            l+=((j-i)*(j-i+1))/2;
            s.erase(a[i]);

    }
    cout<<l%mod;

}
