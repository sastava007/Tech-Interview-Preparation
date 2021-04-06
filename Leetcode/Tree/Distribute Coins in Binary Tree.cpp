/*
    There are total N nodes, and N coins that we've to find no. of moves to distribute coins such that each node has just 1 coin.
    If a node has 0 coin, then it has (-1 coins) in excess from what it needs, and let's say if a node has 4 coins then it has (3) excess coins.

    So idea is do a postorder traversal, and keep on finding the excess coins in subtree rooted under current node. 
    Where moves = abs(excess_in_left_subtree) + abs(excess_in_right_subtree). So the total #moves is basically given by the absolute sum of excess/ balaced/ leftover
    coins in left and right subtree.

    And excessCoins() is returning the #excess(+-) coins in subtree rooted under current node. 

    TC: O(N) & Space: O(H)
*/

class Solution {
public:
    int distributeCoins(TreeNode* root) 
    {
        int requiredMoves = 0;
        excessCoins(root, requiredMoves);
        return requiredMoves;
    }
private:
    int excessCoins(TreeNode* root, int &requiredMoves)
    {
        if(!root)
            return 0;
        int leftBalance = excessCoins(root->left, requiredMoves);
        int rightBalance = excessCoins(root->right, requiredMoves);
        requiredMoves += abs(leftBalance) + abs(rightBalance);  // Total moves will be simply sum of moves that we've to do to move coin b/w (root node-left child) + (root node-right child)
        
        return leftBalance + rightBalance + root->val -1;   // Return the no. of excess coins in subtree rooted under current node
    }
};