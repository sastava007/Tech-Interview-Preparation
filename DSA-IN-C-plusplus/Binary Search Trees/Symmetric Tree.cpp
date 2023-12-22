class Solution{
    public:
    
    bool inorder(Node* root1, Node* root2){
        
        if(root1==NULL || root2==NULL){
            return root1 == root2;
        }
        
        return (root1->data == root2->data) && inorder(root1->left, root2->right) && inorder(root1->right, root2->left);
        
        
    }
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    if(root==NULL) return true;
	    
	    return inorder(root->left, root->right);
    }
};

