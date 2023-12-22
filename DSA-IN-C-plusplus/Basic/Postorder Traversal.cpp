

//User function Template for C++

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */

//Function to return a list containing the postorder traversal of the tree.

void solve(Node* root, vector<int>&ans){
    if(root==NULL) return;
    
    solve(root->left, ans);
    solve(root->right, ans);
    ans.push_back(root->data);
}
vector <int> postOrder(Node* root)
{
  // Your code here
  vector<int>ans;
  solve(root, ans);
  return ans;
}
