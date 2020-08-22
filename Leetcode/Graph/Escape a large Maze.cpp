/* 
    Given a maze of 1M*1M with some cells blocked, find whether its possible to reach from src. to dest.
    In general if src->target is impossible only 2 cases should be considered:

        1. src is trapped and target is not in the same trap
        2. target is trapped and src in not in the same trap

    The idea is to use 2 depth limited search one start from the source to destination, other start from destination to source. Note that if we
    can moves to a spot which the Mahhatan distance is over 200 to the starting point we could consider that we escape the blockade.
    A very special case is that we can reach src to dest within the 200 moves(both are in same trap) in this way we could just do one BFS and return true.
    
    Since the points are given as coordinates a direct mapping is inconvinience in C++, hence, we use unordered_set<long long> which 1000000 * x + y 
    refers to the value of (x, y).
 
*/

class Solution {
    
    unordered_set<long long int> set;
    
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) 
    {
        set = unordered_set<long long>();
        
        for(auto it: blocked)
            set.insert((long long)it[0]*1000000 + it[1]);
        
        int canEscape = bfs(source, target);
        if(canEscape == 2)  // if can directly reach destination
            return true;
        else if(canEscape == 0)     // If we can't escape from trap
            return false;
        
        set = unordered_set<long long>();
        for(auto it: blocked)
            set.insert((long long)it[0]*1000000 + it[1]);
        
        return bfs(target, source)>0;  
    }
    
    int bfs(vector<int>& source, vector<int>& target)
    {
        queue<pair<int, int>> q;
        int offset[] = {-1, 0, 1, 0, -1};
        
        q.push({source[0], source[1]});
        set.insert((long long)source[0]*1000000 + source[1]);
        
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            
            if(temp.first == target[0] && temp.second == target[1])
                return 2;
            if(abs(temp.first - source[0]) + abs(temp.second - source[1]) > 200)   // If manhatan distance is greater than > 200, then it means we've sucessfully escaped the trap
                return 1;
            
            for(int i=0; i<4; i++)
            {
                int x = temp.first + offset[i], y = temp.second + offset[i+1];
                long long hash = (long long)x*1000000 + y;
                if(x<0 || x>=1000000 || y<0 || y>=1000000 || set.find(hash)!=set.end())
                    continue;
                
                q.push({x,y});
                set.insert(hash);
            }
        }
        return 0;
    }
};