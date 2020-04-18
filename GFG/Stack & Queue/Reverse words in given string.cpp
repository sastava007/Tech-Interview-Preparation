#include <bits/stdc++.h>
using namespace std;

stack<string> split(string s, string delim)
{
    stack<string> tokens;
    size_t pos = 0;
    string token;
    
    while ((pos = s.find(delim)) != string::npos) 
    {
        token = s.substr(0, pos);
        tokens.push(token);
        s.erase(0, pos + delim.length());
    }
    tokens.push(s);
    
    return tokens;
}

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        stack<string> tokens = split(s, ".");
        while (!tokens.empty())
        {
            if(tokens.size()!=1)
            cout<<tokens.top()<<".";
            else
            cout<<tokens.top()<<"\n";
            
            tokens.pop();
        }
    }
    
	return 0;
}