/* 
    Sort a linked list using merge sort and O(1) space. A trivial solution is to use D&C which basically works from Top-Bottom but due to recursion the call stack would take O(logN) space.
    So we've to built our solution from bottom-top just as we did in merge K sorted list i.e using step & length and increasing the step 2 times after every iteration.

      ...
    level 2        [ A0, A1, A2,  A3 ], [A4, A5, A6, A7] ,... , [ ..., An-2, An-1 ]
    level 1        [ A0, A1], [A2,  A3 ], [A4, A5], [A6, A7] ,... , [An-2, An-1]
    level 0        [ A0 ], [ A1] , [ A2 ],  [ A3 ],... , [ An-2 ], [ An-1 ]

    Mrge sort is preferred over quick sort becz the memory allocation in linked list is diferent from arrays. As quick sort requires alot of random access to elements which isn't easy with
    linked list as it requires linaer time to reach a particular node. And also becz merge() of merge sort doesn't requires any extra space to merge to linked list which was required in case of
    arrays.

*/
class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
        if(!head || !head->next)
            return head;
        ListNode* curr = head;
        int length = 0;
        while(curr)
        {
            curr = curr->next;
            length++;
        }
        
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode *left, *right, *tail;
        
        for(int i=1; i<length; i *= 2)
        {
            curr = dummy.next;
            tail = &dummy;
            
            while(curr)
            {
                left = curr;
                right = split(left, i);
                curr = split(right, i);
                
                tail = merge(left, right, tail);
            }
        }
        return dummy.next;
    }
    
    private:
    ListNode* split(ListNode* head, int n)
    {
        for(int i=1; i<n && head; i++)
            head = head->next;
        
        if(!head)
            return NULL;
        
        ListNode *temp = head->next;
        head->next = NULL;
        return temp;
    }
    ListNode* merge(ListNode *l1, ListNode *l2, ListNode *head)
    {
        ListNode *cur = head;
		while(l1 && l2){
			if(l1->val > l2->val){
				cur->next = l2;
				cur = l2;
				l2 = l2->next;
			}
			else{
				cur->next = l1;
				cur = l1;
				l1 = l1->next;
			}
		}
		cur->next = (l1 ? l1 : l2);
		while(cur->next) cur = cur->next;
		return cur;
    }
};