/*
    Quite famous problem, this one can be solved using 2 Stack, 1 Stack - 1 Queue, and Deque
*/

void printSpiral(Node *root)
{
    if(root==NULL)
        return ;
        
    stack<Node*> s1, s2;
    s1.push(root);
    
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            Node*temp=s1.top();
            s1.pop();
            
            cout<<temp->data<<" ";
            
            if(temp->right)
                s2.push(temp->right);
            if(temp->left)
                s2.push(temp->left);
        }
        
        while(!s2.empty())
        {
            Node*temp=s2.top();
            s2.pop();
            
            cout<<temp->data<<" ";
            
            if(temp->left)
                s1.push(temp->left);
            if(temp->right)
                s1.push(temp->right);
        }
    }
}


/*  This can also be solved using Deque. 
    The idea is to use a direction variable and decide whether to pop elements from the front or from the rear based on the value of this direction variable.
*/

void printSpiral(Node *root)
{
    if(root==NULL)
        return ;
        
    deque<Node*> q;
    q.push_back(root);
    
    bool dir=true;
    
    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            if(dir)
            {
                Node* temp=q.back();
                q.pop_back();
                
                cout<<temp->data<<" ";
                if(temp->right)
                    q.push_front(temp->right);
                if(temp->left)
                    q.push_front(temp->left);
            }
            else
            {
                Node* temp=q.front();
                q.pop_front();
                
                cout<<temp->data<<" ";
                if(temp->left)
                    q.push_back(temp->left);
                if(temp->right)
                    q.push_back(temp->right);
            }
        }
        dir=!dir;
    }
}