/*  It's a very ambigious problem, so we need to think for a lot of edge cases. Like 
    1. We can't have decimal after finding exponent
    2. Amd there must exist some numbers before & after finding exponent
    3. There couldn't be more that 1 dots(.) and exponent(e) in a number

        "0" => true
        " 0.1 " => true
        "abc" => false
        "1 a" => false
        "2e10" => true
        " -90e3   " => true
        " 1e" => false
        "e3" => false
        " 6e-1" => true
        " 99e2.5 " => false
        "53.5e93" => true
        " --6 " => false
        "-+3" => false
        "95a54e53" => false
*/

class Solution {
public:
    bool isNumber(string s) {
        
        //remove all the white space from starting and ending
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
                if(eSeen || !numSeen)   // if we've already encountered 'e' or haven't encountered any number
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