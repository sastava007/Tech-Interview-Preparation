/*  Similar to no. of islads, but given that here only we need to consider about horizontal & vertical shapes and not any irregular shapes like islands. So first write a recursive solution with 
    TC: O(mn) and by modifyin the board.
 */

class Solution {
public:
    int countBattleships(vector<vector<char>>& board)
    {
        int ships=0;
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[i].size(); j++)
            {
                if(board[i][j]=='X')
                {
                    ships++;
                    sink(board, i, j);
                }
            }
        }
        
        return ships;
    }
    
private:
    void sink(vector<vector<char>> &board, int i, int j)
    {
        if(i<0 || i>=board.size() || j<0 || j>=board[i].size() || board[i][j]=='.')
            return;
        
        board[i][j]='.';    //mark as visited, so that we don't need to get it for the next time
        sink(board, i-1, j);
        sink(board, i, j+1);
        sink(board, i+1, j);
        sink(board, i, j-1);
    }
};

/*  Single pass solution, without modifying the board 
    As we'are traversing the board from left->right and top->bottom so when we're at [i][j] we just need to check for it's top above[i-1][j] and it's left [i][j-1] to check if we've already found
    a battle ship. Becz ultimatley we'll we going to look for it's down and right in next calls, so we only need to make sure for it's top and left. 

*/

class Solution {
public:
    int countBattleships(vector<vector<char>>& board)
    {
        int ships=0;
        if(board.size()==0 || board[0].size()==0)
            return ships;
        
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[i].size(); j++)
            {
                if(board[i][j]=='.')
                    continue;
                if(j>0 && board[i][j-1]=='X')   //this means we're still counting the same battle ships, so we don't to increment our conter for this one.
                    continue;
                if(i>0 && board[i-1][j]=='X')   //this means we're still counting the same battle ships, so we don't to increment our conter for this one.
                    continue;
                ships++;
            }
        }
        
        return ships;
    }
};