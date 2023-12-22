/* Tree node structure  used in the program
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int helper(Node* node, int &res){
        if(node==NULL){
            return 0;
        }
        
        int l = helper(node->left, res);
        int r = helper(node->right, res);
        
        int temp = max(l, r) + 1;
        
        int ans = max(temp, 1+l+r);
        
        res = max(res, ans);
        
        return temp;
    }
    int diameter(Node* root) {
        // Your code here
        int res = INT_MIN;
        helper(root, res);
        return res;
    }
};
