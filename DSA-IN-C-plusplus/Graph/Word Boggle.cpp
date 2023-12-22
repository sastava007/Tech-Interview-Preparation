class Solution {
public:
	bool exist(vector<vector<char>>&board , string word)
{
    int n=board.size();
    int m=board[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dfs(board,i,j,word,n,m)) return true;
        }
    }
    return false;
}

bool dfs(vector<vector<char>>&board ,int i,int j,string word,int n ,int m)
    {
        if(word.size()==0) return true;
        if(i<0 or i>=n or j<0 or j>=m or board[i][j]!=word[0]) return false;
        char temp=board[i][j];
        string check=word.substr(1);
        board[i][j]='#';
        bool ans = dfs(board,i-1,j-1,check,n,m);
        ans|= dfs(board,i-1,j,check,n,m);
        ans|= dfs(board,i-1,j+1,check,n,m);
        ans|= dfs(board,i,j-1,check,n,m);
        ans|= dfs(board,i,j+1,check,n,m);
        ans|= dfs(board,i+1,j-1,check,n,m);
        ans|= dfs(board,i+1,j,check,n,m);
        ans|= dfs(board,i+1,j+1,check,n,m);
        board[i][j]=temp;
        return ans;
    }
    

vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dict) 
	{
	    vector<string> ans;
	    for(auto word : dict)
	    {
	        if(exist(board,word))
	        {
	            ans.push_back(word);
	        }
	    }
	    return ans;
	}
};
