#include<bits/stdc++.h>
using namespace std;

void generateParentheses(int open, int close, int n, string s)
{
	if(open==n && close==n)
	{
		cout<<s<<"\n";
		return;
	}
	if(open<n)
    generateParentheses(open+1,close,n,s+"(");
	if(close<open)
	generateParentheses(open,close+1,n,s+")");
}

main()
{
	int n;
	cin>>n;
	generateParentheses(0,0,n,"");
}
