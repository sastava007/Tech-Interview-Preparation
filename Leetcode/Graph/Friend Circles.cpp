/*  
    Given a matrix of friends, A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends. Find friend circles.
    
    From some source, we can visit every connected node to it with a simple DFS. As is the case with DFS's, seen will keep track of nodes that have been visited.
    For every node, we can visit every node connected to it with this DFS, and increment our answer as that represents one friend circle (connected component)

    TC: O(N*N) and Space: O(N) maximum depth of recursion, as there are total N*M nodes in matrix and we'll visit each node only once.
*/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) 
    {
        int friendCircles=0, n = M.size();
        vector<bool> visited(n,false);
        
        for(int person=0; person<n; person++)
            if(!visited[person])    // From some source, we can visit every connected node to it with a simple DFS. 
            {
                friendCircles++;
                dfs(M, visited, person);
            }
        return friendCircles;
    }
    
private:
    void dfs(vector<vector<int>>& M, vector<bool> &visited, int person)
    {
        for(int other=0; other<M.size(); other++)
        {
            if(M[person][other]==1 && !visited[other])      //We found an unvisited person in the current friend circle
            {
                visited[other] = true;
                dfs(M, visited, other);     //Start DFS on this new found person
            }
        }
    }
};

/* BFS: using Queue */
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) 
    {
        int n=M.size();
        if(n==0)return n;
        int circles=0;
        vector<bool> visited(n,false); 

        for(int i=0;i<n;i++)
        {
            if(visited[i])
                continue;
            queue<int> q1;
            q1.push(i);
            circles++;

           while(!q1.empty())
           {               
            int cur=q1.front();
            q1.pop();
            visited[cur]=true;
                for(int j=0;j<M[cur].size();j++)
                {
                    if(visited[j]==false&&M[cur][j]==1)
                    {
                        q1.push(j);
                        visited[j]=true;
                    }
                }
                    
            }
        }
        return circles;
    }
};

/* A more clear & understandable code using O(N^2) space but not efficient */

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) 
    {
        int friendCircles=0, n = M.size();
        vector<vector<int>> visited(n, vector<int>(n,0));
        
        for(int i=0; i<M.size(); i++)
            for(int j=0; j<M[i].size(); j++)
            {
                if(!visited[i][j] && M[i][j]==1)
                {
                    friendCircles++;
                    dfs(M, visited, i, j);
                }
            }
        return friendCircles;
    }
    
private:
    void dfs(vector<vector<int>>& M, vector<vector<int>>& visited, int x, int y)
    {
        if(x<0 || x>=M.size() || y<0 || y>=M[x].size() || visited[x][y] == 1)
            return;
        
        visited[x][y] = 1;
        visited[y][x] = 1;
        
        for(int i=0; i<M[x].size(); i++)
        {
            if(!visited[y][i] && M[y][i]==1)
                dfs(M, visited, y, i);
        }
    }
};