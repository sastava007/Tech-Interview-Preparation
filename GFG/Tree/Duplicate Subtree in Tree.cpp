/*  We have to find whether the binary tree contains a duplicate sub-tree of size two or more. We don't need to consider leaf nodes, because they are of 
    size 1. Here size means height.

    Approach: Tree Serialization + Hashing

    We can traverse the tree, and keep storing the subtrees that we encounter so far in form of string in a hashset and once we get a string which is 
    already present then it means we have duplicate subtrees in our tree.
*/

string dupSubUtil(Node* root, unordered_set<string> &m, bool &flag)
{
    if(root==NULL)
        return "";
        
    if(!root->left && !root->right)
    {
        string s(1, root->data);
        return s;
    }
    
    string left = dupSubUtil(root->left, m, flag);
    string right = dupSubUtil(root->right, m, flag);

    string s = left + root->data + right;
    if(m.find(s) != m.end())
    {
        flag=true;
    }
    else
    {
        m.insert(s);
    }
    
    return s;
}

bool dupSub(Node *root)
{
    if(root==NULL)
        return false;
    
    unordered_set<string> m;
    bool flag = false;
    
    string dump = dupSubUtil(root, m, flag);
    
    return flag;
}