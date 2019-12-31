
/*       Binary Search || https://www.geeksforgeeks.org/allocate-minimum-number-pages/*/
/*       This solution will give WA on GfG, becz it considers that there exists atleast one solution and it will range b/w [maximum no.of pages - total pages]
 *       For GfG modify the range from [0-total pages] and return -1 if no such distribution is possible
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"

bool ifPossible(ll *a, ll n, ll m, ll cur_min)
{
    ll students=1,cur_sum=0;
    for(ll i=0;i<n;i++)
    {
        if(a[i]>cur_min)
        return false;

        if(cur_sum+a[i]<=cur_min)
        cur_sum+=a[i];
        else
        {
            students++;
            cur_sum=a[i];
            if(students>m)
                return false;
        }
    }
    if(students==m)
        return true;
}

ll readPages(ll *a, ll n, ll m)
{
    ll low=a[n-1];      // There should be
    ll high=0;

    for(ll i=0;i<n;i++)
        high+=a[i];
    ll ans=LLONG_MAX;

    while(low<=high)
    {
        ll mid=(low+high)/2;
        if(ifPossible(a,n,m,mid))
           {
                ans=min(ans,mid);
                high=mid-1;
           }
           else
            low=mid+1;
    }
    return ans;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,i;
    cin>>n>>m;
    ll a[n];
    for(i=0;i<n;i++)
        cin>>a[i];

    cout<<readPages(a,n,m);
}
