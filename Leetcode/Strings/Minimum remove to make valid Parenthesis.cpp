/*  O(N) time and O(1) space: Idea is to iterate the string two times maintaining the count of opening & closing parenthsesi first pass will remove all the unbalanced closing parenthses
    Wheras the second pass will remove all the unbalanced opening parenthesis.
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


/* O(N) time & O(N) Space: Basically the idea is similar to validating parenthesis. And later remove the parenthses which are not valid */

class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        stack<int> todo;
        string temp;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(')   //if opening bracket, then insert it's index into the stack
                todo.push(i);
            else if(s[i]==')')  //if closing bracket, then check whether stack top is also same then pop it else push() it into the stack
            {
                if(!todo.empty() && s[todo.top()]=='(')
                    todo.pop();
                else
                    todo.push(i);   //put a placeholder like '*' or 'A'
            }
            
            temp += s[i];
        }
        
        while(!todo.empty())    //remove the parenthesis which are not valid
        {
            temp.erase(todo.top(), 1);  //this one could take linear time, so instead of erasing put a placeholder at not balanced values and later delete them
            todo.pop(); 
        }
        
        return temp;
    }
};