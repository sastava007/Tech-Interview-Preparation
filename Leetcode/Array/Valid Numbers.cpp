/*  It's a very ambigious problem, so we need to think for a lot of edge cases. Like we can't have decimal after finding exponent, and there must exist
    some numbers that you find exponent, and many other such cases. 

    https://www.youtube.com/watch?v=5gmtCtAooZE  
*/

class Solution {
public:
    bool isNumber(string s) {
        
        while(!s.empty() && s[0]==' ')
            s.erase(s.begin());
        while(!s.empty() && s[s.size()-1]==' ')
            s.erase(s.end()-1);
        
        if(s.empty())
            return false;
        
        bool eSeen = false;
        bool numSeen = false;
        bool dotSeen = false;
        
        for(int i=0; i<s.size(); i++)
        {
            if(isdigit(s[i]))
            {
                numSeen = true;
            }
            else if(s[i] == 'e')
            {
                if(eSeen || !numSeen)
                    return false;
                eSeen = true;
                numSeen = false;
            }
            else if(s[i] == '.')
            {
                if(eSeen || dotSeen)
                    return false;
                dotSeen = true;
            }
            else if(s[i]=='+' || s[i]=='-')
            {
                if(i!=0 && s[i-1]!='e')
                    return false;
            }
            else
                return false;
        }
        
        return numSeen;
        
    }
};