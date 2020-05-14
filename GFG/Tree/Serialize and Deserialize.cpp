void serialize(Node *root,vector<int> &A)
{
    if(root==NULL)
    {
        A.emplace_back(-1);
        return;
    }
    A.emplace_back(root->data);
    serialize(root->left, A);
    serialize(root->right, A);
}

Node * deSerialize(vector<int> &A, int &pointer)
{
    if(A.size()==0 || A[pointer]==-1)
    {
        pointer++;
        return NULL;
    }
    
    Node* temp = new Node(A[pointer]);
    pointer++;
        
    temp->left=deSerialize(A, pointer);
    temp->right=deSerialize(A, pointer);
    
    return temp;
}
Node * deSerialize(vector<int> &A)
{
    int pointer = 0;
    return deSerialize(A, pointer);
}