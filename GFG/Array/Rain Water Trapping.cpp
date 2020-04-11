/*  
    Water will be collected b/w two boundaries, so basically we need to find the maximum greater element on left & right for each element 
    and amount of water will be bounded by minimum of two heights - height of building(elevantion).

    But this would require two extra arrays when solved using DP, but can be optimized further using 2 pointers
    https://leetcode.com/articles/trapping-rain-water/ 
*/


#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,j,ans=0;
	    cin>>n;
	    int a[n];
	    for(i=0;i<n;i++)
	        cin>>a[i];
	    int left_max=0, right_max=0;
	    
	    i=0,j=n-1;
	    while(i<=j)
	    {
	        if(a[i]<a[j])
	        {
	            if(a[i]>left_max)
	                left_max=a[i];
	            else
	                ans+=(left_max-a[i]);
	            i++;
	        }
	        else
	        {
	            if(a[j]>right_max)
	                right_max=a[j];
	            else
	                ans+=(right_max-a[j]);
	            j--;
	        }
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}