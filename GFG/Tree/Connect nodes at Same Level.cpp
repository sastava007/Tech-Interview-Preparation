/* Using map, to store leftmost node of each level */
void connectUtil(Node* root, map<int, Node*> &m, int level)
{
    if(root==NULL)
        return;
    
    if(m.find(level)==m.end())
    {
        m[level]=root;
    }
    else
    {
        m[level]->nextRight=root;
        m[level]=root;
    }
    
    connectUtil(root->left, m, level+1);
    connectUtil(root->right, m, level+1);
}

void connect(Node *p)
{
    if(p==NULL)
        return ;
        
    map<int, Node*> m;
    connectUtil(p, m, 0);
}               


/* Without using map, doing level order traversal*/
void connect(Node *p)
{
    if(p==NULL)
        return ;
        
    queue<Node*> q;
    q.push(p);
    
    while(!q.empty())
    {
        int n = q.size();
        Node* prev=NULL;
        
        while(n--)
        {
            Node* temp = q.front();
            q.pop();
            
            if(prev)
                prev->nextRight=temp;
            
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            
            prev=temp;
        }
    }
}