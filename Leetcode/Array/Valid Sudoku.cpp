class Solution {
public:
    int start(int n)                                        //return starting of sub-boxes
    {
        if(n>=0 && n<=2)
            return 0;
        else if(n>=3 && n<=5)
            return 3;
        else
            return 6;
    }
    bool check(vector<vector<char>>& board, int x, int y)           //check whether board[x][y] is valid or not
    {
        for(int i=0;i<9;i++)                                        //Check whether column contain repetition or not
        {
            if(i!=x && board[i][y]==board[x][y])
            {
                return false;
            }
        }
        for(int j=0;j<9;j++)                                        //Check whether row contain repetition or not
        {
            if(j!=y && board[x][j]==board[x][y])
            {
                return false;
            }
        }
        int x1=start(x),y1=start(y);
        for(int i=x1;i<x1+3;i++)                                   //Check whether subbox contain repetition or not
        {
            for(int j=y1;j<y1+3;j++)
            {
                if(i!=x && j!=y && board[i][j]==board[x][y])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.' && check(board,i,j)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};