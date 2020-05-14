void util(Node* root, vector<Node*> v, unordered_set<Node*> &s, int k)
{
    if(root==NULL)
        return;
        
    v.emplace_back(root);
    
    if(!root->left && !root->right && v.size()>k)
        s.insert(v[v.size()-k-1]);
    
    //Here we've made 2 copies of vector, one for left and one for right subtree. Each copy of vector
    //will contain all ancestors will we reach the leaf node.
    
    util(root->left, v, s, k);
    util(root->right, v, s, k);
}

int printKDistantfromLeaf(Node* root, int k)
{
    if(root==NULL)
        return 0;
        
    vector<Node*> v;
    unordered_set<Node*> s;
    
	util(root, v, s, k);
	
	return s.size();
}