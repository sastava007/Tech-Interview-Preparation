#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(int *a,int n)
{
    ll range=(1<<n);
    ll max_oxa=0,i;
    for(i=1;i<range;i++)
    {
        ll j=i,oxa=0,idx=0;
        int rot=0;
        while(j>0)
        {
            if(j&1)
            {
               if(rot==0)
               oxa|=a[idx];
               else if(rot==1)
               oxa^=a[idx];
               else
               oxa+=a[idx];
               rot=(rot+1)%3;
            }
            j=j>>1;
            idx++;
        }
        max_oxa=oxa>max_oxa?oxa:max_oxa;
    }
    return max_oxa;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t,i,n;
    cin>>t;
    string pred;
    while(t--)
    {
        cin>>pred;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
        cin>>a[i];
        ll max_oxa;
        max_oxa=solve(a,n);
        cout<<max_oxa<<"\n";

//        if((max_oxa%2!=0) && (pred=="Odd") || (max_oxa%2==0) && (pred=="Even"))
//        cout<<"Monk\n";
//        else
//        cout<<"Mariam\n";
    }
}
