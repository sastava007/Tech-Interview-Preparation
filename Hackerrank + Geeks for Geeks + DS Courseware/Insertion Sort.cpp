#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,i,value,hole;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=1;i<n;i++)
    {
        value=a[i];
        hole=i;
        while(hole>0 && a[hole-1]>value)
        {
            a[hole]=a[hole-1];
            hole=hole-1;
        }
        a[hole]=value;
    }
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}
