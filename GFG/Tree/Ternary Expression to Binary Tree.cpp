Node *convertExpression(string str, int i)
{
    if(str.length()==0)
        return NULL;
    
    Node* root = new Node(str[0]);
    
    stack<Node*> s;
    s.push(root);
    
    for(i=1; i<str.length(); i+=2)
    {
        if(str[i]=='?')
        {
            Node *node = new Node(str[i+1]);
            s.top()->left=node;
            s.push(node);
        }
        else if(str[i]==':')
        {
            Node *node = new Node(str[i+1]);
            s.pop();    //to remove the sibling node
            while(!s.top()->right==NULL)    //find the ancestor which don't have a right child yet
                s.pop();
            s.top()->right=node;
            s.push(node);
        }
    }
    
    return root;
}