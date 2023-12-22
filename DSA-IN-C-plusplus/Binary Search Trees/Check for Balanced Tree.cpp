  int height(Node* root){
        if(root == NULL)
            return 0;
        
        int l = height(root->left)+1;
        int r = height(root->right)+1;
        
        return max(l,r);
    }
    
    bool isBalanced(Node *root)
    {
        //  Your Code here
         if(root==NULL)
            return true;
        
        int l = height(root->left);
        int r = height(root->right);
        
        if(abs(l-r) > 1)
            return false;
            
        return isBalanced(root->left) && isBalanced(root->right);
        
    }
