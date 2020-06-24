/*  IPv4 has 3 "." and total 4 segments, each segment length <=3 and lies in b/w [0-255]
    IPv6 has 7 ":" and toatl 8 segments, each segment length <=4 and each segment should be a hexadecimal no of length 1-4

Valid - Invalid IPv4: [172.16.254.1, 172.16.254.01]
Valid - Invalid IPv6: [2001:0db8:85a3:0000:0000:8a2e:0370:7334, 2001:0db8:85a3::8A2E:0370:7334] we can also omit leading zeroes and first ex can be written as 2001:db8:85a3:0:0:8A2E:0370:7334

    TC: O(N) and Space: O(1) here we're ignoring the internal space that is used to store our splitted strings

*/

class Solution {
public:
    string validIPAddress(string IP) 
    {
        if(isIPv4(IP))
            return "IPv4";
        else if(isIPv6(IP))
            return "IPv6";
        else
            return "Neither";
    }
private:
    
    bool isIPv4(string s)
    {
        if(count(s.begin(), s.end(), '.') != 3)
            return false;
        vector<string> parts = split(s, '.');
        if(parts.size() != 4)        // becz there should be 4 segments
            return false;
        
        for(string part: parts)
        {
            if(part.empty() || part.size()>3 || (part[0]=='0' && part.size()>1))    // no leading zeroes
                return false;
            
            for(char c: part)
                if(!isdigit(c))
                    return false;
            if(stoi(part)>255)
                return false;
        }
        return true;
    }
    
    bool isIPv6(string s)
    {
        if(count(s.begin(), s.end(), ':') != 7)
            return false;
        vector<string> parts = split(s, ':');
        if(parts.size() != 8)
            return false;
        
        for(string part: parts)
        {
            if(part.empty() || part.size()>4)
                return false;
            
            for(char c: part)
            {
                if(!isdigit(c) && (!isalpha(c) || toupper(c) > 'F'))    // maximum hexadecimal digit can be 'F'
                    return false;
            }
        }
        return true;
    }
    
    vector<string> split(string s, char c)
    {
        vector<string> parts;
        string token;
        istringstream in(s);
        while(getline(in, token, c))
        {
            parts.emplace_back(token);
        }
        
        return parts;
    }
};