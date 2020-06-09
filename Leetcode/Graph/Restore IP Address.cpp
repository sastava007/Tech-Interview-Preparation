/* FOr ipv4 add we have to place 3 dots, such that each portion lies b/2 [0-255] and if a portion constains a 0 then 
    it should contain only single 0.

    TC: O(3^n) where n = length of string which is expected to be in b/w [4-12] so overall cimplexity is constant
    Space: O(n)
*/

class Solution
{
    public:
    vector<string> restoreIpAddresses(string s)
    {
            if (s.empty()) return {};
            vector<string> res;
            dfs("", 0, 0, res, s);
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
			//handle '001' case leading zeroes
            if(end > str.size() || (i > 1 && str[start] == '0')) 
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