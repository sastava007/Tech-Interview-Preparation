//get height of a binary tree or maximum depth
int height(Node* node)
{
   if(node==NULL)
    return 0;
    
    int left_height = height(node->left);
    int right_height = height(node->right);
    
    return (max(left_height, right_height) + 1);
}

//inorder traversal: traverse left subtree, visit root node, traverse right subtree
void inorder(Node* root)
{
    if(root==NULL)
        return;
        
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
//inorder traversal: Without Recursion using Stack
void inorder(Node* root)
{
    stack<Node*> s;
    Node* curr = root;

    while (!s.empty() || curr)
    {
        if(curr)
        {
            s.push(curr);
            curr=curr->left;    //going left
        }
        else
        {
            curr = s.top();   //going top
            s.pop();
            cout<<curr->data<<" ";

            curr=curr->right;    //going right
        }
    }
    
}


//preorder traversal: visit root, traverse left subtree, traverse right subtree
void preorder(Node* root)
{
  if(root==NULL)
    return;
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
//preorder traversal: Without Recursion using Stack
void preorder(Node* root)
{
    stack<Node*> s;
    Node* curr = root;
    while (!s.empty() || curr)
    {
        if(curr)
        {
            cout<<curr->data<<" ";
            s.push(curr);
            curr=curr->left;    //going left
        }
        else
        {
            curr=s.top();   //going top
            s.pop();

            curr=curr->right;   //going right
        }
    }
}

//postorder traversal: traverse left subtree, traverse right subtree, visit root
void postOrder(Node* root)
{
  if(root==NULL)
    return;
    
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
    
}
//postorder traversal: Without Recursion using Stack
void postOrder(Node* root)
{
    stack<Node*> s;
    stack<int> s1;
    Node* curr = root;
    //The idea is to push reverse postorder traversal to a stack, Now the question is, how to get reversed postorder elements in a stack
    //If take a closer look at this sequence, we can observe that this sequence is very similar to the preorder traversal. The only difference is that the right child is visited before left child,
    //and therefore the sequence is “root right left”
    
    while (!s.empty() || curr)
    {
        if(curr)
        {
            s1.push(curr->data);
            s.push(curr);
            curr=curr->right;    //going left
        }
        else
        {
            curr=s.top();   //going top
            s.pop();

            curr=curr->left;   //going right
        }
    }

    while(!s1.empty())
    {
        cout<<s1.top()<<" ";
        s1.pop();
    }
}


//level order traversal
void levelOrder(Node* node)
{
    if(node==NULL)
    return;
    
    queue<Node*> q;
    q.push(node);
    
    while(!q.empty())
    {
        Node* temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}

//A leaf node has it's both, left & right children NULL so when we encounter any such position return 1, else keep on exploring it's left & right subtree.
int countLeaves(Node* root)
{
    if(root==NULL)
        return 0;
        
    if(root->left==NULL && root->right==NULL)
        return 1;
    
    int left=countLeaves(root->left);
    int right=countLeaves(root->right);
    
    return left+right;
}

//Non leaves node
int countNonLeafNodes(Node* root)
{
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return 0;
        
    int left=countNonLeafNodes(root->left);
    int right=countNonLeafNodes(root->right);
    
    return (left+ right + 1);
    
}

//convert a binary tree to it's mirror trees
void mirror(Node* node) 
{
    if(node==NULL)
        return;
    
    mirror(node->left);
    mirror(node->right);
    
    Node* temp=node->left;
    node->left=node->right;
    node->right=temp;
}

//is Tree identical
bool isIdentical(Node *r1, Node *r2)
{
    if((r1==NULL && r2!=NULL) || (r1!=NULL && r2==NULL))
        return false;
    if(r1==NULL && r2==NULL)
        return true;
        
    bool leftIdentical = isIdentical(r1->left, r2->left);
    bool rightIdentical = isIdentical(r1->right, r2->right);
    
    return ((r1->data==r2->data) && leftIdentical && rightIdentical);
        
}