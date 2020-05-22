#include <bits/stdc++.h>
using namespace std;

int main() 
{   
    int t;
    cin>>t;
    while(t--)
    {
        int n, i, j, k;
        cin>>n>>k;
        
        int a[n];
        
        for(i=0; i<n; i++)
            cin>>a[i];
            
        int sum = 0, maxlen = 0;
        unordered_map<int, int> m;
        
        for(i=0; i<n; i++)
        {
            sum += a[i];
            
            if(sum == k)
                maxlen = max(maxlen, i+1);
            
            if(m.find(sum) == m.end())
                m[sum] = i;
                
            if(m.find(sum-k) != m.end())
                maxlen = max(maxlen, i-m[sum-k]);
            
        }
        
        cout<<maxlen<<"\n";
    }
    
	return 0;
}