set<int> s;
void printSiblingUtil(Node* node)
{
    if(node==NULL)
    return;
    
    if(node->left && !node->right)
        s.insert(node->left->data);
    if(!node->left && node->right)
        s.insert(node->right->data);    
    
    printSiblingUtil(node->left);
    printSiblingUtil(node->right);
}

void printSibling(Node* node)
{
   s.clear();
   printSiblingUtil(node);
   if(!s.size())
    cout<<"-1";
    else
    {
        for(auto it: s)
            cout<<it<<" ";
    }
}   