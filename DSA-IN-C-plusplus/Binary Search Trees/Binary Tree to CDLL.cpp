/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    Node* prev = NULL, *head = NULL;
    
    void inorder(Node *root){
        if(!root) return;
        inorder(root->left);
        if(!head) head = prev = root;
        else{
            prev->right = root;
            root->left = prev;
        }
        
        prev = root;
        inorder(root->right);
    }
  public:
    //Function to convert binary tree into circular doubly linked list.
    Node *bTreeToCList(Node *root)
    {
        //add code here.
        inorder(root);
        head->left = prev;
        prev->right = head;
        return head;
        
    }
};
