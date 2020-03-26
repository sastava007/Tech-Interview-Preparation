// https://practice.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array/0

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,zero=0,x;
	    cin>>n;
	    vector<int> a;
	    for(i=0;i<n;i++)
	    {
	        cin>>x;
	        if(x!=0)
	        a.emplace_back(x);
	        else
	        zero++;
	    }
	    for(i=0;i<zero;i++)
	    a.emplace_back(0);
	    
	    for(i=0;i<n;i++)
	    cout<<a[i]<<" ";
	    
	    cout<<"\n";  
	}
	
	return 0;
}