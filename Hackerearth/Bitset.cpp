#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        {
            cin>>a[i];
            bitset<100> b(a[i]);
            cout<<b.count()<<" ";
        }



}

