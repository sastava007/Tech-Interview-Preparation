/*
    https://practice.geeksforgeeks.org/problems/reverse-bits/0
    Instead of obtaining each bit and storing them in array and then reversing, I checked for each of the 32 bit if it is set then simply add it's counter part 
    i.e 2^(31-i) 
    A simple solution with just 32 iterations.
*/

#include <bits/stdc++.h>
#define deb(x) cout<<#x<<" : "<<x<<"\n";
#define ll long long
using namespace std;

int main() 
{   
    int t;
    cin>>t;
    while(t--)
    {
        ll n,i,ans=0;
        cin>>n;
        for(i=0;i<32;i++)
        {
            // deb(i);
            if(n&1)
            {
                ll temp = (1ll)<<(31-i);
                // deb(temp);
                ans = ans + temp;
                // deb(ans);
            }
            n=(n>>1);
            // deb(n);
        }
        cout<<ans<<"\n";
    }
	return 0;
}