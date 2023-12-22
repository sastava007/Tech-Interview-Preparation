/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  public:
    bool check(Node *root, int l, int h){
        if(!root) return false;
        if(l==h) return true;
        
        return check(root->left, l, root->data-1) or check(root->right, root->data+1, h);
    }
    bool isDeadEnd(Node *root)
    {
        //Your code here
        return check(root, 1, INT_MAX);
    }
};
