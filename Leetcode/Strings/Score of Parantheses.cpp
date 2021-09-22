/* 
    () has score 1
    AB has score A + B, where A and B are balanced parentheses strings.
    (A) has score 2 * A, where A is a balanced parentheses string.
*/


/* Using DFS  TC & Space: O(N)*/
int scoreOfParentheses(string s) 
{
    int i = 0;
    return dfs(s, i);
}
int dfs(string s, int &i)
{
    int res = 0;
    while(i<s.size())
    {
        if(s[i++]=='(')   // if it's an opening bracket, then look for next bracket. If that's closing then easy () +1, otherwise it means call for recrusion to compute inner parentheses
        {
            if(s[i]==')')
            {
                res++;
                i++;
            }
            else
            {
                res += 2*dfs(s, i);
            }
        }
        else
            return res;
    }
    return res;
}

/* Using Stack  TC & Space: O(N)*/
int scoreOfParentheses(string s) 
{
    stack<int> todo;
    todo.push(0);
    
    for(char c: s)
    {
        if(c=='(')          // whenever we encounter an opening bracket push a 0
            todo.push(0);
        else                // when we encounter a closing bracket, find what we have at the top of the stack
        {
            int top = todo.top();
            todo.pop();
            
            if(top == 0)                // if top of stack is 0, which means this closing bracket is next to an opening parantheses
                todo.top += 1;          // in such case increment the value at top of stack by 1
            else
                todo.top += 2*top;      // otherwise it means that there's a nesting of parentheses involved
        }
    }
    return todo.top();
}

/* Count the layers: O(1) Space */
int scoreOfParentheses(string s) 
{
    int layer = 0, result = 0;
    
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(')   // when we encounter opening bracket, this means we're entering a new level/ layer so increment the depth
            layer++;
        else            // when we encounter closing bracket this means we're coming out from a layer so decrement the depth
            layer--;
        
        if(s[i]==')' && s[i-1]=='(')   // when we encounter "()", we know that numbers of layer outside covering this. So we can calcuate it's score
            result += (1<<layer);
    }
    return result;
}