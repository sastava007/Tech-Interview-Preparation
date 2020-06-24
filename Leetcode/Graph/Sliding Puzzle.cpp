/* 
    We can consider each configuartion of board as a node in a graph, and where we need to reach to a particular node in minimum steps possible. So the first things that jumps into my mind is
    to use BFS to find the min distance b/w start and end node. And while using BFS, we can count the no. of levels as we expand to keep track of the distance, but first we have to define the
    possible set of transitions that we can make from our current state, and this can be done by understanding the pattern of swaps that we can make.

    And every time we swap '0' to reach a new state, we should recors that state to avoid visiting it again & again 

    Analysis: There will be total 6! permutations of 6 numbers[0-5] and each state is 6 character long so Space Complexity = O(6*6!) and for each state str.find() & str.equals() will 
    take linear time which is equal to length of string so Time Complexity = O(6*6!) => O(4320)

*/

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) 
    {
        int n = board.size(), m = board[0].size();
        string target = "123450";       // our goal is to reach this state
        string start = "";
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                start += to_string(board[i][j]);
        
        unordered_map<int, vector<int>> dirs;
        dirs[0] = vector<int>({1,3});
        dirs[1] = vector<int>({0,2,4});
        dirs[2] = vector<int>({1,5});
        dirs[3] = vector<int>({0,4});
        dirs[4] = vector<int>({1,3,5});
        dirs[5] = vector<int>({2,4});
        
        unordered_set<string> visited;
            
        queue<string> q;
        q.push(start);
        visited.insert(start);
        
        int res = 0;
        while(!q.empty())
        {
            int size = q.size();
             while(size--)
             {
                 string curr = q.front();
                 q.pop();
                 
                 if(curr == target)
                     return res;
                 
                 int index = curr.find("0");
                 for(int dir: dirs[index])
                 {
                     string candidate = curr;
                     swap(candidate[index], candidate[dir]);
                     if(visited.find(candidate) == visited.end())
                     {
                         q.push(candidate);
                         visited.insert(candidate);
                     }
                 }
             }
            res++;
        }
        return -1;
    }
};

/* Follow Up: How to print the path of all the transition, I think in that case simple BFS won't work and we'v to use DFS+Backtracking */