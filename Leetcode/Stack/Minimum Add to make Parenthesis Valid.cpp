/*  A string is valid, when it's counter of parenthesis is balanced = 0. And we represent balance of a string as (open_branckets-closing_brackets) and also for every prefix, the opening_brackets 
    should be non negative.

    Here 'open' represents number of extra opening brackets, that requires more closing brackets for getting balanced.
    Similarly 'close' represents number of extra closing brackets, that requires addition of more opening brackets.  

    Ex: "()))(("  O/P = 4
    
  */

class Solution {
public:
    int minAddToMakeValid(string S) {
        int open=0, close=0;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='(')
                open++;
            else
            {
                if(!open)
                    close++;
                else
                    open--;
            }
        }
        return open+close;
    }
};