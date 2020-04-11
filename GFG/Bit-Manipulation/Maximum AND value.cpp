/*
    We'll get 1 only if both bits are 1, so we start traversing from MSB->LSB and check that whether there are >=2 elements which that position set
    Here imp thing is, mask = ans|(1<<i) which is becz we know that the maximum answer will be when the current bit is set with same elements as the last MSB because
    if all the bits are set for a pair of elements but MSB is unset then also it won't be maximum.

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// #define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);

int main()
{

    // IOS;

    int t;
    cin>>t;
    while (t--)
    {   
        int n,i,j;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        
        int ans=0, mask=0;
        for(i=31;i>=0;i--)
        {
            mask=ans|(1<<i);
            int count=0;
            for(j=0;j<n;j++)
            {
                if((mask & a[j]) == mask)
                    count++;
            }
            if(count>=2)
            ans |= (1<<i);
        }
        cout<<ans<<"\n";
    }
    return 0;
}