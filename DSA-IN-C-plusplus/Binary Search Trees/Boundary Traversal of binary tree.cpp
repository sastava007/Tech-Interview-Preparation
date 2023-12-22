/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:

    void left(Node* root, vector<int>&ans){
        if(root==NULL) return;
        if(root->left == NULL && root->right==NULL) return;
        
        ans.push_back(root->data);
        if(root->left == NULL && root->right != NULL) left(root->right, ans);
        else left(root->left, ans);
    }
    
    
    void leaf(Node* root, vector<int>&ans){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
        }
        
        leaf(root->left, ans);
        leaf(root->right, ans);
    }
    
    void right(Node* root, vector<int>&ans){
        if(root==NULL) return;
        if(root->left == NULL && root->right == NULL) return;
        
        if(root->right == NULL && root->left != NULL){
            right(root->left, ans);
        }
        
        else{
            right(root->right, ans);
        }
        
        ans.push_back(root->data);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        
        if(root == NULL) return ans;
        
        if(root->left == NULL && root->right==NULL){
            ans.push_back(root->data);
            return ans;
        }
        
        ans.push_back(root->data);
        
        left(root->left, ans);
        leaf(root, ans);
        right(root->right, ans);
        return ans;
    }
};
