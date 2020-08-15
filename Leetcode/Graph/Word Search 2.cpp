/* 
    Naive Approach: DFS(Backtracking)

    Find all the words from the dictionaty whcih can be formed by the combining the letters in the grid. So, one way is to use wordSearch() problem for every word in array.
    TC: O(M * N * num_words * 4^longest_word_length)

    DFS + Trie
    We are doing this N*M times since we need to check for words starting at each position in the board. Order of each traversal is O(4^min(M*N, longest_word_length))
    'min' accounts for the case where we've words in the dictionary longer than the number of characters in the board.

    TC: O(M * N * (4^min(Y, NM)))

    Edge Case: Input: {["a"], ['a','a']} Output: ["a","a"]
    Expected: ["a"]     // not consider the repeated one

*/

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
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        TrieNode *root = new TrieNode();
        for(string word: words)
        {
            TrieNode *curr = root;
            for(char c: word)
            {
                if(curr->children[c-'a']==NULL)
                    curr->children[c-'a'] = new TrieNode();
                curr = curr->children[c-'a'];
            }
            curr->isWord = true;
        }
        vector<string> result;
        unordered_set<string> hashSet;
        for(int i=0; i<board.size(); i++)
            for(int j=0; j<board[0].size(); j++)
            {
                dfs(board, i, j, "", hashSet, root);
            }
        
        result.insert(result.end(), hashSet.begin(), hashSet.end());
        return result;
    }
private:
    void dfs(vector<vector<char>>& board, int x, int y, string word, unordered_set<string> &hashSet, TrieNode *root)
    {   
       if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || board[x][y] == ' ')
           return;
        
        if(root->children[board[x][y]-'a'])
        {
            word += board[x][y];
            root = root->children[board[x][y]-'a'];
            
            if(root->isWord)
                hashSet.insert(word);
            
            char temp = board[x][y];
            board[x][y] = ' ';       
                dfs(board, x-1, y, word, hashSet, root);
                dfs(board, x, y+1, word, hashSet, root);
                dfs(board, x+1, y, word, hashSet, root);
                dfs(board, x, y-1, word, hashSet, root);
            board[x][y] = temp;
        }    
    }
};