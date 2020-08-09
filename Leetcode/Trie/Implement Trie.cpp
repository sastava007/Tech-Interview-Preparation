/*  */

struct TrieNode
{
    TrieNode* children[26];
    bool isWord;
    TrieNode()
    {
        isWord = false;
        memset(children, NULL, sizeof(children));
    }
};

class Trie {
public:
    
    Trie() 
    {
        root = new TrieNode();
    }
    
    void insert(string word) 
    {
        TrieNode *temp = root;
        for(char c: word)
        {
            if(temp->children[c-'a']==NULL)
                temp->children[c-'a'] = new TrieNode();
            temp = temp->children[c-'a'];
        }
        temp->isWord = true;
    }
    
    bool search(string word) 
    {
        TrieNode *temp = root;
        for(int i=0; i<word.length(); i++)
        {
            char c = word[i];
            if(temp->children[c-'a']==NULL)
                return false;
            temp = temp->children[c-'a'];
        }
        return temp->isWord;
    }
    
    bool startsWith(string prefix) 
    {
        TrieNode *temp = root;
        for(int i=0; i<prefix.length(); i++)
        {
            char c = prefix[i];
            if(temp->children[c-'a']==NULL)
                return false;
            temp = temp->children[c-'a'];
        }
        return true;
    }
    
    TrieNode *root;
};