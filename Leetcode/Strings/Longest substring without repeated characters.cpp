/* Inspired from ssubstring search leetcode template */

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char, int> m;
        int begin=0, end=0, counter=0;  //counter here stores the no. of duplicate characters present in current window 
        int n = s.length(), maxlen=0;
        while(end<n)
        {
            m[s[end]]++;
            if(m[s[end]] > 1)   //when frequency of a char>1, this means that it has already occurred before means dupliacte
                counter++;
            end++;
            
            while(counter>0)    //this means that there are some duplicates
            {
                if(m[s[begin]] > 1)
                    counter--;
                m[s[begin]]--;
                begin++;
            }
            maxlen=max(maxlen, end-begin);
        }
        
        return maxlen;
    }
};
