/*  
    As there could be cyclic paths as well i.e we've a non DAG, so that's why we dont use topological sort which sounds most intutive here. 
    TC: O(NlogD) where N is size of tickets and D is largest outgoing edge of a vertex.
    Space: O(N)

    1. Store the flight in a hash map. (say m in the code below. This map enables us to find all possible destinations from a place in amortized constant time.)
    2. Run a DFS clevery, ensuring that airports are explored in lexographical order

*/

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        vector<string> iternary; 
        if(tickets.size()==0)
            return iternary;
        
        unordered_map<string, multiset<string>> graph;
        
        for(auto &ticket: tickets)  
            graph[ticket[0]].insert(ticket[1]);     //push the outhging or detination edges 
        
        stack<string> todo;
        todo.push("JFK");
        
        while(!todo.empty())
        {
            string airport = todo.top();
            
            if(graph[airport].empty())      //if we've explored all it's outgoing edges, i.e no more pending to be explored
            {
                iternary.push_back(airport);
                todo.pop();
            }
            else
            {
                todo.push(*(graph[airport].begin()));   // otherwise puch the outgoing edges to the stack, and remove it from the graph
                graph[airport].erase(graph[airport].begin());
                
            }
        }
        reverse(iternary.begin(), iternary.end());
        return iternary;
    }
};