/* 
1) We first compute maximum sum till every index and store it in an array maxSum[].
2) After filling the array, we use the sliding window concept of size k. Keep track of sum of current k elements. To compute sum of current window, remove first element of previous window and add current element. After getting the sum of current window, we add the maxSum of the previous window, if it is greater than current max, then update it else not.

*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k, i, j;
	    cin>>n;
	    int a[n];
	
	    for(i=0;i<n;i++)
	        cin>>a[i];
	        
	    cin>>k;
	        
	    int maxsum[n], sum = a[0];
	        maxsum[0] = a[0];
	        
	    // maximum sum subarray ending at ith index using Kadane's algorithm
	    for(i=1;i<n;i++)
	    {
	        sum = max(a[i], a[i]+sum);
	        maxsum[i] = sum;
	    }
	    
	    sum = 0;
	    
	    for(i=0;i<k;i++)
	        sum += a[i];
	        
	    int ans = sum;
	    for(i=k; i<n; i++)
	    {
	        //sum of current window
	        sum = sum + a[i] - a[i-k];
	        
	        ans = max({ans, sum, sum+maxsum[i-k]});     //maximum of {prev window, curr window, curr window+prev window} 
	    }
	    
	    cout<<ans<<"\n";    
	}
	
	return 0;
}