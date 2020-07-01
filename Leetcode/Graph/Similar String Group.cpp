/* 
    One attempt is a standard kind of brute force: for each pair of words, let's draw an edge between these words if they are similar. 
    Solved using DFS O(N2 * W) where N is total string in Array and W is average length of string. 

    Basically idea is if a group of strings lie in a similar group, then all these nodes will be connected as a single component. So idea is to just find the no. of connected components
*/

class Solution {
public:
    unordered_set<string> visited;
    int numSimilarGroups(vector<string>& A) 
    {
        int result=0;
        if(A.size() == 0)
            return result;
        
        for(string s: A)
        {
            if(visited.find(s) == visited.end())
            {
                dfs(s, A);
                result++;
            }
        }
        return result;
    }
private:
    bool areSimilar(string s, string t)
    {
        int count=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]!=t[i])
            {
                count++;
                if(count>2)
                    return false;
            }
        }
        return (count==2 || count==0);
    }
    
    void dfs(string s, vector<string> &A)
    {
        if(visited.find(s) != visited.end())
            return;
        
        visited.insert(s);
        
        for(string t: A)
            if(visited.find(t)==visited.end() && areSimilar(s, t))
                dfs(t, A);
        
    }
    
};