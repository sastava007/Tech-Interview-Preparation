/*  The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero. 
    Intution is similar to converting, as we evaluate expression using stack i.e we can is current element isdigi then convert it to a valid number, and record the operator. Here we are dellaying
    the insertion by one step, I mean let's consider an example "3*2-1". So here we first get 3, but we won't insert it into the stack, untill we get some operator to work upon. And when we encounter a operator, first we process the last operator that we've encountered till yet, and recors our current operator for next cycle. 

    PS: the check for last element of string is made using i==s.size()-1

*/

class Solution {
public:
    int calculate(string s) 
    {
        long num=0;
        char sign='+';
        
        stack<long> stk;
        
        for(int i=0; i<s.size(); i++)
        {
            if(isdigit(s[i]))
                num = num*10 + s[i]-'0';
            if((!isdigit(s[i]) && !isspace(s[i])) || i==s.size()-1)
            {
                if(sign=='+')
                    stk.push(num);
                else if(sign=='-')
                    stk.push(-num);
                else if(sign=='*')
                {
                    long temp = stk.top()*num;
                    stk.pop();
                    stk.push(temp);
                }
                else if(sign=='/')
                {
                    long temp = stk.top()/num;
                    stk.pop();
                    stk.push(temp);
                }
                sign=s[i];
                num = 0;
            }
        }
        
        long result=0;
        while(!stk.empty())
        {
            result += stk.top();
            stk.pop();
        }
        
        return result;
    }
};