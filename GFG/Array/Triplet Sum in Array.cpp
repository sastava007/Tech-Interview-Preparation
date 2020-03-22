/*
    This is a classical problem of two pointer problem applied on sorted array
    But this can also be solved using simply iterating 2 loops and checking for other remaining sum in a hash map.

*/

#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,k;
	    cin>>n>>k;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        bool found=false;
        for(i=0;i<n-2;i++)
        {
            int l=i+1, r=n-1;
            while(l<r)
            {
                if(a[i]+a[l]+a[r] == k)
                {
                    found =true;
                    break;
                }
                else if(a[i]+a[l]+a[r]<k)
                l++;
                else 
                r--;
            }
        }
        
        found?cout<<"1\n":cout<<"0\n";
	}
	return 0;
}