/*  
    One way is to recursively find the mid of LL using slow & fast pointers and then disconnect the portion of list to the left of the middle element. And then processing the list, bt this method
    takes O(nlogn) time as to find mid element it take O(n) time but each time basically we ae decesing out list into 2 halves. So the complexity get redced to O(nlogn)

    But a better solu. will be to maintain a global copy of variable and find the size once, and similar as we do with arrays, process thiis list. This takes O(n) time and O(1) space. 

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
        
        TreeNode* temp = new TreeNode(node->val);
        temp->left = left;
        
        node = node->next;  //move to next element in sequece
        
        temp->right = util(mid+1, high);
        return temp;
    }
};
