#include<bits/stdc++.h>
#define ll long long
using namespace std;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,k,i;
    cin>>t;

    while(t--)
    {
        cin>>k;
        ll n=(pow(10,k));
        ll c=1;
        for(i=1;i<=n;i++)
        {
            unordered_set<ll> s;
            ll sum=0,j=i;
            while(j>0 && s.size()<=2)
            {
                ll ele=j%10;
                if(s.find(ele)==s.end())
                    sum+=ele;
                s.insert(ele);
                j/=10;
            }
            ll l=s.size();

            if(((ll)log10(i)+1)==k && sum==9 && l<=2)
            {
                c++;
                cout<<i<<" "<<n-i<<"\n";
            }
            else if(((ll)log10(i)+1)==l && (s.find(0)!=s.end() || s.find(9)!=s.end()) && (sum==0||sum==9))
            {
                c++;
                cout<<i<<" "<<n-i<<"\n";
            }
        }
        cout<<c;
    }


}
