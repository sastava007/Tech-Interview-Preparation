/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    bool ans = true;
    int solve(Node* root){
        if(root==NULL) return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        
        if(root->left == NULL && root->right==NULL){
            return root->data;
        }
        
        if(root->data != (l+r)){
            ans = false;
        }
        
        return l + r + root->data;
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         
         ans = true;
         solve(root);
         return ans;
         
    }
};
