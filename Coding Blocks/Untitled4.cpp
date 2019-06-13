#include<bits/stdc++.h>
using namespace std;
#define ll long long
void count_digits(ll n,unordered_set<ll> s)
{
    while(n>0 && s.size()<=2)
    {
        s.insert(n%10);
        n/=110;
    }

}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t,k;
    cin>>t;
    while(t--)
    {
        cin>>k;
        ll c=0;
        ll n=pow(10,k)-1,i;

        for(i=0;i<=n;i++)
        {
            unordered_set<ll> s;
            count_digits(i,s);
            count_digits(n-i,s);
            if((s.size())<=2)
             {
                 cout<<i<<" "<<n-i<<"\n";
             }   c++;
        }
        cout<<c<<"\n";
    }
}
