// Here we have used Binary search to find such values of root for which ax2 + bx +c >=k.
// As maximum value of k is 10^9 so, its root can have maximum value upto 10^5 hence we'll use Binary search
// and keep on dividing the search space every time.
/* https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/monks-encounter-with-polynomial/ */


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

main()
{
    int t,a,b,c,k,res;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>k;
        ll low=0,high=100000,res=-1,mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            ll val=a*(mid*mid) + b*mid +c;
            if(val >=k)
            {
                res=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        cout<<res<<"\n";

    }

}

