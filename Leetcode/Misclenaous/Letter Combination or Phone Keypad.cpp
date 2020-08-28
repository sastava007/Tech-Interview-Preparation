/* 
    Here we'll be using a backtracking approach, to find all the valid solutions by exploring all the possible candidates.
    
    TC & Space: O(3^N * 4^M)

    Where N is the no. of digits that maps to 3 letters, and M is the no. of digits that map to 4 letters

*/

class Solution {
    
private:
    unordered_map<char, string> m;
    
public:
    Solution()
    {
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";
    }
    vector<string> letterCombinations(string digits) 
    {
        vector<string> result;
        if(digits=="")
            return result;
        util(digits, 0, "", result);
        return result;
    }
    void util(string digits, int pos, string temp, vector<string> &result)
    {
        if(pos==digits.length())
        {
            result.push_back(temp);
            return;
        }

        string str = m[digits[pos]-'0'];
        for(char c: str)
        {
            string x(1, c);
            temp += x;
            util(digits, pos+1, temp, result);
            temp.pop_back();    // backtracking step i.e remove the last appended element
        }
    }
};