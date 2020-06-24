/*  
    For IPV4 add. we have to place 3 dots, such that each portion lies b/2 [0-255] and if a portion constains a 0 then 
    it should contain only single 0.

    DFS Approach

    TC: O(3^4) 
    Space: O(n)
*/

class Solution
{
    public:
    vector<string> restoreIpAddresses(string s)
    {
            if (s.empty()) return {};
            vector<string> res;
            dfs("", 0, 0, res, s);      // we can use 2 variable, one to maintain the octet/group upto which we've processed and other to track character in string
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