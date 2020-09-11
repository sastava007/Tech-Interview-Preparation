/*  One way is to recursively call isValiddBST() for each node, but this would require O(N^2) worst case in case of Skewed Tree.
    We can do it in O(N) using following property: 

    A Tree is BST if following is true for every node x.
            The largest value in left subtree (of x) is smaller than value of x.
            The smallest value in right subtree (of x) is greater than value of x.
    
    We can traverse the tree in bottom up manner, and for every traversed node we can return the maximum and minimum value in subtree rooted under current node

    TC: O(N) and Space: O(H)
*/

struct data
{
    int minele, maxele, size;
    bool isBST;
    data() : size(0), minele(INT_MAX), maxele(INT_MIN), isBST(false){}
};

class Solution {
public:
    int largestBSTSubtree(TreeNode *root) {
        if (root == NULL) 
        {
            return 0;
        }
        int ans =0;
        util(root, ans);
        return ans;
    }
private:
    data util(TreeNode *root, int &ans) 
    {
        data curr;
        if (root == nullptr) 
        {
            curr.isBST = true;
            return curr;
        }

        data left = util(root->left, ans);
        data right = util(root->right, ans);

        curr.minele = min(root->data, left->minele);
        curr.maxele = max(root->data, right->maxele);

        if (left.isBST && right.isBST && left->maxele < root->data && right->minele > root->data)      // we've assumed that BST is strict, without any duplicates else use (<= and >=)
        {
            curr.size = left->size + right->size + 1;
            cur.isBST = true;
            ans = max(ans, curr.size);
        }
        else 
        {
            curr.size = max(left.size, right.size);
            curr.isBST = false;
        }
        return curr;
    }
};