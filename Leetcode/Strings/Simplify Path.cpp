/* Parse the path to obtain token, and make sure few things
    1. / means root
    2. .. means going upward in directry, so remove the top most element from stack. And if already present at top then stay there
    3. /.dir is valid directry name, becz folders can contain '.'
*/

class Solution {
public:
    string simplifyPath(string path) 
    {
        vector<string> stk;
        stringstream ss(path);
        string token;
        
        while(getline(ss, token, '/'))
        {
            if(token=="" || token==".")
                continue;
            else if(token != "..")
                stk.emplace_back(token);
            else if(!stk.empty())
                stk.pop_back();
        }
        
        string res="";
        for(string &token: stk)
            res += "/" + token;
        
        return stk.empty()? "/":res;
    }
};