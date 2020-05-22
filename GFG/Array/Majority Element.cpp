/* Moore's Voting Algorithm */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);

int getMajor(ll *a, ll n)
{
    int major = 0;
    int count = 1;
    
    for(int i=1;i<n;i++)
    {
        if(a[major]==a[i])
            count++;
        else
            count--;
        if(count==0)
        {
            major = i;
            count = 1;
        }
    }
    return major;
}

bool verify(ll *a, ll n, int major)
{
    int count = 0;
    for(int i=0;i<n;i++)
        if(a[i]==a[major])
            count++;
    
    return (count>n/2);
}

int main()
{
    int t,i;
    cin>>t;
    while (t--)
    {
        ll n, i;
        cin>>n;
        ll a[n];
        
        for(i=0;i<n;i++)
            cin>>a[i];
        
        int major = getMajor(a, n);
        if(verify(a, n, major))
            cout<<a[major]<<"\n";
        else
            cout<<"-1\n";
        
    }
    
    return 0;
}