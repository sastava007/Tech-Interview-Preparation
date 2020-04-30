/*
    We have to find level with maximum no. of nodes, if two level has same node then the one closest to root node will be our answer. 

    In questions involving level order traversal, try to use unordered_map<> to map the count of elements at each level. And once we have total nodes at each level, we can simply find maximum of them.
    To get count of nodes at each level, pass level no as parameter and increase the counter of that level into the unordered_map.

*/

unordered_map<int, int> m;
int maxlevel=0, maxnode=0;

void maxNodeLevelUtil(Node *root, int level)
{
    if(root==NULL)
        return ;
    
    m[level]++;
    
    if(m[level]>maxnode)
    {
        maxnode=m[level];
        maxlevel=level;
    }
    else if(m[level]==maxnode && level<maxlevel)
    {
        maxlevel=level;
    }
    
    maxNodeLevelUtil(root->left, level+1);
    maxNodeLevelUtil(root->right, level+1);
 
}
int maxNodeLevel(Node *root)
{
    m.clear();
    maxnode=0,maxlevel=0;
    
    maxNodeLevelUtil(root, 0);
    
    return maxlevel;
}