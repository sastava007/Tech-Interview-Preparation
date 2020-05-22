/* ALgorithm
    1.transepose the matrix.
    2.reverse every row
 */

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, i, j;
	    cin>>n;
	    
	    int a[n][n];
	     
	    for(i=0;i<n;i++)
	        for(j=0;j<n;j++)
	            cin>>a[i][j];   
	            
	    for(i=0;i<n;i++)
	        for(j=i;j<n;j++)
	            swap(a[i][j], a[j][i]);     //transpose of matrix
	            
	    for(i=0;i<n;i++)
	    {
	        int l = 0, r = n-1;
	        while(l<r)
	            swap(a[i][l++], a[i][r--]);     //reverse the row
	    }
	    
	    for(i=0;i<n;i++)
	        for(j=0;j<n;j++)
	            cout<<a[i][j]<<" ";
	    cout<<"\n";
	
	}
    return 0;
}