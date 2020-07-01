/* The intution for this problem can be made from maximum width of BT, where we maintained a level and id */
/*  We just need to keep traversing, and everytime we go left decrease the horizontal distance by 1 and every time we go to right increase by 1 
    But, make sure that we're doing this by level order traversal otherwise through preorder it may be possible that a node may come before than it's top node

We should use BFS(level-order), not DFS here. Because order needs to be from top to bottom, and left to right. Using DFS could append lower level nodes before upper level nodes

             1
          /     \
         2       3
        /  \    /  \
       4    5  6    7
                \  /  \
                 8 10  9 
                     \
                     11
                       \
                        12      

    Like here using preorder we get 12 before 9.
*/

/* 
    Note: The below approach assumes that if two nodes have same position then output is printed from left->right
    TC: O(NlogN) and Space: O(N) if we use a tree-map
*/

vector<vector<int>> verticalOrder(TreeNode * root) 
{
    vector<vector<int>> ans;
    if(root==NULL)
        return ans;
        
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    
    map<int, vector<int>> m;
    while(!q.empty())       // perform a level order traversal
    {
        pair<TreeNode*, int> temp = q.front();
        q.pop();
        
        m[temp.second].push_back(temp.first->val);
        
        if(temp.first->left)
            q.push({temp.first->left, temp.second-1});
            
        if(temp.first->right)
            q.push({temp.first->right, temp.second+1});
        
    }
    for(auto it: m)
    {
        vector<int> temp;
        for(int node: it.second)
            temp.push_back(node);
        ans.push_back(temp);
    }   
    return ans;    
}

/*  We can also do this without using a tree-map, by first calculating the range of indices i.e the minimum & maximum extreme values column_no. OR horizontal distance that we can get.
    And later we can declare our result as size of (max_index - min_index + 1) and each time before pushing subtract the minimum index from it, so that it gets mapped to positive index 

    TC: O(N) and Space: O(N)
*/

vector<vector<int>> verticalOrder(TreeNode * root) 
{
    if(root==NULL)
        return {{}};
    
    pair<int,int> mm;
    getMinMax(root,mm,0);
    int len = mm.second - mm.first + 1;

    vector<vector<int>> ans(len);

    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    
    while(!q.empty())       // perform a level order traversal
    {
        pair<TreeNode*, int> temp = q.front();
        q.pop();
        
        ans[temp.second - mm.first].push_back(temp.first->val);
        
        if(temp.first->left)
            q.push({temp.first->left, temp.second-1});
            
        if(temp.first->right)
            q.push({temp.first->right, temp.second+1});
        
    } 
    return ans;    
}
void getMinMax(TreeNode* root, pair<int,int> &temp, int d)
{
    if(root==NULL)
        return;
    temp.first = min(temp.first, d);
    temp.second = max(temp.second, d);

    getMinMax(root->left, temp, d-1);
    getMinMax(root->right, temp, d+1);
}


/* Ps: If two nodes are in the same row and column, the order should be from small to large, which is diferent from above solution where we were simply printing from L->R 
    Assuming no duplicates node value, in that case use vector instead of set and sort them later.
*/
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode * root) 
    {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
            
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0,0}});
        
        map<int, map<int, set<int>>> m;
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            
            m[temp.second.first][temp.second.second].insert(temp.first->val);
            
            if(temp.first->left)
                q.push({temp.first->left, {temp.second.first-1, temp.second.second+1}});
                
            if(temp.first->right)
                q.push({temp.first->right, {temp.second.first+1, temp.second.second+1}});
            
        }
        
        for(auto it: m)
        {
            vector<int> col;
            for(auto jt: it.second)
                col.insert(col.end(), jt.second.begin(), jt.second.end());
            ans.push_back(col);
        }
            
        return ans;    
    }
};

/* Using vector & Sorting */
class Solution {
    struct Node {
        TreeNode* n;
        int x, y;
    };
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, vector<int>>> mp;
        queue<Node*> q;
        q.push(new Node{root, 0, 0});
        while(!q.empty()) {
            Node* node = q.front();
            q.pop();
            if(node->n->left) q.push(new Node{node->n->left, node->x - 1, node->y + 1});
            if(node->n->right) q.push(new Node{node->n->right, node->x + 1, node->y + 1});
            mp[node->x][node->y].push_back(node->n->val);
        }
        for(pair<int, map<int, vector<int>>> p1 : mp) {
            ans.push_back({});
            for(pair<int, vector<int>> p2 : p1.second) {
                vector<int> v = p2.second;
                sort(v.begin(), v.end());
                ans.back().insert(ans.back().end(), v.begin(), v.end());
            }
        }
        return ans;
    }
};