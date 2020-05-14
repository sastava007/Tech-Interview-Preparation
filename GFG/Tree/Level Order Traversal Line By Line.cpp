/*
    The important concept that I learned from this problem is that `nodeCount = q.size()` gives the number of nodes which are present at current level
    And we have to exactly run the internal node this number of times, becz we have to extract child nodes of current nodes and push them in queue.
*/

void levelOrder(Node* node)
{
    if(node==NULL)
        return ;
    
    queue<Node*> q;
    q.push(node);
    
    while(!q.empty())
    {
        //this represents number of nodes at current level, we are running internal loop this number of times bcoz we have to extract child nodes of all nodes which are present at current level
        int nodeCount=q.size();
        
        while(nodeCount--)
        {
            Node* temp = q.front();
            q.pop();
            
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        cout<<"$ ";
    }
}

/* Print level at distance K from root */
void printKdistance(struct Node *root, int k)
{
    if(root==NULL)
        return;
        
    if(k==0)
        cout<<root->data<<" ";
    
    if(k>0)
    {
        printKdistance(root->left, k-1);
        printKdistance(root->right, k-1);
    }
}