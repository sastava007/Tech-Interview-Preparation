#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll setbits=0;

ll set_bits(ll n)
{
    if(n>0)
    {
        setbits++;
        n=n&(n-1);
        set_bits(n);

    }
    else
    return setbits;

}

main()
{
    ll q,a,b,i;
    cin>>q;
    while(q--)
    {
        cin>>a>>b;
        ll ans=0;
        for(i=a;i<=b;i++)
        {
            ans+=set_bits(i);
            setbits=0;
        }
        cout<<ans<<"\n";
    }
}
