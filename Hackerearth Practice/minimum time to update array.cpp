#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    long long int n,k,i;
    while(t--)
    {
        cin>>n>>k;
        long long int a[n],min=1e6+1;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]<min)
            min=a[i];
        }
        cout<<k-min<<endl;
    }
    return 0;
}

