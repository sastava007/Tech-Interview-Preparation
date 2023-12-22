

// Function to search a node in BST.
bool search(Node* root, int x) {
    // Your code here
    if(root == NULL) return false;
    if(root->data == x) return true;
    
    return (root->data>x) ? search(root->left, x) : search(root->right, x);
}
