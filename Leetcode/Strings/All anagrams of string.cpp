/* TC: O(N) because the begin and end points will move from left to right only once. */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> ans;
        
        if(p.length() > s.length())
            return ans;
        
        unordered_map<char, int> m;
        for(char c: p)
            m[c]++;
        
        int begin = 0, end = 0, counter = m.size();
        
        while(end<s.length())
        {
            if(m.find(s[end]) != m.end())
            {
                m[s[end]]--;
                if(m[s[end]] == 0)
                    counter--;
            }
            end++;
            
            while(counter == 0)
            {
                if(m.find(s[begin]) != m.end())
                {
                    m[s[begin]]++;
                    if(m[s[begin]] > 0)
                        counter++;
                }
                
                if(end-begin == p.length())
                    ans.emplace_back(begin);
                
                begin++;
            }
        }
        
        return ans;
    }
};