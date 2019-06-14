#include <bits/stdc++.h>
using namespace std;
string p;
int prec(char c)
{
    if(c=='^')
        return 3;
    else if(c=='*'||c=='/')
        return 2;
    else if(c=='+'||c=='-')
        return 1;
    else
        return 0;
}
int is_operator(char symbol)
{
    if(symbol=='^' || '+' || '-' || '*' || '/')
        return 3;
    else if(symbol=='(')
        return 2;
    else if(symbol==')')
        return 1;
    else
        return 0;
}

string infix_postfix(string a)
{
    int i=0,j=0;

    stack<char> s;
    a = '(' + a + ')';
    for(int i=0;i<a.length();i++)
    {
        if(is_operator(a[i])==0)
          {
              p+=a[i];
          }
        else if(is_operator(a[i])==2)
            s.push(a[i]);
        else if(is_operator(a[i])==3)
        {
            while(prec(s.top())>=prec(a[i]))
            {
                p+=s.top();
                s.pop();
            }
            s.push(a[i]);
        }
        else if(is_operator(a[i])==1)
        {
            while(s.top()!='(')
            {
                p+=s.top();
                s.pop();
            }
            s.pop();
        }
    return p;
    }

}
main()
{
    string a="A+((B+C)+(D+E)*F)/G";
    cout<<infix_postfix(a);
    //cout<<p;
}
