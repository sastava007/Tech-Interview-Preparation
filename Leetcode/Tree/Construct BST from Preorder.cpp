/*
    Construct BST from preorder traversal, we know that first element of
   preorder is the root node then we can find the point of split 'i' preorder[i]
   > root node and make recursive calls for left and right subtree. TC: O(N^2)
   worst case when BST is skewed like [8,7,6,5,4,3,2,1] and O(NlogN) for avergae
   case
*/

class Solution {
public:
  TreeNode *bstFromPreorder(vector<int> &preorder) {
    if (preorder.empty())
      return NULL;
    return util(preorder, 0, preorder.size() - 1);
  }

private:
  TreeNode *util(vector<int> &preorder, int low, int high) {
    if (low > high)
      return NULL;

    TreeNode *node = new TreeNode(preorder[low]);
    // find the split point 'i', such that preorder[i] > preorder[start] or root
    // node value

    int index = find_if(preorder.begin() + low, preorder.begin() + high + 1,
                        [&](int val) { return val > preorder[low]; }) -
                preorder.begin();

    node->left = util(preorder, low + 1, index - 1);
    node->right = util(preorder, index, high);
    return node;
  }
};

/*
    Using characteristic property of BST which we used to validate whether given
   Tree is BST or not We know that all the values in left sub-tree is bounded by
   root->val, wheras the one in right subtree is bounded by parents root-val
   which could be INT_MAX for root node. TC:O(N)
*/

class Solution {
public:
  TreeNode *bstFromPreorder(vector<int> &preorder) {
    if (preorder.empty())
      return NULL;
    int index = 0;
    return util(preorder, index, INT_MAX);
  }

private:
  TreeNode *util(vector<int> &preorder, int &index, int bound) {
    if (index == preorder.size() || preorder[index] > bound)
      return NULL;

    TreeNode *root = new TreeNode(preorder[index++]);
    root->left = util(preorder, index, root->val);
    root->right = util(preorder, index, bound);
    return root;
  }
};