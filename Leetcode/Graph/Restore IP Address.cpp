/*  
    For IPV4 add. we have to place 3 dots, such that each portion lies b/2 [0-255] and no portion should have a leading zero
    What we are trying to do here is to partition the input string into 4 parts with 3 cuts. There are C(n, 3) ways to cut the string into 4 parts. In that sense, the time complexity is O(n^3). On second thought, however, because we are doing backtracking and removing lots of unnecessary checking, we are only checking three possibilities for each part (it has to be [0,255]), it becomes 3^4, which is just a constant, so it becomes O(1)

    DFS Approach
    TC: O(3^4) & Space: O(n) for output return oterwise O(1) depth of recursion tree is 4
    
    Input: "25525511135"  Output: ["255.255.11.135", "255.255.111.35"]
*/

class Solution
{
    public:
    vector<string> restoreIpAddresses(string s)
    {
            if (s.empty()) return {};
            vector<string> res;
            dfs("", 0, 0, res, s);      // we can use 2 variable, one to maintain the group upto which we've processed and other to track character in string
            return res;
    }
    
    private:
    void dfs(string prefix, int step, int start, vector<string> &res, string &str) 
    {
        if (step == 4 && prefix.size() - str.size() == 4) //here we are checking that difference b/w orignial string and restored IP should be = 4, becz we've added only 4 extra dots
        {
            prefix.pop_back();  //remove the last dot '.'
            res.push_back(prefix);
            return;
        }
        if (step > 4) 
        {
            return;
        }
        for(int i = 1; i < 4; i++) 
        {
            int end = start + i;
            if(end > str.size() || (str[start] == '0' && i > 1 ))    //handle '001' case leading zeroes
                continue;
            string segment = str.substr(start, i);
            int num = stoi(segment);
            if(num < 0 || num > 255) 
            {
                continue;
            }
            dfs(prefix + segment + ".", step+1, end, res, str);
        }
    }
};