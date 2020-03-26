// https://practice.geeksforgeeks.org/problems/minimum-indexed-character/0/

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t,i;
	cin>>t;
	while(t--)
	{
	    string a,b;
	    char ans ='$';
	    cin>>a>>b;
	    int min= INT_MAX;
	    unordered_map<char, int> m;
	    for(i=0;i<a.length();i++)
	        if(m.find(a[i])==m.end())
	        m[a[i]]=i;
	        
	    for(i=0;i<b.length();i++)
	       if(m.find(b[i])!=m.end() && m[b[i]]<min)
	       {
	           min=m[b[i]];
	           ans = b[i];
	       }
	       cout<<ans<<"\n";
	}
	
	return 0;
}