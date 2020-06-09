/*  
    So idea is to basically try to obatin substrings of the given word and check if that's present in the disctionary or not. 
    So a brute force approach would be to recursively generate & check all possible substrings of string and check if that's present in the dictionary or not O(2^n)

*/

class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        // put all words into a hashset
        Set<String> set = new HashSet<>(wordDict);
        return wb(s, set);
    }
    private boolean wb(String s, Set<String> set) {
        int len = s.length();
        if (len == 0) {
            return true;
        }
        for (int i = 1; i <= len; ++i) {
            if (set.contains(s.substring(0, i)) && wb(s.substring(i), set)) {
                return true;
            }
        }
        return false;
    }
};

/* Using DP: dp[j] is true only when dp[i] is true and s.substr(i,j) is present in dictionary. In this case we tried every possible length, but we can do some optimization over this */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        vector<bool> dp(s.length()+1, false);
        
        dp[0]=true;
        
        for(int i=0; i<s.length(); i++)
        {
            if(dp[i]==false)
                continue;
            
            for(int j=i+1; j<=s.length(); j++)
            {
                string temp = s.substr(i, j);
                if(dict.find(temp) != dict.end())
                    dp[j] = true;
            }   
        }    

        return dp[s.length()];
    }
};


/*  As we seen in above approach that there will be many substraings that will be generated repeatedly, so we have to look for methods to memoize them. 

    dp[i] represents whether subarray(0, i) can be segmented into words that are present into dictionary. dp[0] = subarray(0,0) which is empty string can be ofcourse
    segmented so answer is yes.

    https://www.youtube.com/watch?v=6UcUFUCCpjY

*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        vector<bool> dp(s.length()+1, false);
        dp[0]=true;
        
        int n = s.length();

        for(int i=0; i<n; i++)
        {
            if(dp[i]==false)
                continue;
            
            for(string word: wordDict)
            {
                int len = word.length();    //there is no need to try for all length, just try for i+word.length which is in dictionary
                int j = i+len;
                if(j<=n && s.substr(i,len) == word)
                    dp[j] = true;
            }
            
        }
        
        return dp[n];
    }
};