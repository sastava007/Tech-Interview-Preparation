/*  Print all paths from root to leaf node, this is the first solution using preorder traversal that hits me 
    But this will be O(n2), coz of vector printing. We can improve this using string which has constant time for pinting data
*/

vector<int> v;
void print()
{
    for(auto it:v)
        cout<<it<<" ";
        
    cout<<"#";
}
void printPathsUtil(Node* root)
{
    if(root==NULL)
        return ;
        
    v.emplace_back(root->data);
    
    printPathsUtil(root->left);
    printPathsUtil(root->right);
    
    if(root->left==NULL && root->right==NULL)
        print();
    
    v.pop_back();
}

void printPaths(Node* root)
{
    v.clear();
    printPathsUtil(root);
    cout<<"\n";
}

/* A O(n) solution using String */

void printPathsUtil(Node* root, string s)
{
    if(root==NULL)
        return;
    
    s=s+to_string(root->data);

    printPathsUtil(root->left, s+" ");
    printPathsUtil(root->right, s+" ");

    if(root->left==NULL && root->right==NULL)
        cout<<s<<" #";
}

void printPaths(Node* root)
{
    string str="";
    printPathsUtil(root, str);
    cout<<"\n";
}