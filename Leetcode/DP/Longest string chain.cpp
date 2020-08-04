/* 
    A bruteforce approach is to check for sequence chain strating from each word and keep on updating the maximum length of chain seen so far.
    Ex: ["a","b","ba","bca","bda","bdca"]
    starting from "a" => [a,ba,bca,bdca] similarly the one starting from "b" => [b,ba,bca,bdca] which shows that {ba,bca,bdca} are common in bot the chains because of repition
    hence we need to use DP over here.

*/

/* 
    Find the length of longest sequence chain which are pre-decessor of next word in chain.
    
    Idea: Is to sort the words in increasing order of length, and for each word loop for all words with exactly 1 letter missing and if we've seen this already then update
    the length of the longest chain ending at current word.

    TC: O(NlogN +  N*M^2)   // where M is length of string
    Space: O(N*S)
*/

class Solution {
public:
    
    static bool comp(string s1, string s2)
    {
        return s1.length() < s2.length();
    }
    int longestStrChain(vector<string>& words) 
    {
        int ans = 0;
        sort(words.begin(), words.end(), comp);
        unordered_map<string, int> dp;           // length of longest string chain ending with this string
        
        for(string w: words)
        {
            for(int i=0; i<w.length(); i++)
            {
                dp[w] = max(dp[w], dp[w.substr(0,i)+w.substr(i+1)]+1);      // update the length of longest chain sequence ending at the current word
            }
            ans = max(ans, dp[w]);
        }
        return ans;
    }
};