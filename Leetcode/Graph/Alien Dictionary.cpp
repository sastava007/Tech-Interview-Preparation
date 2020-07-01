/*  
    TC & Space: O(N*M) where N is no. of words & M is average length of each word

    1. First, build a degree map for each character in all the words:
    2. Then build the hashmap by comparing the adjacent words, the first character that is different between two adjacent words reflect the lexicographical order.
    3. Then in last call a topological sorting() to get the required ordering of alphabets in dictionary
*/

#include<bits/stdc++.h> 
using namespace std; 
  
class Solution {
public:
    string alienOrder(vector<string>& words)
    {
        unordered_map<char, unordered_set<char>> graph;
        vector<int> indegree(26);

        buildGraph(words, graph, indegree);
        return bfs(graph, indegree);   //topological sorting using BFS to get the required ordering
    }

private:

    void buildGraph(vector<string>& words, unordered_map<char, unordered_set<char>> &graph, vector<int> &indegree)
    {
        for(string word: words)     // add all charcters/alphabet to graph
            for(char c: word)
                graph[c]={};
        
        for(int i=0; i<words.size()-1; i++)
        {
            string word1=words[i], word2=words[i+1];
            int j;
            for(j=0; j<min(word1.length(), word2.length()); j++)
            {
                if(word1[j] != word2[j])    // add an edge from u->v if u comes before v in 2 adjacent words
                {
                    char out = word1[j], in=word2[j];
                    graph[out].insert(in);
                    indegree[in-'a']++;

                    break;
                }
            }
            if(j==min(word1.length(), word2.length()) && word1.length()>word2.length())     //consider case [apple, app] i.e when ordering isn't valid
            {
                graph.clear();
                return;
            }
        }
    }

    string bfs(unordered_map<char, unordered_set<char>> &graph, vector<int> &indegree)
    {
        string res="";
        int totalCharacters=graph.size();

        queue<char> q;

        for(auto it: graph) //enque all the vertices with 0 indegree becz they don't have any dependency to met, their precedence is greater in dictionary
            if(indegree[it.first-'a']==0)
            {
                res += it.first;
                q.push(it.first);
            }
        
        while (!q.empty())  //standard BFS algorithm
        {
            char curr = q.front();
            q.pop();

            if(graph[curr].size() != 0) //if current nodes has neighbours
            {
                for(char neigh: graph[curr])
                {
                    indegree[neigh-'a']--;
                    if(indegree[neigh-'a'] == 0)
                        {
                            q.push(neigh);
                            res += neigh;
                        }
                }
            }
        }
        return (res.length()==totalCharacters?res:"");
    }
};

int main()
{
    Solution obj;

    vector<string> words={"wrt","wrf","er","ett","rftt"};
    string output = "wertf"

    cout<<obj.alienOrder(words);

    return 0;
}