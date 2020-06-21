/*  
    M represent unrevealed mine
    E represent revealed empty square
    B represent revealed blank square which doesn't have any adjacent mines
    X represent revealed mine

    Return the board, after revealing the position(x,y) according to foll. rules: 
    1. if M(unrevealed mine), then change it too 'X' and return
    2. if E(empty square) with no ajacent revealed mines, then change it to B, and recursively check in all 8 directions
    3. if E(empty square) with >0 adjacet mine, then chanfe it to digit [1-8] and return

    TC: O(M*N) and Space: O(M*N)

*/

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) 
    {
        if(board[click[0]][click[1]]=='M')
        {
            board[click[0]][click[1]] = 'X';
                return board;
        }
        else if(board[click[0]][click[1]]=='E')
        {
            check_adjacent(board, click[0], click[1]);
        }
        return board;
    }
private:
    vector<pair<int, int>> dir ={{0,1}, {0,-1}, {-1,0}, {1,0}, {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
    void check_adjacent(vector<vector<char>>& board, int x, int y)
    {
        int mines = 0;
        for(auto pt: dir)
        {
            int x1 = x+pt.first, y1 = y+pt.second;
            if(x1>=0 && x1<board.size() && y1>=0 && y1<board[0].size() && board[x1][y1]=='M')
                mines++;
        }
        
        if(mines>0)                                 // if have adjacent mine, then simply update it with number of mines
            board[x][y] = (char)(mines+'0');
        else                                        // if no adjacent mine, then change it to 'B' and recursively check all 8 adjacent direction
        {
            board[x][y] = 'B';
            for(auto pt: dir)
            {
                int x1 = x+pt.first, y1 = y+pt.second;
                if(x1>=0 && x1<board.size() && y1>=0 && y1<board[0].size() && board[x1][y1]=='E')
                    check_adjacent(board, x1, y1);
            }
        }
    }
};