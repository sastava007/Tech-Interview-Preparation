#include<bits/stdc++.h>
#define ll long long unsigned
using namespace std;
main()
{
    int n,i,j,c=0;
    cin>>n;
    long long int a[n];
    unordered_set<ll int> s;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        s.insert(a[i]);
    }
    int dist=s.size();
    for(i=0;i<n;i++)
    {
        s.clear();j=i;
        while(s.size()!=dist&&j<n)
        {
            s.insert(a[j]);
            j++;
        }
        if(j!=n)
        c+=(n-j+1);
    }
    cout<<c;
}
