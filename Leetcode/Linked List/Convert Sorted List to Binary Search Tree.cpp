/*  
    1. One way is to recursively find the mid of LL using two pointer approach (slow & fast pointers) and then disconnect the portion of list to the left of the middle element. And then processing the list, bt this method takes O(nlogn) time as to find mid element it take O(n) time but each time basically we ae decesing out list into 2 halves. So the complexity get redced to O(nlogn)
    2. Convert LL to array, and then we can access the middle element in O(1). This way we can build the tree in O(N) time and O(N) extra space.

    ```Simulate the Inorder Traversal```

    Using the idea, that inorder tarversal of BST gives a sorted array. So once we calculate the size of the linked list, we can use that to parse our list and build the tree.
    This takes O(n) time and O(logN) space due to recursive stack calls. 

*/

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        int size = sizeOfList(head);
        node = head;
        return util(0, size-1);
    }
private:
    ListNode* node;     //global copy to store the head of linked list
    
    int sizeOfList(ListNode* head)
    {
        int c=0;
        ListNode* temp = head;
        while(temp)
        {
            c++;
            temp=temp->next;
        }
        return c;
    }
    TreeNode* util(int low, int high)
    {
        if(low>high)
            return NULL;
        
        int mid = (low+high)/2;
        TreeNode* left = util(low, mid-1);
        
        TreeNode* temp = new TreeNode(node->val);   // When we're done building the left subtree then add the value the value at head to root node and shift the head.
        temp->left = left;
        
        node = node->next;  //move to next element in sequence
        
        temp->right = util(mid+1, high);
        return temp;
    }
};
