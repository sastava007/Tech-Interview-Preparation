/*
    https://practice.geeksforgeeks.org/problems/sum-of-xor-of-all-pairs/0
    Similar to Sum of bit difference problem asked in Google TR2, I counted no of set and unset bits and simply multiply them to take total possible pairs
    and later multiply them with their position value i.e (1<<i) which they will contribute to sum.

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);

int main()
{

    IOS;
    int t;
    cin>>t;
    while (t--)
    {
        int n,i,j,ans=0;
        cin>>n;
        int a[n];
        for (i = 0; i < n; i++)
            cin>>a[i];
        for(i=31;i>=0;i--)
        {
            int set_bit=0;
            for(j=0;j<n;j++)
            {
                if(a[j]&(1<<i))
                    set_bit++;
            }
            ans += (set_bit*(n-set_bit)*(1<<i));
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}