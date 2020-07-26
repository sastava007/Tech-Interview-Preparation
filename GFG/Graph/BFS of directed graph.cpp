/* 
    

*/

vector <int> bfs(vector<int> g[], int N)
{
    vector<int> result;
    unordered_set<int> visited;
    queue<int> q;
    
    q.push(0);
    visited.insert(0);
    
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        result.push_back(temp);
        
        for(int neigh: g[temp])
            if(visited.find(neigh)==visited.end())
            {
                q.push(neigh);
                visited.insert(neigh);
            }
    }
    
    return result;
}