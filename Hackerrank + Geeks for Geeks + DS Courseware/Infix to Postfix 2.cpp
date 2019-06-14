#include<bits/stdc++.h>
using namespace std;
int prec(char c)
{
    if(c=='^')
        return 3;
    else if(c=='*'||c=='/')
        return 2;
    else if(c=='+'||c=='-')
        return 1;
    else
        return -1;
}

void infix_postfix(string a)
{
    int n=a.length();
    stack<char> s;
    s.push('(');
    string postfix= "";
    int i;
        for(i=0;i<n;i++)
        {
            if(isalpha(a[i]))
                postfix=postfix+a[i];

            else if(a[i]== '(')
                    s.push('(');

            else if(a[i]==')')
            {
                while(s.top()!='(')
                {
                    postfix+=s.top();
                    s.pop();
                }
                s.pop();
            }

            else
            {
                while(prec(s.top()) >= prec(a[i]))
                {
                    postfix= postfix + s.top();
                    s.pop();
                }
                s.push(a[i]);
            }
        }


    while(s.top() != '(')
    {
        char c = s.top();
        s.pop();
        postfix += c;
    }

    cout<<postfix;
}

    int main()
    {
      string a="a+b*(c^d-e)^(f+g*h)-i";
     infix_postfix(a);
     return 0;
    }
