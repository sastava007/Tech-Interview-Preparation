#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool go(int mp[],int k)
{
    for(int i=0;i<k;i++)
    {
        if(mp[i]==0)
            return false;
    }
    return true;
}

bool check(vector<int> &a,int m,int k)
{
    int mp[1002]={0};
    for(int i=0;i<m-1;i++)
        mp[a[i]]++;
    for(int i=m-1;i<a.size();i++)
    {
        mp[a[i]]++;
        if(go(mp,k))
            return true;
        mp[a[i-m+1]]--;
    }
    return false;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    int low=k,high=n,ans=1e9;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(check(a,mid,k))
        {
            ans=min(ans,mid);
            high=mid-1;
        }
        else
            low=mid+1;
    }
    cout<<(ans==1e9?-1:ans)<<'\n';
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();

    return 0;
    
}