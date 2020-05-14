/* The intution for this problem can be made from maximum width of BT, where we maintained a level and id */
/*  We just need to keep traversing, and everytime we go left decrease the horizontal distance by 1 and every time we go to right increase by 1 
    But, make sure that we're doing this by level order traversal otherwise through preorder it may be possible that a node may come before than it's top node

             1
          /     \
         2       3
        /  \    /  \
       4    5  6    7
                \  /  \
                 8 10  9 
                     \
                     11
                       \
                        12      

    Like here using preorder we get 12 before 9.

*/



// PS: here 'level' actually means horizontal distance(hd) and not level which is technically wrong.

void verticalOrderUtil(Node* root, map<int, vector<int>> &m)
{
    if(root==NULL)
        return;
        
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    
    while(!q.empty())
    {
        pair<Node*, int> temp = q.front();
        q.pop();
        
        m[temp.second].emplace_back(temp.first->data);
        
        if(temp.first->left)
            q.push({temp.first->left, temp.second-1});
        if(temp.first->right)
            q.push({temp.first->right, temp.second+1});
    }
}

void verticalOrder(Node *root)
{
    if(root==NULL)
        return;
        
    map<int, vector<int>> m;
    verticalOrderUtil(root, m);
    
    for(auto it: m)
        for(auto jt: it.second)
        {
            cout<<jt<<" ";
        }
}