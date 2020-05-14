/* The idea is to simply iterate the main 'T' tree and whenever T->data == S->data we call for check functions which returns whether both the subtrees are
    identical or not.
    The helper function is simply checking two trees identical or not.

    This algo assumes that there will be no/less duplicate values, othewise TC increase.
    O(n) if no duplicate value
*/

bool areEqual(Node* t, Node* s)
{
     if(!t && !s)
        return true;
    
    if(!t || !s)
        return false;
        
    if(t->data==s->data)
    {
        bool left = areEqual(t->left, s->left);
        bool right = areEqual(t->right, s->right);
        
        return (left&&right);
    }
    
    return false;
}

bool isSubTree(Node* t, Node* s)
{
    if(!t && !s)
        return true;
    
    if(!t || !s)
        return false;
        
    if(t->data == s->data)
    {
        bool check = areEqual(t,s);
        if(check)
            return true;
    }
    
    return (isSubTree(t->left, s) || isSubTree(t->right, s));

}