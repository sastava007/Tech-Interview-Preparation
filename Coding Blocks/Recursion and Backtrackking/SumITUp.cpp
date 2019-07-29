#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<<"\n";

set<vector<int>> ans;
vector<int> v;
bool sumItUp(int i, int n, int *a, int t)
{
    //base case
    int j;
    if(t==0)
    {
        ans.insert(v);
        return false;
    }

    for(j=i;j<n;j++)
    {
        v.emplace_back(a[j]);
        bool canBeCalcu=sumItUp(j+1,n,a,t-a[j]);
        if(canBeCalcu)
            return true;

        t+a[j];
        v.pop_back();
    }
    return false;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int i,n;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    int t;
    cin>>t;
    sort(a,a+n);
    sumItUp(0,n,a,t);
    for(auto it:ans)
        {
            for(i=0;i<it.size();i++)
            cout<<it[i]<<" ";
            cout<<"\n";
        }

}

