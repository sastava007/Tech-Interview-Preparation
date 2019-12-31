#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,i,j;
    cin>>n;
    ll a[n],pre[n],suf[n],sum=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(i!=0)
            pre[i]=pre[i-1]+a[i];
        else
            pre[i]=a[i];
        sum+=a[i];
    }
    vector<int> v;
    for(i=n-1;i>=0;i--)
    {
        if(i!=n-1)
            suf[i]=suf[i+1]+a[i];
        else
            suf[i]=a[i];
    }

    for(i=0;i<n;i++)
    if(suf[i]==sum/3)
        v.emplace_back(i);

    ll c=0;
    if(sum%3==0)
    {
        for(i=0;i<n;i++)
            if(pre[i]==sum/3)
            {
               int pos=upper_bound(v.begin(),v.end(),i+1)-v.begin();
               c+=(v.size()-pos);
            }
        cout<<c;
    }
    else
        cout<<"0";
    return 0;
}

