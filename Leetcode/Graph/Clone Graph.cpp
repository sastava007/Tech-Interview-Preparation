/*  We've to make a deep copy of given graph, so basic idea is to traverse the graph using BFS/DFS and map the visiting nodes to it's new copy. 
    Here, I'm using hash-map<> to store visited nodes as well as build the connection while traversing.

    The first value in hash-map is the original node, and we'are mapping it's copy to it.

    There are 2 methods to perform copy, the first one is Deep Copy & Shallow Copy.
*/

//Iterative BFS solution, TC: O(N+M) Space: O(N or n+m)

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
private:
    unordered_map<Node*, Node*> hash;

public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;

        Node *temp = new Node(node->val, {});
        hash[node] = temp;

        queue<Node *> todo;
        todo.push(node);

        while (!todo.empty())
        {
            Node *curr = todo.front();
            todo.pop();
            
            for (Node *neighbor : curr->neighbors)
            {
                if (hash.find(neighbor) == hash.end())
                {
                    hash[neighbor] = new Node(neighbor->val, {});
                    todo.push(neighbor);
                }
                hash[curr]->neighbors.push_back(hash[neighbor]);
            }
        }
        return hash[node];
    }
};

/* Recursive, DFS Solution */

class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
        if (!node) {
            return NULL;
        }
        if (copies.find(node) == copies.end()) 
        {
            copies[node] = new Node(node -> val, {});
            for (Node* neighbor : node -> neighbors) 
            {
                copies[node] -> neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return copies[node];
    }
private:
    unordered_map<Node*, Node*> copies;
};