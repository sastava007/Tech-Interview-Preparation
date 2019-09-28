
/*     Agressive Cows Problem: https://www.spoj.com/problems/AGGRCOW/
 *     Approach: Place the first cow at a[0] and then check if it possible to place the other cows at a distance of >=(pos+mid) using lower_bound
 *                 ifPossible() then change low=mid+1 as it would also be possible for all values lying in left part, else high=mid-1, as if it's not
 *                 possible to place the cows at distance mid then it will also not be placed at greater than mid
 */


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"

bool ifPossible(int low,int high, int *a, int n, int cows)
{
    int c=1,pos=a[0];
    int mid=(low+high)/2;
    for(int i=1;i<cows;i++)
    {
        int dist=lower_bound(a,a+n,pos+mid)-a;
        if(dist!=n)
        {
            c++;
            pos=a[dist];
        }
        if(c==cows)
            return true;
        if(dist==n)
            return false;
    }
}
int solve(int *a, int n, int cows)
{
    int low=0,high=a[n-1];
    int ans=0;

    while(low<=high)
    {
        int mid=(low+high)/2;
        if(ifPossible(low,high,a,n,cows))
        {
            ans=mid;
            low=mid+1;
        }
        else
            high=mid-1;
        ifPossible(low,high,a,n,cows);

    }
    return ans;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i;
    cin>>t;
    int n, cows;
    while(t--)
    {
        cin>>n>>cows;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        cout<<solve(a,n,cows);
    }

}
