#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	string a;
	cin>>t;
	while(t--)
	{
	    cin>>a;
	    int i=0,res;
	    stack<int> s;
	    while(i<a.length())
	    {
	       if(isdigit(a[i]))
	       s.push(a[i]-'0');
	       else
	       {
	           int op2=s.top();
	           s.pop();
	           int op1=s.top();
	           s.pop();
	               if(a[i]=='+')
                    res=op1+op2;
                    else if(a[i]=='-')
                     res=op1-op2;
                     else if(a[i]=='*')
                    res=op1*op2;
                    else if(a[i]=='/')
                    res=op1/op2;

	           s.push(res);
	       }
	       i++;
	    }
	    cout<<s.top()<<endl;
	}
	return 0;
}
