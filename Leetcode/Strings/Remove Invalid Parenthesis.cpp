/* 
    So instead of trying to remove each opening/closing parenthesis we can do a much clever way, if we just take maintain the number of unbalanced extra set of opening & closing brackets  
    Let's say if we've a string comprising of 1000 characters, and which has just 3 unbalanced opening brackets & 2 unbalanced closing brackets, So instead of checking for all of them
    if we just remove this 5 brackets somehow then we're all set. 

    Okay, idea is to first find the no. of extra opening & closing brackets and using that data recursively call our method. We'll add our expression when no. of remaining opening
    & closing brackets becomes zero, which means that we've removed all unwanted brackets.

    Here also the worst case TC will be when "(((((((" here left_rem = len(S), so we've to remove all of the brackets (2^N)
    Space: O(N) becz we'll go to maximum recursion depth of N before we hit the base case

*/
class Solution { 
public:
    vector<string> removeInvalidParentheses(string s) 
    {   
        vector<string> result;
        int left = 0, right = 0;
        for(char c: s)
        {
            if(c=='(')
                left++;
            else if(c==')')
            {
                if(left == 0)
                    right++;
                else
                    left--;
            }
        }
        unordered_set<string> res;
        recurse(s, 0, 0, 0, left, right, "", res);
        
        result.insert(result.end(), res.begin(), res.end());
        return result;
    }
private:
    void recurse(string s, int index, int leftCount, int rightCount, int leftRem, int rightRem, string exp, unordered_set<string> &res)
    {
        if(index == s.length()) //base case
        {
            if(leftRem==0 && rightRem==0)
                res.insert(exp);
        }
        else
        {
            if(s[index]=='(' && leftRem>0 || s[index]==')' && rightRem>0)   //if we've some remaing extra set of brackets to delete
                recurse(s, index+1, leftCount, rightCount, leftRem - (s[index]=='('?1:0), rightRem - (s[index]==')'?1:0), exp, res);
            
            exp += s[index];
            
            if(s[index]!='(' && s[index]!=')')  // if it's not a character
                recurse(s, index+1, leftCount, rightCount, leftRem, rightRem, exp, res);
            else if(s[index] == '(')
                recurse(s, index+1, leftCount+1, rightCount, leftRem, rightRem, exp, res);
            else if(rightCount < leftCount)
                recurse(s, index+1, leftCount, rightCount+1, leftRem, rightRem, exp, res);
        }
    }
};



/*  
    As we need to generate all possible output we will backtrack among all states by removing one opening or closing bracket and check if they are valid. If found valid on the current level, we add it to the final result and we're done. If invalid then add the removed bracket back and go for next state. We will use BFS for moving through states, use of BFS will assure removal of minimum brackets.

    The idea is straightforward, with the input string s, we generate all possible states by removing one ( or ), check if they are valid, if found valid ones on the current level, put them to the final result list and we are done, otherwise, add them to a queue and carry on to the next level.

    Level/layer 0: no bracket removal
    Level/layer 1: 1 bracket removal
    Level/layer 2: 2 bracket removal

    TC: O(N* 2^N) where expression has N parenthesis, as for for each bracket we can either pick it or drop it, and there are total 2^N states and checking each state will take another N time
    Space: O(2^N)

    Worst Case: "((((((((((" all opening
*/

class Solution {
    
private:
bool isBalanced(string s)
{
    int open=0;
    for(char c: s)
    {
        if(c=='(')
            open++;
        else if(c==')')
            open--;
        if(open<0)
            return false;
    }
    return (open==0);
}
    
public:
    vector<string> removeInvalidParentheses(string s) 
    {
        vector<string> res;
        unordered_set<string> vis;
        queue<string> q;
        
        q.push(s);
        vis.insert(s);
        
        bool flag=false;
        while(!q.empty())
        {
            string str = q.front();
            q.pop();
            if(isBalanced(str))
            {
                res.push_back(str); 
                flag=true;   // If answer is found, make level true so that valid string of only that level are processed. 
                            // IF current string is valid, then we don't need to go to further levels i.e remove any brackets
            }
            if(flag==true)
                continue;
            
            for(int i=0; i<str.length(); i++)
            {
                if(str[i]!='(' && str[i]!=')')
                    continue;   
                string temp = str.substr(0,i)+str.substr(i+1);  //remove the ith bracket it could be opening/closing
                if(vis.find(temp)==vis.end())
                {
                    q.push(temp);
                    vis.insert(temp);
                }
            }
        }
        return res;
    }
};
