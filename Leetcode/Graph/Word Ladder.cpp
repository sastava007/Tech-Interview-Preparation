/*  
    The basic idea is to do BFS to search the shortest path. The only trick is to speed up the search, we do bi-directional search, in the sense that we may expand the current path to the next level either from the beginWord side or the endWord side, depending on which side has less nodes to be expanded.

    Here we maintain two visited hashsets to keep track of nodes visited from the search starting from both the ends. And whenver we find a word which is present in visited set of other parallel search, then it means we've reached in middle where they both have met.  

    TC and Space: O(M^2 * N) where M is length of word and N is number of words in dictionary. 
    But here unlike single source BFS, the search time & space reduces to half, since the two parallel searches meet somewhere in the middle.

*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordDict) 
    {
        unordered_set<string> head, tail, dict(wordDict.begin(), wordDict.end());

        if(dict.find(endWord) == dict.end())
            return 0;
        head.insert(beginWord);
        tail.insert(endWord);

        int minPath = 2;

        while(!head.empty() && !tail.empty())
        {
            if(head.size()>tail.size())
                head.swap(tail);
            
            unordered_set<string> temp;
            for(auto it: head)
            {
                string s = it;
                for(int i=0; i<s.length(); i++)
                {
                    char old = s[i];
                    for(char c='a'; c<='z'; c++)
                    {
                        if(s[i]==c)
                            continue;
                        s[i]=c;
                        if(tail.find(s) != tail.end())
                            return minPath;
                        if(dict.find(s) != dict.end())
                        {
                            temp.insert(s);
                            dict.erase(s);
                        }
                    }
                    s[i]=old;
                }
            }
            head.swap(temp);
            minPath++;
        }
        
        return 0;
    }
};