#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
using namespace std;

bool isBalanced(char x, char y)
{
    return (x=='(' && y==')');
}

int main() 
{
    IOS;
    
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    
	    stack<pair<char,int>> st;
	    int c=1;
	    for(int i=0;i<s.length();i++)
	    {
	        if(s[i]=='(' || s[i]==')')
	        {
	            if(st.empty())
	            {
	                st.push({s[i],c});
	                cout<<c<<" ";
	                c++;
	            }
	            else if(isBalanced(st.top().first,s[i]))
	            {
	                cout<<st.top().second<<" ";
	                st.pop();
	            }
	            else
	            {
	                st.push({s[i],c});
	                cout<<c<<" ";
	                c++; 
	            }
	        }
	    }
	    cout<<"\n";
	}
	return 0;
}