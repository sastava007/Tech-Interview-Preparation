/* 
    For understanding multiplication, if you have a sequence of 12345 and you have proceeded to (1 + 2 + 3), now your eval is 6 right? If you want to add a * between 3 and 4, you would take 3 as the digit to be multiplied, so you want to take it out from the existing eval. You have 1 + 2 + 3 * 4 and the eval now is (1 + 2 + 3) - 3 + (3 * 4).

    The time complexity is 3^(N-1) (N-1 because there is no branching for the first element) 
    where N is the length of the string because for every instance of recursion you have 3 branches, (+,-,*)For Example, with "123". at 1 you will produce 3 branches 1+2,1-2,1*2 and for each of these branches you will get 3 more branches and so on.

    Space: O(3^N) doubt

    Input: num = "123", target = 6 Output: ["1+2+3", "1*2*3"]  ;  Input: num = "105", target = 5  Output: ["1*0+5","10-5"]
*/

class Solution {
public:
    vector<string> addOperators(string num, int target)
    {
        vector<string> res;
        dfs(num, target, 0, 0, 0, "", res);
        return res;
    }
    
    void dfs(string& s, int target, int pos, long cv, long pv, string r, vector<string>& res) 
    {
        if (pos == s.size() && cv == target) 
        {
            res.push_back(r);
            return;
        }
        for (int i = 1; i <= s.size() - pos; i++) 
        {
            string t = s.substr(pos, i);
            if (i > 1 && t[0] == '0') 
                continue; // preceding 
            long n = stol(t);
            if (pos == 0)
            {
                dfs(s, target, i, n, n, t, res);    // to get started with the current_value or set the current_value that can be used for all other recursive calls
                continue;
            }
            dfs(s, target, pos+i, cv+n, n, r+"+"+t, res);
            dfs(s, target, pos+i, cv-n, -n, r+"-"+t, res);
            dfs(s, target, pos+i, cv-pv+pv*n, pv*n, r+"*"+t, res);  // we don' use previous_val untill it's not '*' operator
            // similaryly we can also add for / operator
        }
    }
};