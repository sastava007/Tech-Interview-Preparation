/*  
    Using Trie: Shorter DFS implementation, As typical DFS has O(V+E) time complexity
    For each '.' I would have to process all possible branches of the tree. For example a query like this "..." would mean, 
    I have to check all nodes and all vertices within the tree. That would be V (vertices) + E(edges)
    
    Time: O(V + E) and Space O(M*N) where N = no. of words & M = length of maximum word

*/

struct TrieNode
{
    bool isKey;
    TrieNode* children[26];
    TrieNode():isKey(false){
        memset(children, NULL, sizeof(children));
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) 
    {
        TrieNode* node = root;
        for(auto c: word){
            if(!node->children[c - 'a'])        // If current character is not present in our Trie tree, then create a new one & add.
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->isKey = true;
    }
    
    bool search(string word) {
        return helper(word, root);
    }

private:
    TrieNode* root;
    
    bool helper(string word, TrieNode* node)
    {
        for(int i = 0; i < word.size(); i++){
            char c = word[i];
            if(c != '.')
            {
                if(!node->children[c - 'a']) 
                    return false;
                node = node->children[c - 'a'];
            }
            else
            {
                bool found = false;
                int j = 0;
                for(; j < 26; j++)
                {
                    if(node->children[j]) 
                        found = found | helper(word.substr(i + 1), node->children[j]);
                    if(found) return true;
                }
                if(j == 26) return false;
            }
        }
        return node->isKey;
    }
};

/* My own implementation */

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

class WordDictionary {
public:
    
    WordDictionary()
    {
        root = new TrieNode();
    }
    
    void addWord(string word)
    {
        TrieNode* node = root;
        for(char c: word)
        {
            if(!node->children[c-'a'])
                node->children[c-'a']=new TrieNode();
            
            node=node->children[c-'a'];
        }
        node->isWord=true;
    }
    
    
    bool search(string word)
    {
        return searchUtil(word, 0, root);
    }
    
    private:
    TrieNode* root;
    
    bool searchUtil(string word, int index, TrieNode* node)
    {
        if(index==word.length())    // base case
            return node->isWord;
        
        char c = word[index];
        
        if(c != '.')  // perform the regular trie search
        {
            return (node->children[c-'a']!=NULL && searchUtil(word, index+1, node->children[c-'a']));   //if current character is present then only search for next character 
        }
        else
        {
            for(int i=0; i<26; i++)
            {
                if(node->children[i]!=NULL && searchUtil(word, index+1, node->children[i]))
                    return true;
            }
            
            return false;
        }
    }
    
};
