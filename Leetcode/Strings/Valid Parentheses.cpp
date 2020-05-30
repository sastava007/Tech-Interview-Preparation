#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool isSame(char x, char y)
    {
        if(x=='(' && y==')')
           return true;
        if(x=='{' && y=='}')
           return true;
        if(x=='[' && y==']')
           return true;
        
        return false;
    }
    
    bool isValid(string s) 
    {
        stack<char> todo;
        
        for(int i=0; i<s.length(); i++)
        {
            if(todo.empty())
                todo.push(s[i]);
            else if(isSame(todo.top(), s[i]))
                todo.pop();
            else
                todo.push(s[i]);
        }
        
        return (todo.size()==0);
    }
};

main()
{
    Solution obj;
    string s;
    cin>>s;
    cout<<obj.isValid(s);

}
