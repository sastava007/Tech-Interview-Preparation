
/*     Painter Partition Problem using Binary Search, searching for possible solution in given range and then reducing the range after every step to reach the termination
 *     https://practice.geeksforgeeks.org/problems/the-painters-partition-problem/0
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"

bool ifPossible(ll *board, int n, int m, ll cur_min)
{
    ll painter=1,cur_sum=0;
    for(int i=0;i<n;i++)
    {
        if(board[i]>cur_min)
        return false;

        if(cur_sum+board[i]<=cur_min)
            cur_sum+=board[i];
        else
        {
            cur_sum=board[i];
            painter++;
            if(painter>m)
                return false;
        }
    }
    if(painter ==m)
        return true;

}
ll minimumTime(ll *board, int n, int m)
{
    ll low=*max_element(board,board+n),high=0;
    for(int i=0;i<n;i++)
        high+=board[i];

    ll ans=low;
    while(low<=high)
    {
        ll mid=(low+high)/2;

        if(ifPossible(board,n,m,mid))
        {
            ans=mid;
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
    cin.tie(NULL); cout.tie(NULL);
    int k,n;
    cin>>k>>n;
    ll board[n];
    for(int i=0;i<n;i++)
        cin>>board[i];

    cout<<minimumTime(board,n,k);
}
