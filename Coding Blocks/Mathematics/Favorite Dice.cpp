/*
                        Similar to Coupon Collector Problem (Mathematical Expectation)

                        Spoj: https://www.spoj.com/problems/FAVDICE/
*/

#include<bits/stdc++.h>
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        double n;
        cin>>n;
        double temp=0,i=0;
        while(i<n)
        {
            temp+=(1/(n-i));
            i++;
        }
        cout<<fixed<<setprecision(2)<<temp*n<<"\n";
    }

}
