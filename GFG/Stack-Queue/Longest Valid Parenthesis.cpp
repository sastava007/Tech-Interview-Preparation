
/*
    Though, their can be various possible solution to this but I solved this by breaking down it into two known classical problems i.e 
    Parenthesis Validation & longest subarray of non-negative integers.

    https://practice.geeksforgeeks.org/problems/longest-valid-parentheses/0 
*/

class Solution {
public:
    
    bool isBalanced(char x, char y)
    {
        return (x=='(' && y==')');
    }
    int longestValidParentheses(string s) 
    {
        vector<int> arr(s.length(), -1);
        stack<pair<char, int>> stk;
        
        for(int i=0; i<s.length(); i++)
        {
            if(s.empty())
                stk.push({s[i], i});
            else if(!stk.empty() && isBalanced(stk.top().first, s[i]))
            {
                arr[i] = 1;
                arr[stk.top().second] = 1;
                stk.pop();
            }
            else
                stk.push({s[i], i});
        }
        
        int ans = 0, counter = 0;
        for(int i: arr)
        {
            if(i==1)
                counter++;
            else
                counter = 0;
            ans = max(counter, ans);
        }
        return ans;
    }
};

/* One more solution without using extra array for storing indices, here we are pushing a extra pair{-1,-1} to build base for our valid substrings */

int main()
{
    int t,i;
    cin>>t;
    while (t--)
    {
        string a;
        cin>>a;

        stack<pair<char, int>> s;
        s.push({-1,-1});

        int max_count=0;

        for(i=0;i<a.length();i++)
        {
            if(s.size()==1)
                s.push({a[i], i});
            else if(isBalanced(s.top().first, a[i]))
            {
                pair<char, int> top = s.top();
                    s.pop();
                if(!s.empty())
                {
                    max_count = max(max_count, i-s.top().second);
                }
                else
                s.push(top);
            }
            else
                s.push({a[i], i});
        }
        cout<<max_count<<"\n";
    }
    return 0;
}

/* Without using Stack, doing a 2 pass */

class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int open = 0, close = 0, maxlength = 0;

        for(int i=0; i<s.length(); i++)     // This will remove all the exta unbalanced closing brackets
        {
            if(s[i]=='(')
                open++;
            else
                close++;
            
            if(open == close)
                maxlength = max(maxlength, open*2);
            else if(close > open)
                open = 0, close = 0;
        }
        
        open = 0, close = 0;
        
        for(int i=s.length()-1; i>=0; i--)  // This will remove all the exta unbalanced opening brackets
        {
            if(s[i]=='(')
                open++;
            else
                close++;
            
            if(open == close)
                maxlength = max(maxlength, open*2);
            else if(open > close)
                open = 0, close = 0;
        }
        return maxlength;
    }
};