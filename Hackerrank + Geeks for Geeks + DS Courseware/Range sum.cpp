#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    ll t,n,i;
    cin>>n;
    vector<ll> v(n),sum(n);

    for(i=0;i<n;i++)
    {
        cin>>v[i];
        if(i!=0)
            sum[i]=sum[i-1]+v[i];
        else
            sum[i]=v[i];
    }
    cin>>t;
    ll l,r,x,op,c=0;
    while(t--)
    {
        cin>>op;
        if(op==1)
            {
                cin>>l>>r;
                if(l>=2)
                cout<<sum[r-1+c]-sum[l-2]<<"\n";
                else
                    cout<<sum[r-1]<<"\n";
            }
        else
            {
                cin>>x;
                c++;
                sum.insert(sum.begin(),x);
            }
    }
}
