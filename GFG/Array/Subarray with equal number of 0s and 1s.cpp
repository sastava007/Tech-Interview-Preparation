/* The idea is to replace 0 with -1 and then equal number of 0s and 1s in a subarray means zero sum subaray */

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, i;
	    cin>>n;
	    int a[n];
	    
	    unordered_map<int, int> m;
	    int sum = 0, count = 0;
	    
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	        if(a[i]==0)
	            a[i] = -1;
	            
	        sum += a[i];
	        
	        if(sum == 0)
	            count++;
	        
	        if(m.find(sum) != m.end())
	            count += m[sum];
	            
	        m[sum]++;
	    }
	    cout<<count<<"\n";
	    
	}
	return 0;
}

/* Largest subarray with 0s and 1s  */
int maxLen(int a[], int n) 
{
    int i, sum = 0, maxlen = 0;
    unordered_map<int, int> m;
    
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
            sum += -1;
        else
            sum += 1;
            
        if(sum == 0)
            maxlen = max(maxlen, i+1);
            
        if(m.find(sum) != m.end())
            maxlen = max(maxlen, i-m[sum]);
        else
            m[sum] = i;
    }
    
    return maxlen;
}