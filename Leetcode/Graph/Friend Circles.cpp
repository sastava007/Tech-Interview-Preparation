/*  
    Given a matrix of friends, A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends. Find friend circles.
    
    From some source, we can visit every connected node to it with a simple DFS. As is the case with DFS's, seen will keep track of nodes that have been visited.
    For every node, we can visit every node connected to it with this DFS, and increment our answer as that represents one friend circle (connected component)

    TC: O(N*N) and Space: O(N) maximum depth of recursion
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
            if(M[person][other]==1 && !visited[other])      //We found an unvisited person in the current friend cycle 
            {
                visited[other] = true;
                dfs(M, visited, other);     //Start DFS on this new found person
            }
        }
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

/* Using Queue */
public int findCircleNum(int[][] M) {
    int count = 0;
    for (int i=0; i<M.length; i++)
        if (M[i][i] == 1) { count++; BFS(i, M); }
    return count;
}

public void BFS(int student, int[][] M) {
    Queue<Integer> queue = new LinkedList<>();
    queue.add(student);
    while (queue.size() > 0) {
        int queueSize = queue.size();
        for (int i=0;i<queueSize;i++) {
            int j = queue.poll();
            M[j][j] = 2; // marks as visited
            for (int k=0;k<M[0].length;k++) 
                if (M[j][k] == 1 && M[k][k] == 1) queue.add(k);
        }
    }
}