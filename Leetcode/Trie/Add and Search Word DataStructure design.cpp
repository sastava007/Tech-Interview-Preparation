/*  
    Using Trie: As typical DFS has O(V+E) time complexity
    
    
    Time: O(V + E) and Space O(M*N) where N = no. of words & M = length of maximum word
    Add Word: O(N)
    Search Word: Worst Case O(26^N) in case of "..." we've to check for all the 26 characters for each '.' encountered
    
    O(V+E) , for each '.' I would have to process all possible branches of the tree. For example a query like this "..." would mean, 
    I have to check all nodes and all vertices within the tree. That would be V (vertices) + E(edges)

    Space: O(M*N*26)    here M is length of string, and 26 becz we're declaring 26 children pointers

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
        for(auto c: word)
        {
            if(!node->children[c - 'a'])        // If current character is not present in our Trie tree, then create a new one & add.
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->isKey = true;
    }
    bool search(string word) 
    {
        return helper(word, root);
    }

private:
    TrieNode* root;
    bool helper(string word, TrieNode* node)
    {
        for(int i = 0; i < word.size(); i++)
        {
            char c = word[i];
            if(c != '.')
            {
                if(!node->children[c - 'a'])   // if even our current character isn't present then no need to check further, simply return false
                    return false;
                node = node->children[c - 'a'];
            }
            else
            {
                bool found = false;
                int j = 0;
                for(; j < 26; j++)
                {
                    if(node->children[j])   // if current 'j'char exist, then move forward
                        found = found | helper(word.substr(i + 1), node->children[j]);
                    if(found) return true;
                }
                if(j == 26) return false;
            }
        }
        return node->isKey;
    }
};

/* Another Approach */

class WordDictionary {
    class TrieNode {
        TrieNode[] children;
        boolean isWord;
        
        TrieNode() {
            children = new TrieNode[26];
        }
    }

    private TrieNode root;
    
    public WordDictionary() {
        root = new TrieNode();
    }
    
    public void addWord(String word) 
    {
        TrieNode current = root;
        for (char c : word.toCharArray()) {
            int index = c - 'a';
            if (current.children[index] == null) {
                current.children[index] = new TrieNode();
            }
            current = current.children[index];
        }
        current.isWord = true;
    }
    
    public boolean search(String word) {
        return search(word, 0, root);
    }
    
    private boolean search(String word, int index, TrieNode node) {
        if (index == word.length()) {
            return node.isWord;
        }
        
        char c = word.charAt(index);
        if (c == '.') {
            for (TrieNode child : node.children) {
                if (child != null && search(word, index + 1, child)) {
                    return true;
                }
            }
            return false;
        } else {
            TrieNode child = node.children[c - 'a'];
            if (child == null) {
                return false;
            }
            return search(word, index + 1, child);
        }
    }
}
