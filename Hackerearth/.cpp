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
        int low=0,high=100000,res=-1,mid;
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

