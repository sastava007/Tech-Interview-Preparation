/* The idea is to modify vertical order traversal, to stire just last element of each vertical line */

// using Queue and map
void bottomViewUtil(Node* root, map<int,int> &m)
{
    if(root==NULL)
        return;
        
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    
    while(!q.empty())
    {
        pair<Node*, int> temp = q.front();
        q.pop();
        
        m[temp.second]=temp.first->data;
        
        if(temp.first->left)
            q.push({temp.first->left, temp.second-1});
        if(temp.first->right)
            q.push({temp.first->right, temp.second+1});
    }
}

void bottomView(Node *root)
{
    if(root==NULL)
        return;
        
    map<int, int> m;
    bottomViewUtil(root, m);
    
    for(auto it: m)
        cout<<it.second<<" ";
}

// Best Approach: using just map and two variables for horizontal distance(hd) and level

void bottomViewUtil(Node* root, map<int,pair<int, int>> &m, int hd, int level)
{
    if(root==NULL)
        return;

    if(m.find(hd)==m.end())
    {
        m[hd]={root->data, level};
    }
    else if(level>=m[hd].second)
    {
        m[hd]={root->data, level};
    }

    bottomViewUtil(root->left, m, hd-1, level+1);
    bottomViewUtil(root->right, m, hd+1, level+1);
}

void bottomView(Node *root)
{
    if(root==NULL)
        return;
        
    map<int,pair<int, int>>  m; 
    bottomViewUtil(root, m, 0, 0);
    
    for(auto it: m)
        cout<<it.second.first<<" ";
}