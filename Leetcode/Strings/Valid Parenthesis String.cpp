/* 
    Idea is to iterate from L2R and keep the count of unpaired '(', and here we're maintaining lower & upper bound to store range of unpaired numbers.
    So whenever we encounter an '(' we know that both lower & upper value will be incremented and when we encounter ')' we know that we need to decrement both lower 
    and upper bounds.
    But when we encounter '*' we've 3 possible option/ branches consider it as opening bracket and increment, or consider it as closing bracket and decrement. 
    So we know that in such case our lower bound will get decreased and upper bound will get increased.

    Also we know that if our lower bound falls below 0, which means that there are more closing brackets but they can be compensated by '*'

    But if upper bound falls <0, it means it's already invalid, we should return false. Becz this shows that no. of closing brackets is way to greter than opening brackets & 
    even '*' can't compensate for this.

    https://fardolieri.github.io/Valid-Parenthesis-String/
*/

bool checkValidString(string s) 
{
    int lower = 0, upper = 0;
    for(char c: s)
    {
        if(c=='(')
        {
            lower++;
            upper++;
        }
        else if(c==')')
        {
            lower--;
            upper--;
        }
        else
        {
            lower--;
            upper++;
        }
        
        if(lower < 0)   // Whenever lower limit falls below '0' we should force it to be '0' because we never accept negative val during the process.
            lower = 0;
        if(upper < 0)
            return false;
    }
    return lower == 0;
}

/* 
    A brute force way is try all possible 3 options using backracking.
    TC: O(N*3^N) & Space: O(N)
*/