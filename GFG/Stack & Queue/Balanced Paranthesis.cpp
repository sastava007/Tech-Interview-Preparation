/*
    https://practice.geeksforgeeks.org/problems/parenthesis-checker/0#_=_
*/

#include <bits/stdc++.h>
using namespace std;

bool isSame(char x, char y)
{
    if(x=='{')
        return y=='}';
    if(x=='(')
        return y==')';
    if(x=='[')
        return y==']';
        
    return false;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int i;
	    string a;
	    cin>>a;
	    stack<char> s;
	    bool balanced;
	    for(i=0;i<a.length();i++)
	    {
            if(s.empty())
            {
               s.push(a[i]);
            }
            else if(isSame(s.top(), a[i]))
               s.pop();
            else 
            s.push(a[i]);
	    }
	    
	    balanced = s.size()==0;
	    balanced?(cout<<"balanced\n"):(cout<<"not balanced\n");
	}
	return 0;
}