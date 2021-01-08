/* For reversing the linked list just focus on reversing the direction of arrow */

class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* prev=NULL;
        while(head)
        {
            ListNode* temp = head->next;
            head->next = prev;
            prev=head;
            
            head = temp;
        }
        return prev;
    }

    /* Using Recursion */
    
    ListNode* reverseList(ListNode* head) 
    {
        return util(head, NULL);
    }
    ListNode* util(ListNode* head, ListNode* prev)
    {
        if(head==NULL)
            return prev;
        ListNode* temp = head->next;
        head->next = prev;
        prev = head;
        return util(temp, prev);
    }
};

/*  Reverse the LL b/w m-n(both inclusive). Assume this as partitioing the list into 3 parts and reversing the middle most part. We'll use conection and tail variables to connect the first - second
    part and second-third part respectively.

*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        if(head==NULL)
            return NULL;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(m>1)
        {
            prev=curr;
            curr=curr->next;
            m--;
            n--;
        }
        
        ListNode *connection=prev, *tail=curr;
        while(n>0)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            n--;
        }
        
        if(connection != NULL)
            connection->next = prev;
        else
            head = prev;
        
        tail->next = curr;
        return head;
    }
};