
/*    Find squareroot of a number upto p precision using binary search expected time complexity O(logn+P)*/

#include<bits/stdc++.h>
using namespace std;

float squareroot(int n, int p)
{
    float ans=0;
    float low=0,high=n;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(mid*mid==n)
        {
            ans=mid;
            return ans;
        }

        if(mid*mid<n)
        {
            low=mid+1;
            ans=mid;
        }

        else
        high=mid-1;
    }

    float inc=0.1;
    for(int i=0;i<p;i++)
    {
        while(ans*ans<=n)
        {
            ans+=inc;

        }
        ans-=inc;
        inc/=10;
    }

    return ans;
}
main()
{
    int n,p;
    n=10;
    p=3;
    cout<<squareroot(n,p);

}
