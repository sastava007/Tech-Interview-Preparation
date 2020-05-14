void leftView(Node *root)
{
    if(root==NULL)
        return ;
    
    if(root->left)
    {
        cout<<root->data<<" ";
        leftView(root->left);
    }
    else if(root->right)
    {
        cout<<root->data<<" ";
        leftView(root->right);
    }
}
void rightView(Node *root)
{
    if(root==NULL)
        return ;
        
    if(root->right)
    {
        rightView(root->right);
        cout<<root->data<<" ";
    }
    else if(root->left)
    {
        rightView(root->left);
        cout<<root->data<<" ";
    }
    
}
void leafView(Node *root)
{
    if(root==NULL)
        return ;
        
    if(!root->left && !root->right)
    {
        cout<<root->data<<" ";
        return ;
    }
        
    leafView(root->left);
    leafView(root->right);
}

void printBoundary(Node *root)
{
    if(root==NULL)
        return ;
    cout<<root->data<<" ";
    
    leftView(root->left);
        
    leafView(root);
    
    rightView(root->right);
}