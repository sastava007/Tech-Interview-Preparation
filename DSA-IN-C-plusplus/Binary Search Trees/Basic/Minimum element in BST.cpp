// Recursive Solution

int minValue(Node* root) {
    // Code here
    if(root == NULL){
        return -1;
    }
    
    if(root->left == NULL){
        return root->data;
    }
    
    minValue(root->left);
}

// Iterative

int minValue(Node* root) {
    // Code here
    if(root == NULL){
        return -1;
    }
    
    while(root->left != NULL){
        root = root->left;
    }
    
    return root->data;
}
