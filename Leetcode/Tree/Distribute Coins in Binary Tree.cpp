/*
    There are total N nodes, and N coins that we've to find no. of moves to distribute coins such that each node has just 1 coin.
    If a node has 0 coin, then it has (-1 coins) in excess from what it needs, and let's say if a node has 4 coins then it has (-3) excess coins.

    So idea is do a postorder traversal, and keep on finding the excess coins in subtree rooted under current node. 
    Where moves = abs(excess_in_left_subtree) + abs(excess_in_right_subtree)
*/

class Solution {
public:
    int distributeCoins(TreeNode* root) 
    {
        int moves = 0;
        excess(root, moves);
        return moves;
    }
    
    int excess(TreeNode* root, int &moves) 
    {
        if(root==NULL)
            return 0;
        int leftBalance = excess(root->left, moves);
        int rightBalance = excess(root->right, moves);
        
        moves += abs(leftBalance) + abs(rightBalance);
        
        return root->val + leftBalance + rightBalance -1;     // return the no. of excess coins in subtree rooted under current node
    }
};