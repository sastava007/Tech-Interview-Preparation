/* 
    Bruteforce: We can generate all 2^(2n) sequences of '(' and ')' characters. Then we can check if they're valid or not.

    Backtracking: 
    
    Instead of adding '(' or ')' every time as in Approach 1, let's only add them when we know it will remain a valid sequence. We can do this by keeping track of the number of opening and closing brackets we have placed so far.

    We can start an opening bracket if we still have one (of n) left to place. And we can start a closing bracket if it would not exceed the number of opening brackets. 

    Time Complexity & Space: O(exponential) => Nth catalan number 1/(n+1) 2nCn

*/

class Solution {
public:
    vector<string> generateParenthesis(int n) 
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