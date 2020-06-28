/*  Given a dictionary of words, check whether it's possible to find a word in dictionary after modifying exactly 1 character.
    The main disadvantage of tries is that they need a lot of memory for storing the strings. For each node we have too many node pointers(equal to number of characters of the alphabet)

    Trie is preferred when we've to search for more complex patterns, rather than simple searches
*/

/*  Using hash-set 
    TC: buildDict O(1) for single word, and O(N) for total N words. 
        Search O(W*26) where N = no. of words in dictionary and W = length of word

    Space: O(Summation(Wi)) where Wi is length of string i, so total space would be summation of it.

*/
class MagicDictionary {
private:
    unordered_set<string> words;
public:
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dict) {
        for (string w : dict) {
            words.insert(w);
        }
    }
    bool search(string word) {
        for (int i = 0; i < word.size(); i++) {
            char wi = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {      // try replacing each character with [a-z], and if exists in dictionary[] then return true else backtrack the change.
                if (ch == wi) continue;
                word[i] = ch;
                if (words.count(word)) return true;
            }
            word[i] = wi;
        }
        return false;
    }
};

/*  Using Trie, idea is to build a prefix tree while buildingDictionary()
    And loop for [a-z] trying to replace original char with [a-z], if that's exist in dictionary then return true else return false

    TC: buildDict O(W) for single word, and O(N*W) for all the words in dictionary
        Search: O(W*W*26) W = key length, we're checking by replacing each character in W and each find() will take O(W) time
    
    Space: O(Alphabet_Size*N*M) where N = total words in dictionary and M = length of longest string  here Alphabet_Size = 26

 */
class TrieNode
{
    public:
    TrieNode* children[26];
    bool isWord;
    TrieNode()
    {
        memset(children, NULL, sizeof(children));
        isWord=false;
    }
};

class MagicDictionary {
public:
    MagicDictionary() 
    {
        root = new TrieNode();
    }
    
    void buildDict(vector<string> dict) 
    {
        for(string word : dict)
        {
            TrieNode* node = root;
            for(char c: word)
            {
                if(!node->children[c-'a'])
                    node->children[c-'a'] = new TrieNode();

                node=node->children[c-'a'];
            }
            node->isWord=true;
        }
    }
    bool search(string word) 
    {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) 
        {
            char original_char = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) 
            {
                if (ch == original_char) 
                    continue;
                word[i] = ch;               // replace the current char with [a-z]
                if (find(node, word)) 
                    return true;
            }
            word[i] = original_char;       // backtrack the change
        }
        return false;
    }
private:
    TrieNode* root;
    bool find(TrieNode* node, string s)
    {
        TrieNode* curr = node;
        for(char c: s)
        {
            if(curr->children[c-'a']==NULL)
                return false;
            
            curr = curr->children[c-'a'];
        }
        return curr->isWord;
    }
};