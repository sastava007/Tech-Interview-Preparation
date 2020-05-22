/* Simiar to finding subarray with given sum */

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k, i, j;
	    cin>>n>>k;
	    int a[n];
	
	    for(i=0;i<n;i++)
	        cin>>a[i];
	        
	    i = 0, j = 0;
	    
	    int sum = 0;
	    int minlen = INT_MAX;
	    
	    while(i<n && j<n)
	    {
	        sum += a[j++];
	        
	        while(sum>k && i<j)
	        {
	            minlen=min(minlen, j-i);    //here we didn't used j-i+1 becz j is already incremented one position while doing j++
	            sum -= a[i++];
	        }
	    }
	    cout<<minlen<<"\n";
	    
	}
	return 0;
}