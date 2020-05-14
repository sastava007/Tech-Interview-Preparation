/* Left view Using Recursion */
void leftViewUtil(Node *root, int level, int &maxLevel)
{
    if(root==NULL)
        return ;
    
    if(level>maxLevel)
    {
        cout<<root->data<<" ";
        maxLevel=level;
    }
    
    leftViewUtil(root->left, level+1, maxLevel);
    leftViewUtil(root->right, level+1, maxLevel);
}
void leftView(Node *root)
{
    int maxLevel=-1;
    leftViewUtil(root, 0, maxLevel);
}

/* Left view Without Recursion */
void leftView(Node* node)
{
    if(node==NULL)
    return;
    
    queue<Node*> q;
    q.push(node);
    
    while(!q.empty())
    {
        cout<<q.front()->data<<" ";
        int size = q.size();
        while(size--)
        {
            Node* temp = q.front();
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}


/* Right View without using Recursion */
void rightView(Node* node)
{
    if(node==NULL)
    return;
    
    queue<Node*> q;
    q.push(node);
    
    while(!q.empty())
    {
        cout<<q.front()->data<<" ";
        int size = q.size();
        while(size--)
        {
            Node* temp = q.front();
            q.pop();
            
            if(temp->right)
                q.push(temp->right);
            if(temp->left)
                q.push(temp->left);
        }
    }
}