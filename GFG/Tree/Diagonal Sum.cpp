void diagonalSum(Node* root, int d,  map<int, int> &m)
{
    if(root==NULL)
        return;
    
    m[d]+=root->data;
    diagonalSum(root->left, d+1, m);
    diagonalSum(root->right, d, m);
    
}
void diagonalSum(Node* root) 
{
    if(root==NULL)
        return;
    
    map<int, int> m;
    diagonalSum(root, 0, m);
    
    for(auto it: m)
        cout<<it.second<<" ";
}