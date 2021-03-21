/* The idea is to simply iterate the main 'T' tree and whenever T->data == S->data we call for check functions which returns whether both the subtrees are
    identical or not.
    The helper function is simply checking two trees identical or not.

    This algo assumes that there will be no/less duplicate values, othewise TC increase.
    O(n) if no duplicate value
*/

bool isIdentical(Node* t, Node* s)
{
    if(!t && !s)
        return true;
    if(!t || !s)
        return false;
    
    return (t->data==s->data && isIdentical(t->left, s->left) && isIdentical(t->right, s->right));
}
bool isSubTree(Node* t, Node* s) 
{
    if(!t && !s)
        return true;
    if(!t || !s)
        return false;
        
    if(t->data==s->data && isIdentical(t, s))
        return true;
    
    return isSubTree(t->left, s) || isSubTree(t->right, s);
}

/* 
    Using Inorder & Preorder Traversal  TC: O(N) 
    but giving segmentation fault on GFG
*/

string inorder(Node* root)
{
    if(!root)
        return "#";
    return inorder(root->left) + to_string(root->data) + inorder(root->right);
}

string preorder(Node* root)
{
    if(!root)
        return "#";
    return to_string(root->data) + preorder(root->left) + preorder(root->right);
}

bool isSubTree(Node* t, Node* s) 
{
    if(!t && !s)
        return true;
    if(!t || !s)
        return false;
    
    string in_t = inorder(t);
    string in_s = inorder(s);
    string pre_t = preorder(t);
    string pre_s = preorder(s);
    
    return in_t.find(in_s) != string::npos && pre_t.find(pre_s) != string::npos;
}