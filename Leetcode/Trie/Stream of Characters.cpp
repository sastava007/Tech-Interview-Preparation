/* 	As we've to check the last K characters including this word to be present in dictinoary then we should build our prefix tree in reverse order. 
	And keep on adding the letters to an empty string and check from it's ending whethere there exists some word or not.

	TC: O(N*W) time to buld the tree, where N = total words in dictionary and W = maximum word length and O(no_of_letters_that_has_been_quered) for query
	Space: O(N*W*26)
 */


struct TrieNode
{
    TrieNode* children[26];
    bool isWord;
    TrieNode()
    {
        memset(children, NULL, sizeof(children));
        isWord = false;
    }
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words)
    {
        root = new TrieNode();
        for(string word: words)
        {
            TrieNode* node = root;
            for(int i=word.length()-1; i>=0; i--)
            {
                char c = word[i];
                if(node->children[c-'a']==NULL)
                    node->children[c-'a'] = new TrieNode();
                node = node->children[c-'a'];
            }
            node->isWord = true; 
        }
    }
    
    bool query(char letter) 
    {
        s += letter;
        TrieNode* node = root;
        for(int i=(int)s.length()-1; i>=0 && node!=NULL; i--)
        {
            char c = s[i];
            node = node->children[c-'a'];
            
            if(node!=NULL && node->isWord)
                return true;
        }
        return false;
    }
private:
    TrieNode* root;
    string s;
};