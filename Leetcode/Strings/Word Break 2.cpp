/*  Idea is to first pick a string and then recursively solve for all other substrings
    s= "pineapplepenapple" and wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
    
    pine -> all other substrings
    pine -> apple -> all other substrings
    pine -> apple -> pen -> all other substrings
    pine -> apple -> pen -> apple -> all other substrings "** nothing remaining"

    pineapple -> all other substrings
    pineapple -> pen -> all other substrings
    pineapple -> pen -> apple -> all other substrings

    What I know is the first word sperated by a ' ', and then list of other substrings

    Backtracking with Memoization' TC & Space: O(n*2^n)
    Worst case scenario where all combinations of the string are correct (e,g, s=aaa, dict=[a, aa, aaa])  O/P: ["a a a","aa a","a aa","aaa"]

    s = "pineapplepenapple"  wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
    O/P:  ["pine apple pen apple", "pineapple pen apple", "pine applepen apple"]

 */

// Top down approach: Backtracking + Meoization
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        dict.insert(wordDict.cbegin(), wordDict.cend());
        return wordBreak(s);
    }
private:
    unordered_set<string> dict;
    unordered_map<string,vector<string>> map;

    vector<string> wordBreak(string s) 
    {
        if (map.find(s) != map.end()) //if the sentence starting from current word already present in hash-map, then simply return it
            return map[s];
        vector<string> sentences;
        for (int pos = s.size() - 1; pos >= 0; --pos) 
        {
            string word = s.substr(pos);
            if (dict.find(word) != dict.end()) 
            {
                if (pos == 0)
                    sentences.push_back(word); // base case of recursion
                else 
                {
                    vector<string> subSentences = wordBreak(s.substr(0, pos));
                    for (auto subSentence : subSentences)
                        sentences.push_back(subSentence + " " + word);
                }   
            }
        }
        map[s] = sentences;
        return sentences;
    }
};


/* Using DP 

    The basic idea is to use DP to create an array isBreakable[i] to indicate whether s[i..s.size()-1] is breakable. Then we can use such information to help us speed up the DFS path build process  (buildPath). Learned from other posts, I first calculated minlen and maxlen to speed up the process. 

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
                if(pos+i == len) 
                    res.push_back(curP + s.substr(pos,i));
                else 
                    buildPath(isBreakable, s, pos+i, res, curP + s.substr(pos,i) + " ", wordDict, minlen, maxlen);
    }
    
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int sSize = s.size(), len, i, minlen = INT_MAX, maxlen = INT_MIN;
        vector<string> res;
        bool isBreakable[sSize+1];
        fill_n(isBreakable, sSize+1, false);
            
        for (string word : wordDict)    // find the minimum and maximum word length 
        { 
            minlen = min(minlen, (int)word.length());
            maxlen = max(maxlen, (int)word.length()); 
        }        
        //DP to build isBreakable
        for(i=sSize-minlen, isBreakable[sSize]= true; i>=0; --i)
            for(len=minlen; len<=min(maxlen, sSize-i); ++len)
            {
                if(isBreakable[i+len] && wordDict.count(s.substr(i,len)) ) 
                {
                    isBreakable[i] = true;
                    break;
                }
            }
        //if breakable, do DFS path building
        if(isBreakable[0]) 
            buildPath(isBreakable, s, 0, res, "", wordDict, minlen, maxlen);
        return res;
    }
};