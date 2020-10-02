Node *lca(Node *root, int v1,int v2) 
{
    Node *temp=root;
    while(1)
    {
        if(v1==temp->data || v2==temp->data)
        {
            return temp;
        }
        else if(v1<temp->data && v2<temp->data)
        {
            temp=temp->left;
        }
        else if(v1>temp->data && v2>temp->data)
        {
            temp=temp->right;
        }
        else
        {
            return temp;
        }
    }
}