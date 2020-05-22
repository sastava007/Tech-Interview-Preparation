/* We can use prefix and suffix arrays for this, but the optimized solution can be made using two variables */

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, ans = -1;
        cin>>n;
        
        ll a[n], sum = 0;
        
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum += a[i];
        }
    
        ll leftsum = 0;
        for(int i=0;i<n;i++)
        {
            sum -= a[i];
            
            if(leftsum == sum)
            {
                ans = i+1;
                break;
            }
            
            leftsum += a[i];
        }
        cout<<ans<<"\n"; 
    }
	return 0;
}