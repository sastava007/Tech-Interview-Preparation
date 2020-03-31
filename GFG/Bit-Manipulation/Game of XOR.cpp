/*
    Simplest approach for this solution
    Here each element will occur (n-1)*(i+1) times in all subarrays. So the element which occur odd number of times will be counted in final XOR else ignore it.
*/


#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,ans=0;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if( ((n-i)*(i+1))&1 )
            ans ^= a[i];
        }
        cout<<ans<<"\n";
    }
	return 0;
}