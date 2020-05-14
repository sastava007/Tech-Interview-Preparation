/* Performing a levelorder traversal using Queue and map */
void topViewUtil(Node *root, map<int, int> &m)
{
    if(root==NULL)
        return ;
    
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    
    while(!q.empty())
    {
        pair<Node*, int> temp = q.front();
        q.pop();
        
        if(m[temp.second]==0)
            m[temp.second]=temp.first->data;
        
        if(temp.first->left)
            q.push({temp.first->left, temp.second-1});
        if(temp.first->right)
            q.push({temp.first->right, temp.second+1});
    }
}

void topView(struct Node *root)
{
    map<int, int> m;
    topViewUtil(root, m);
    
    for(auto it: m)
        cout<<it.second<<" ";
}


// Best Approach: Perform a preorder traversal using just map and two variables for horizontal distance(hd) and level

void topViewUtil(Node* root, map<int,pair<int, int>> &m, int hd, int level)
{
    if(root==NULL)
        return;

    if(m.find(hd)==m.end())
    {
        m[hd]={root->data, level};
    }
    else if(level<m[hd].second)     //only update if current node lies at upper level, then only it will be visible
    {
        m[hd]={root->data, level};
    }

    topViewUtil(root->left, m, hd-1, level+1);
    topViewUtil(root->right, m, hd+1, level+1);
}

void topView(Node *root)
{
    if(root==NULL)
        return;
        
    map<int,pair<int, int>>  m; 
    topViewUtil(root, m, 0, 0);
    
    for(auto it: m)
        cout<<it.second.first<<" ";
}