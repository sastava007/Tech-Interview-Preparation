/*  
    This problem is similar to Minimum Remove to Make Valid Parenthesis where we've to remove any invalid bracket to get the answer. But here we've to find all such valid valid combination. 
    
    As we need to generate all possible output we will backtrack among all states by removing one opening or closing bracket and check if they are valid if invalid then add the removed bracket back and go for next state. We will use BFS for moving through states, use of BFS will assure removal of.

    Level 0: no bracket removal
    Level 1: 1 bracket removal
    Level 2: 2 bracket removal

    TC: O(2^N) where expression has N parenthesis

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
