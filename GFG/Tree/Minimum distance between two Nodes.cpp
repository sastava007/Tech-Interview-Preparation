/* The idea is simple to, first find the LCA the point from which both the nodes diverges then from LCA we can either traverse both sides to find
    distnace to the n1 & n2 nodes. Or we can find distance of 'A', 'B' and lca from root node and use the formula

    Dist(n1, n2) = Dist(root, n1) + Dist(root, n2) - 2*Dist(root, lca)

  */

 Node* LCA(Node* root, int a, int b)
{
    if(root==NULL)
        return NULL;
        
    if(root->data==a || root->data==b)
        return root;
    
    Node* left = LCA(root->left, a, b);
    Node* right = LCA(root->right, a, b);
    
    if(left&&right)
        return root;
    
    if(left)
        return left;
    else
        return right;
}

void getDistance(Node* root, int a, int b, int lca, int &disA, int &disB, int &disLca)
{
    if(root==NULL)
        return ;
        
    queue<Node*> q;
    q.push(root);
    
    int level=0;
    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            if(q.front()->data==a)
                disA = level;
            if(q.front()->data==b)
                disB = level;
            if(q.front()->data==lca)
                disLca = level;
                
            if(q.front()->left)
                q.push(q.front()->left);
            if(q.front()->right)
                q.push(q.front()->right);
                
            q.pop();
        }
        level++;
    }
}

int findDist(Node* root, int a, int b) 
{   
    if(root==NULL)
        return 0;
        
    Node* lca = LCA(root, a, b);
    int disA=0, disB=0, disLca=0;
    
    getDistance(root, a, b, lca->data, disA, disB, disLca);
    
    return (disA+disB-2*disLca);
    
}