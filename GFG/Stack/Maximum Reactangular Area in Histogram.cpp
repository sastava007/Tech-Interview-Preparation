#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);

int main()
{
    // IOS;
    int t,i;
    cin>>t;
    while (t--)
    {
        int n,i;
        cin>>n;
        ll a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        stack<int> s, s2;
        vector<int> nsl(n),nsr(n);

        //finding nearest smaller to left
        for(i=0;i<n;i++)
        {
            if(s.empty())
                nsl[i]=-1;
            else if(a[s.top()]<a[i])
                nsl[i]=s.top();
            else
            {
                while (!s.empty() && a[s.top()]>=a[i])
                    s.pop();
                if(s.empty())
                    nsl[i]=-1;
                else
                    nsl[i]=s.top();
            }
            s.push(i);
        }
        // finding nearest smaller element to right
        for(i=n-1;i>=0;i--)
        {
            if(s2.empty())
                nsr[i]=n;
            else if(a[s2.top()]<a[i])
                nsr[i]=s2.top();
            else
            {
                while (!s2.empty() && a[s2.top()]>=a[i])
                    s2.pop();
                if(s2.empty())
                    nsr[i]=n;
                else
                    nsr[i]=s2.top();
            }
            s2.push(i);
        }
            
        ll ans=0;
        for(i=0;i<n;i++)
            ans=max<ll>(ans, a[i]*(nsr[i]-nsl[i]-1));
        cout<<ans<<"\n";
    }
    
    return 0;
}