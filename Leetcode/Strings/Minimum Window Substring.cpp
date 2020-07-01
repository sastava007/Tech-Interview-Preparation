/* https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/92007/Sliding-Window-algorithm-template-to-solve-all-the-Leetcode-substring-search-problem. 

    We are supposed to find the minimum window in S which contains all the characters of string T

    TC: O(M+N) & Space: O(1)
    
    Input: S = "ADOBECODEBANC", T = "ABC"
    Output: "BANC"
*/

class Solution {
public:
    string minWindow(string s, string t) 
    {
        if(t.length() > s.length())
            return "";
        
        unordered_map<char, int> map;
        for(char c: t)
            map[c]++;
        
        int start = 0, end = 0, n = s.length(), minstart = 0, remaining = map.size(), minlen = INT_MAX;
        
        while(end<n)
        {
            if(map.find(s[end]) != map.end())
            {
                map[s[end]]--;
                if(map[s[end]] == 0)
                    remaining--;
            }
            end++;
            
            while(remaining == 0)   //keep removing the characters from current window by shiting begin, untill they become invalid, then again look for in next window.
            {
                if(end-start<minlen)
                {
                    minlen=end-start;
                    minstart=start;
                }
                
                if(map.find(s[start]) != map.end())
                {
                    map[s[start]]++;
                    if(map[s[start]] > 0)
                        remaining++;
                }
                start++;
            }
        }
        
        if(minlen != INT_MAX)
            return s.substr(minstart, minlen);
        else
            return "";
    }
};

class Solution {
public:
    string minWindow(string s, string t) 
    {
        unordered_map<char, int> map;
        for(char c: t)
            map[c]++;
        
        int start = 0, end = 0, n = s.length(), minstart = 0, remaining = t.size(), minlen = INT_MAX;
        
        while(end<n)
        {   
            // If char in s exists in t, decrease remaining
            if(map[s[end]] > 0)
                remaining--;
            // Decrease m[s[end]]. If char does not exist in t, m[s[end]] will be negative.    
            map[s[end]]--;
            end++;
            
            // When we found a valid window, move start to find smaller window.
            while(remaining == 0)
            {
                if(end-start < minlen)
                {
                    minlen = end-start;
                    minstart = start;
                }
                map[s[start]]++;
                // When char exists in t, increase remaining.
                if(map[s[start]] > 0)
                    remaining++;
                start++;
            }
        }
        
        if(minlen != INT_MAX)
            return s.substr(minstart, minlen);
        else
            return "";
    }
};