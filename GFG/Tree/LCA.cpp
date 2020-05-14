/*  This method assumes that both keys are present in Binary Tree. If one key is present and other is absent, then it returns the present key as LCA 
    (Ideally should have returned NULL).
*/

Node* lca(Node* root ,int n1 ,int n2 )
{
    if(root==NULL)
        return NULL;
    
    if(root->data==n1 || root->data==n2)
        return root;
    
    Node* left=lca(root->left, n1, n2);
    Node* right=lca(root->right, n1, n2);
    
    if(left && right)
        return root;
        
    return (left != NULL)? left:right;
}

/*  We can extend this method to handle all cases by passing two boolean variables v1 and v2.
    v1 is set as true when n1 is present in tree and v2 is set as true if n2 is present in tree.   
    In worst case we have to traverse 3 times
*/

Node* lcaUtil(Node* root, int n1, int n2, bool &v1, bool &v2)
{
    
    if(root==NULL)
        return NULL;
        
    if(root->data==n1)
    {
        v1=true;
        return root;
    }
    
    if(root->data==n2)
    {
        v2=true;
        return root;
    }
    
    Node* left=lcaUtil(root->left, n1, n2, v1, v2);
    Node* right=lcaUtil(root->right, n1, n2, v1, v2);
    
    if(left && right)
        return root;
        
    return (left != NULL)? left:right;
}

bool find(Node* root, int k)    //check if key k is rooted under current node
{
    if(root==NULL)
        return true;
    
    bool left=find(root->left, k);
    bool right=find(root->right, k);
    
    return (root->data==k || left || right);
}

Node* lca(Node* root ,int n1 ,int n2 )
{
    if(root==NULL)
        return NULL;
    bool v1=false,v2=false;
    
    Node* lca = lcaUtil(root, n1, n2, v1, v2);
    
    if(v1&&v2 || (v1&&find(lca, n2)) || (v2&&find(lca, n1)))
        return lca;
        
    return NULL;
}