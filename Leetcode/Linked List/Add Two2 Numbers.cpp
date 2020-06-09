/*  TC: O(max(m,n)) and Space O(max(m,n)) 
    The algorithm above iterates at most max(m,n) times and length of new string would be maximum of length O(m,n)+1

*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode prehead(0);
        ListNode* p = &prehead;
        
        int carry = 0;
        
        while(l1 || l2 || carry)
        {
            int a=0, b=0;
            
            if(l1)
            {
                a=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                b=l2->val;
                l2=l2->next;
            }
            
            int sum = a+b+carry;
            p->next = new ListNode(sum%10);
            p=p->next;
            
            carry=sum<10?0:1;
        }
        
        return prehead.next;
    }
};