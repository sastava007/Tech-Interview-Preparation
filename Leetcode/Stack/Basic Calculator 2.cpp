/*  
    The expression string contains only non-negative integers, +, -, *, / operators and empty spaces. The integer division should truncate toward zero. 
    Intution is similar to converting, as we evaluate expression using stack i.e we can if the current element isdigi then convert it to a valid number, and record the operator. Here we are dellaying the insertion by one step, I mean let's consider an example "3*2-1". So here we first get 3, but we won't insert it into the stack, untill we get some operator to work upon. And when we encounter a operator, first we process the last operator that we've encountered till yet, and record our current operator for next cycle. 

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

/* 
    Without Stack 
    "3-5*2" here when we encounter '*' preval = 3 and currval = 5 so (result += 3 and preval = -3) and this on continue.
*/

public int calculate(String s) 
{
    if (s == null) return 0;
    s = s.trim().replaceAll(" +", "");
    int length = s.length();
    
    int res = 0;
    long preVal = 0; // initial preVal is 0
    char sign = '+'; // initial sign is +
    int i = 0;
    while (i < length) {
        long curVal = 0;
        while (i < length && (int)s.charAt(i) <= 57 && (int)s.charAt(i) >= 48) { // int
            curVal = curVal*10 + (s.charAt(i) - '0');
            i++;
        }
        if (sign == '+') {
            res += preVal;  // update res
            preVal = curVal;
        } else if (sign == '-') {
            res += preVal;  // update res
            preVal = -curVal;
        } else if (sign == '*') {
            preVal = preVal * curVal; // not update res, combine preVal & curVal and keep loop
        } else if (sign == '/') {
            preVal = preVal / curVal; // not update res, combine preVal & curVal and keep loop
        }
        if (i < length) { // getting new sign
            sign = s.charAt(i);
            i++;
        }
    }
    res += preVal;
    return res;
}