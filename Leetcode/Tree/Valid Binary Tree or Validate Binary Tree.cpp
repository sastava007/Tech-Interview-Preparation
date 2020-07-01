/* GIven a set of nodes, check if they all represent the nodes of a single binary tree */

/*
    Idea is to maintain 2 hash-set, first one containing set of all candidate root nodes and other one storing all the seen nodes. For each node in list, check if it's aready seen, then continue
    otherwise check this tree hasCycle, and while doing so add all the nodes rooted under current node to seen.
    To check for hasCycle, if a node has already been seen then return true otherwise look in's left & right subtree.

    Note: here we're given the structure of TreeNode as containing only (left* & right*), so that's why we're not checking for more than 2 childrens
*/

bool isBinaryTree(vector<TreeNode*> nodes) 
{
    unordered_set<TreeNode*> roots, seen;
    roots.insert(nodes.begin(), nodes.end());   // possible candidates to become root

    for (TreeNode* cur : nodes)
    {
        if (seen.find(curr) != seen.end()) 
            continue;

        unordered_set<TreeNode*> curSeen;
        if (hasCycle(cur,roots,curSeen)) 
            return false;
        seen.insert(curSeen.begin(), curSeen.end());
        roots.add(cur);
    }
    return roots.size() == 1 && seen.size() == nodes.size();    //checking equal to seen.size() becz it may be possible that some nodes aren't there in list, but connected with tree
}
bool hasCycle(TreeNode* cur, Set<TreeNode*> &roots, Set<TreeNode*> &curSeen) 
{
    if (cur == null) return false;
    if (curSeen.find(curr) != curSeen.end()) 
        return true;
    curSeen.add(cur);   // mark current node as seen
    roots.erase(cur);  // as current node has been accesed by some other node, which means this can't be a root node, so remove it from here
    return hasCycle(cur.left,roots,curSeen) || hasCycle(cur.right,roots,curSeen);
}

/* 

        1               
       ↙ ↘              
      2   3             
         ↙          
        4               
     "true"   


    	 1
       ↙  ↘
      2    3
       ↘  ↙
        4
     "false"


    	1           4
       ↙ ↘        ↙  ↘
      2   3      5     6

          "false"

          1
        ⤤ ⤦
         2
      "false"

    	1
       ↙ ↘
      2   3
         ↙
        4
    "false"  becz here n4 was not included in list  [n1,n2,n3] 
*/