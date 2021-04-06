/*  
    O(N) time and O(1) space: Idea is to iterate the string two times maintaining the count of opening & closing parenthsesi first pass will remove all the unbalanced closing parenthses
    wheras the second pass will remove all the unbalanced opening parenthesis.

    Input: s = "))(("
    Output: ""

    Input: s = "lee(t(c)o)de)"
    Output: "lee(t(c)o)de",  "lee(t(co)de)" ,  "lee(t(c)ode)"
*/

class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        string temp;
     
        int open=0; 
        for(int i=0; i<s.length(); i++) //this will remove all the exta unbalanced closing brackets
        {
            if(s[i]=='(')
                open++;
            else if(s[i]==')')
            {
                if(open==0)
                    continue;
                open--;
            }
            temp += s[i];
        }
        
        int closed=0;
        string res;
        for(int i=(int)temp.length()-1; i>=0; i--)     //this will remove all the exta unbalanced opening brackets
        {
            if(temp[i]==')')
                closed++;
            else if(temp[i]=='(')
            {
                if(closed==0)
                    continue;
                closed--;
            }
            res += temp[i];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

/* Doing it inplace, using 2 pointers */

string minRemoveToMakeValid(string s)
{
    int i = s.size();
    int balance = 0;
    for (int j = s.size() - 1; j >= 0; j--) {   //remove extra '(' from back to front
        if (s[j] == ')') balance++;
        else if (s[j] == '(') {
            if (balance == 0) continue;
            balance--;
        }
        s[--i] = s[j];      // there might be empty slots in the front.
    }
    int len = 0;
    balance = 0;
    for (; i < s.size(); i++) {         // remove remaining extra ')' from front to back.
        if (s[i] == '(') balance++;
        else if (s[i] == ')') {
            if (balance == 0) continue;
            balance--;
        }
        s[len++] = s[i];    //the second loop fill the empty slots in the front. Then we don't have to move anything, just erase unused at the back.
    }
    s.erase(len);
    return s;
}

/* O(N) time & O(N) Space: Basically the idea is similar to validating parenthesis. And later remove the parenthses which are not valid */

class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        stack<int> todo;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(')   //if opening bracket, then insert it's index into the stack
                todo.push(i);
            else if(s[i]==')')  //if closing bracket, then check whether stack top is also same then pop, it else push() it into the stack
            {
                if(!todo.empty() && s[todo.top()]=='(')
                    todo.pop();
                else
                    todo.push(i);   //put a placeholder like '#' or '*'
            }
            temp += s[i];
        }

        while(!todo.empty())
        {
            s[todo.top()] = '#';
            todo.pop();
        }
        
        string result = "";
        for(char c: s)
            if(c != '#')
                result += c;
        
        return result;
    }
};