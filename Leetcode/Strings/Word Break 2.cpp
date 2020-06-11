/*  Is to first pick a string and then recursively solve for all other substrings
    "pineapplepenapple"
    pine-> all other substrings
    pine -> apple -> all other substrings
    pine -> apple -> pen -> all other substrings
    pine -> apple -> pen -> apple -> all other substrings "** nothing remaining"

    pineapple -> all other substrings
    pineapple -> pen -> all other substrings
    pineapple -> pen -> apple -> all other substrings

    What I know is the first word sperated by a ' ', and then list of other substrings

    'Backtracking with Memoization' TC: O(2^n)

 */

class Solution {
private:
    unordered_map<string, vector<string>> m;

public:
    vector<string> wordBreak(string s,unordered_set<string>& dict) 
    {
        if(m.count(s))    //if current word exist in our hashatble that means starting with this one
            return m[s];

        vector<string> result;
        if(dict.count(s))   // when the whole string is a word in dictinary
        {
            return result.push_back(s);
        }

        for(int i=1; i<s.size(); i++)
        {
            string word = s.substr(i);
            if(dict.count(word))    // if this word is present in dictionary
            {
                string rem = s.substr(0, i);
                vector<string> prev = combine(word, wordBreak(rem, dict));     // recursively generate and combine
                result.insert(result.end(), prev.begin(), prev.end());
            }
        }

        m[s] = result;  //memorize the result
        return result;
    }
private: 
    vector<string> combine(string word, vector<string> prev)
    {
        for(int i=0; i<prev.size(); i++)
        {
            prev[i] += " " + word;
        }
        return prev;
    }
};

/* Using DP 

    The basic idea is to use DP to create an array isBreakable[i] to indicate whether s[i..s.size()-1] is breakable. Then we can use such information to help us speed up the DFS path build process    (buildPath). Learned from other posts, I first calculated minlen and maxlen to speed up the process. 

    So basically what we are doing is to preprocess the string using wordBreak 1 DP and determine whether to go or not. All this will just help to reduce the no. of recursive calls to(N2) but 
    TC remains the same. The worst case scenario where all combinations of the string are correct (e,g, s=aaa, dict=[a, aa, aaa]).


*/

class Solution {
private: //DFS path build function
    void buildPath(bool isBreakable[], string &s, int pos, vector<string> &res, string curP, unordered_set<string>& wordDict, int minlen, int maxlen)
    {
        int i, len = s.size();
        for(i =minlen; i<= min(maxlen, len - pos); ++i)
            if( isBreakable[pos+i] && wordDict.count(s.substr(pos,i)) ) 
                if(pos+i == len) res.push_back(curP + s.substr(pos,i));
                else buildPath(isBreakable, s, pos+i, res, curP + s.substr(pos,i) + " ", wordDict, minlen, maxlen);
    }
    
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int sSize = s.size(), len, i, minlen = INT_MAX, maxlen = INT_MIN;
        vector<string> res;
        bool isBreakable[sSize+1];
        fill_n(isBreakable, sSize+1, false);
            
        for (string word : wordDict) { // find the minimum and maximum word length 
            minlen = min(minlen, (int)word.length());
            maxlen = max(maxlen, (int)word.length()); 
        }        
        //DP to build isBreakable
        for(i=sSize-minlen, isBreakable[sSize]= true; i>=0; --i)
            for(len=minlen; len<=min(maxlen, sSize-i); ++len)
            {
                if(isBreakable[i+len] && wordDict.count(s.substr(i,len)) ) {isBreakable[i] = true; break;}
            }
        //if breakable, do DFS path building
        if(isBreakable[0]) buildPath(isBreakable, s, 0, res, "", wordDict, minlen, maxlen);
        return res;
    }
};