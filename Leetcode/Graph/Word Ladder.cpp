/*  
    As we can change only 1 letter at a time, so we only move to those words which have eactly 1 letter diff from it we keep on doing this untill we reach the target string. 
    Visualizing this as a nodes of a grpah, this problem can be solved by doing a BFS from starting node and we've to find the minimum transitions that we make while doing so.

    PS: starting _word cannot be equal to the ending_word, first clearify that what we've to return no. of transformations or length of transformation sequence
    
    Space: O(N*M) where M is length of maximum word, and N is total number of words
    TC: O(N*M*26)

*/  

int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
{
    unordered_set<string> dict(wordList.begin(), wordList.end());
    queue<string> todo;
    todo.push(beginWord);

    int ladder = 1;     // Here we've to return the length of the transformation seq. and not the no. of transformations that's why starting from 1

    while (!todo.empty()) 
    {
        int size = todo.size();
        while(size--)
        {
            string word = todo.front();
            todo.pop();
            if (word == endWord)
                return ladder;
    
            dict.erase(word);       //deleting so that, we don't visit that node again this way we're not required to maintain an explicit visited set
            for (int j = 0; j < word.size(); j++)
            {
                char c = word[j];
                for (int k = 0; k < 26; k++)
                {
                    word[j] = 'a' + k;
                    if (dict.find(word) != dict.end()) {    //if word after changing 1 letter exists in dictionary, then move to next state
                        todo.push(word);
                    }
                }
                word[j] = c;        // replace the original character
            }
        }
        ladder++;
    }
    return 0;
}

/*  
    We can optmize the above process, by starting the search from both the ends, we keep on expanding simultaneously untill we reach a common word.

    Here we maintain two visited hashsets to keep track of nodes visited from the search starting from both the ends. And whenver we find a word which is present in visited set of other parallel search, then it means we've reached in middle where they both have met.  

    But here unlike single source BFS, the search time & space reduces to half every time, since the two parallel searches meet somewhere in the middle.

    Worst Case when both the sets have N/2 elements

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
                            dict.erase(s);  //to mark as visited
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