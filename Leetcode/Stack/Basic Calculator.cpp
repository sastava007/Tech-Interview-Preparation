/* 
    Given an expression consisting of only "+/-" sign, evaluate it
    Input: "(1+(4+5+2)-3)+(6+8)"    Output: "23"

    So the idea is to iterate the string from left to right, and keep on evaluating the expression on fly. And whenever we encounter a "(", we push the value obtained so far along 
    with the sign before it. And when we encounter a closing bracket we multiply the value generated so far within the brackets to the sign at the top of the stack and add it to the
    overall result.

*/


int calculate(string s) 
{
    stack<long> stk;
    long result = 0, operand = 0, sign = 1;    // 1 means '+' and -1 means '-'
    
    for(int i=0; i<s.length(); i++)
    {
        if(isdigit(s[i]))
            operand = operand*10 + s[i]-'0';
        else if(s[i]=='+')
        {
            result += sign*operand; // evaluate the expression to the left of this symbol, using operand and sign
            sign = 1;            // save the currently encountered sign
            operand = 0;    // reset the operand to 0
        }
        else if(s[i]=='-')
        {
            result += sign*operand;
            sign = -1;
            operand = 0;
        }
        else if(s[i]=='(')
        {
            stk.push(result);   // push the value evaluated so far
            stk.push(sign);     // also save the sign, in case of 10 - (   ), it's imp to push '-' sign into stack
            
            result = 0;     // as we've pushed the current evaluated expression so far, so reset the reuslt for evaluation inside the bracket
            sign = 1;
        }
        else if(s[i]==')')
        {
            result += sign*operand;     // evalute the value generated so far inside the bracket
            result *= stk.top();    // multiply the value inside the bracket to the sign before the bracket
            stk.pop();
            
            result += stk.top();    // add the value within the brackets to result so far
            stk.pop();  
            
            operand = 0;
        }
    }
    return result + sign*operand;   // for last character
}