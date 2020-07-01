/*  
    The idea is to build a undirected graph of email id with edge connecting from first email to all other emails. 
    And if there are some common emails between two accounts, then there will be connected component and we can find such relations by doing a DFS.

    We'll also need a maintatin a hash table with emaild id and name of person.
    
    TC: Summation(a[i]*loga[i]) where ai=length of account[i]
    Space: Summation(a[i])

    Note: If the graph is static then use DFS, else if queries are made to update the vertex then use DSU
*/

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
    {
        unordered_map<string, string> emailToName;
        unordered_map<string, vector<string>> graph;
        
        for(auto it: accounts)      //build undirected graph
            for(int i=1; i<it.size(); i++)
            {
                emailToName[it[i]] = it[0];
                
                graph[it[1]].emplace_back(it[i]);
                graph[it[i]].emplace_back(it[1]);
            }
        
        unordered_set<string> visited;
        vector<vector<string>> ans;
        
        for(auto it: graph)     //iterate through all the nodes, and check for conneced components
        {
            if(visited.find(it.first) == visited.end())     // for each connected component
            {
                vector<string> temp;
                temp.emplace_back(emailToName[it.first]);
                
                stack<string> todo;
                todo.push(it.first);
                
                while(!todo.empty())
                {
                    string cur = todo.top();
                    todo.pop();

                    if(visited.find(cur) == visited.end())
                    {
                        temp.emplace_back(cur);
                        visited.insert(cur);
                    }
                    
                    for(string edge: graph[cur])
                        if(visited.find(edge) == visited.end())
                        {
                            todo.push(edge);
                        }
                }
                sort(temp.begin()+1, temp.end());
                ans.emplace_back(temp);
            }
        }
        
        return ans;
    }
};