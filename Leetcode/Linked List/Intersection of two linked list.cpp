/*  Find the point of intersection of 2 linked list, we can assume that there's no cycle in linked list 
    
    Idea: Is to use 2 pointers to traverse the list, and whenever we reach the end of one list then we made it to point to head of other list and we keep on doing so untill we reach/found a 
    common node.

    Why this works?
    Consider 2 lists A=[1,3,5,7,9,11] and B=[2,4,9,11] here list B is 2 node smaller hence it will reach the end first, so our idea is to somehow able to made it cover two extra nodes by 
    pointing it to A. As it covers 2 extra node, so now both can reach the point of intersection at the same time.

    TC: O(M+N) and Space: O(1)
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if(headA==NULL || headB==NULL)      // if there's just one list, then there can't be any point of intersection so just return NULL
            return NULL;
        
        ListNode *p1 = headA, *p2 = headB;
        while(p1 != p2)
        {
            p1 = p1==NULL?headB:p1->next;   // Don't check for p1->next, coz that way we'll never reach the same node is there's no intersection 
            p2 = p2==NULL?headA:p2->next;
        }      
        return p1;
    }
};

/* 

    You can prove that: say A length = a + c, B length = b + c, after switching pointer, pointer A will move another b + c steps, pointer B will move a + c more steps, 
    since a + c + b + c = b + c + a + c, it does not matter what value c is. Pointer A and B must meet after a + c + b (b + c + a) steps. If c == 0, they meet at NULL. 

*/