/* 
    DFS + Backtracking
    Find if the given word exists in the board or not, word can be formed by combining the letters in board sequentially

    TC: O(M∗N∗4^L) where L is length of string
    When we start searching from a character we have 4 choices of neighbors, So for each character we have 4 choices. Total no. of characters are s where s is the length of the input string. 
    So one invocation of search function of your implementation would take O(4^S) time.
    Also in worst case the search is invoked for m∗n times. So an upper bound would be O(M∗N∗4^S).
*/

class Solution 
{
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        if((board.size()==0 || board[0].size()==0) && !word.empty())
            return false;
        
        for(int i=0; i<board.size(); i++)
            for(int j=0; j<board[0].size(); j++)
            {
                if(ifExist(board, word, i, j, 0))   // traverse the board to find the first char
                    return true;
            }
        return false;    
    }
    
    bool ifExist(vector<vector<char>>& board, string word, int x, int y, int pos)
    {
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || board[x][y] != word[pos])
            return false;
        
        if(pos == word.length()-1)
            return true;

        char temp = board[x][y];
        board[x][y] = '.';  //mark as used
        
        if(ifExist(board, word, x-1, y, pos+1) || ifExist(board, word, x, y+1, pos+1) || ifExist(board, word, x+1, y, pos+1) || ifExist(board, word, x, y-1, pos+1))
            return true;

        board[x][y] = temp;     // reset
        return false;
    }
};