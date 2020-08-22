/* 
    Bruteforce: We can generate all 2^(2n) sequences of '(' and ')' characters. Then we can check if they're valid or not.

    Backtracking: 
    
    Instead of adding '(' or ')' every time as in Approach 1, let's only add them when we know it will remain a valid sequence. We can do this by keeping track of the number of opening and closing brackets we have placed so far.
    We can start an opening bracket if we still have one (of n) left to place. And we can start a closing bracket if it would not exceed the number of opening brackets. 

    Time Complexity & Space: O(exponential) => Nth catalan number 1/(n+1) 2nCn

*/

class Solution {
public:
    vector<string> generateParenthesis(int n) // here n is the no. of valid pairs of parenthesis
    {
        vector<string> result;
        util(result, "", 0, 0 , n);
        
        return result;
    }
private:
    void util(vector<string> &result, string curr, int open, int close, int max)
    {
        if(curr.length()==max*2)
        {
            result.push_back(curr);
            return;
        }
        
        if(open<max) 
            util(result, curr+"(", open+1, close, max);
        
        if(close<open) 
            util(result, curr+")", open, close+1, max);
    }
};

/* Backtracking One */

class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> combinations = new ArrayList();
        generateAll(new char[2 * n], 0, combinations);
        return combinations;
    }

    public void generateAll(char[] current, int pos, List<String> result) 
    {
        if (pos == current.length)
        {
            if (valid(current))
                result.add(new String(current));
        }
        else
        {
            current[pos] = '(';
            generateAll(current, pos+1, result);
            current[pos] = ')';
            generateAll(current, pos+1, result);
        }
    }

    public boolean valid(char[] current) {
        int balance = 0;
        for (char c: current) {
            if (c == '(') balance++;
            else balance--;
            if (balance < 0) return false;
        }
        return (balance == 0);
    }
}