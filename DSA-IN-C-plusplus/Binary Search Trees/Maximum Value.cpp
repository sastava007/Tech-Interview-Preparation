//User function Template for C++
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */

class Solution {
  public:
    vector<int>ans;
    void tree(Node* root, int level){
        if(root==NULL) return;
        
        if(ans.size() == level) ans.push_back(root->data);
        else ans[level] = max(root->data, ans[level]);
        
        tree(root->left, level+1);
        tree(root->right, level+1);
    }
    vector<int> maximumValue(Node* node) {
        //code here
        
        tree(node, 0);
        return ans;
    }
};
