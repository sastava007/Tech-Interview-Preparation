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
            p1 = p1==NULL?headB:p1->next;
            p2 = p2==NULL?headA:p2->next;
        }
        
        return p1;
    }
};