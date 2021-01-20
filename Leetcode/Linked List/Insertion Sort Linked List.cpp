/* 
    A trivial solution is to use D&C which basically works from Top-Bottom but due to recursion the call stack would take O(logN) space.
    So we've to built our solution from bottom-top just as we did in `Merge K sorted list` i.e using step & length and increasing the step 2 times after every iteration.

    level 2        [ A0, A1, A2,  A3 ], [A4, A5, A6, A7] ,... , [ ..., An-2, An-1 ]
    level 1        [ A0, A1], [A2,  A3 ], [A4, A5], [A6, A7] ,... , [An-2, An-1]
    level 0        [ A0 ], [ A1] , [ A2 ],  [ A3 ],... , [ An-2 ], [ An-1 ]

    Idea is to first create sublist of size starting from 1 and increasing everytime with a multiple of 2. And to seperate the sublist from LL using spli() that Divide the linked list
    into two lists, while the first list contains first 'N' ndoes returns the second list's head.
    And to merge them we use tail, and points it's next to merge(left, right, tail) and later update/move forward it with pointer returned by merge()

    Follow Up: Merge Sort over Quick Sort?
    becz the memory allocation in linked list is diferent from arrays. As quick sort requires alot of random access to elements which isn't easy with
    linked list as it requires linaer time to reach a particular node. And also becz merge() of merge sort doesn't requires any extra space to merge to linked list which was required in case of
    arrays.
*/

// TC: O(NlogN) & Space: O(1)

class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
        if(!head || !head->next)
            return head;
        
        int n = 0;
        ListNode *runner = head;
        while(runner)
        {
            runner = runner->next;
            n++;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;    
        
        for(int step = 1; step<n; step*=2)
        {
            ListNode *curr = dummy->next, *left, *right, *tail = dummy;
            while(curr)
            {
                left = curr;
                right = split(left, step);
                curr = split(right, step);
                
                tail = merge(left, right, tail);    
            }
        }
        return dummy->next;
    }
    ListNode* split(ListNode *head, int n)
    {
        for(int i=1; head && i<n; i++)  // First list contains the first 'N' nodes so keep on shifting and later close the end to seperate
            head = head->next;
        
        ListNode *temp = NULL;
        if(head)
        {
            temp = head->next;  // return the head of second list
            head->next = NULL;  // first list contain first 'n' nodes, and now close the end of first chain
        }
        return temp;
    }
    ListNode* merge(ListNode *left, ListNode *right, ListNode *tail)
    {
        ListNode *curr = tail;     // We're not creating a new dummy node unlike typical merge functions becz here we need to set the sorted list head's to tail->next
        while(left && right)
        {
            if(left->val > right->val)
                curr->next = right, right = right->next;
            else
                curr->next = left, left = left->next;
            curr = curr->next;
        }
        curr->next = left?left:right;
        
        while(curr->next)   // As this is going to be the tail, which means this should be present at the end so keep on moving it towards the end
            curr = curr->next;
        return curr;
    }
};

/*  Using Top-Bottom D&C Approach TC: O(NlogN) & Space: O(logN)  */
class Solution {
private:
    ListNode* findMiddle(ListNode* head)
    {
        ListNode *slow = head, *fast = head, *pre;
        while(fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(pre)
            pre->next = NULL;
        return slow;
    }
    ListNode* merge(ListNode *left, ListNode *right)
    {
        if(!left)
            return right;
        if(!right)
            return left;
        
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        
        while(left && right)
        {
            if(left->val<right->val)
            {
                p->next = left;
                left = left->next;
            }
            else
            {
                p->next = right;
                right = right->next;
            }
            p = p->next;
        }
        p->next = left?left:right;
        return dummy->next;
    }
public:
    ListNode* sortList(ListNode* head) 
    {
        if(!head || !head->next)
            return head;
        
        ListNode *mid = findMiddle(head);
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        
        return merge(left, right);
    }  
};

/*  Insertion Sort 

    Here we maintain a partially sorted list, and iterate over the LL, once we find a node having value < previous node value. We pick this node and start scanning
    the partially sorted list to find it's correct position to insert and since this can be inserted at the start of the LL that's why we've used a dummy node.

    TC: O(N2) & Space: O(1);
*/

ListNode* insertionSortList(ListNode* head) 
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *pre = dummy, *curr = head;
    
    while(curr)
    {
        if(curr->next && (curr->next->val < curr->val)) // if curr->next->val < curr->val
        {
            ListNode *temp = curr->next->next;
            while(pre->next && pre->next->val < curr->next->val)   // find the correct position to insert this (curr->next) node
                pre = pre->next;
            
            curr->next->next = pre->next;
            pre->next = curr->next;
            curr->next = temp;
            pre = dummy;
        }
        else    // It might be the case that the next node in list is also < then curr->val that's why not shifting forward curr before checking
            curr = curr->next;
    }
    return dummy->next;
}