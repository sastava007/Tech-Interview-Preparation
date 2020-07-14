/*  
    If the list is immutable, then we can divide the list into sqrt(N) buckets, where each bucket stores the starting node of that group of elements. And then we can traverse each bucket
    from ending and keep on adding the elements in a vector. Later we can print all the elements of that vector in reverse order and we do this for each bucket.

    So this way we only need sqrt(N) elements to store at a time.

    Time: O(N) and Space: O(sqrt(N))
    list = [1-2-3-4-5-6-7-8-9],  buckets = [1,4,7]
    We first pick 7, traverse all it's node store them in a vector as [7->8->9] and later print them in reverse order.
    Similarly we've to this for each bucket.

*/

void printLinkedListInReverse(Node* head) 
{
    if(head == NULL)
        return;

    int count = 0;
    Node* curr = head;
    while(curr)
    {
        curr = curr->next;
        count++;
    }

    int bucket_count = ceil(sqrt(count));
    curr = head;
    vector<Node*> buckets;

    while(curr)
    {
        if(count % bucket_count == 0)   // this help us to store only first element of each bucket
            buckets.emplace_back(curr);
        curr = curr->next;
        count++;
    }

    for(int i=buckets.size()-1; i>=0; i--)
    {
        printNodes(buckets[i], bucket_count);
    }
}
void printNodes(Node* head, int count)
{
    vector<Node*> nodes;
    while(head && node.size()!=count)   // if we've lesser nodes than bucket_size, specially in case if it;s last node
    {
        node.emplace_back(head);
        head = head.size();
    }

    for(int i=nodes.size()-1; i>=0; i--)
        cout<<nodes[i]->val<<"  ";
}


/* If the input linked list is mutable, then we can simply modify it in O(N) time and O(1) Space */

public ListNode reverseList(ListNode head) 
{
    ListNode *prev=null; 
    ListNode *next=null;
    
    while(head!=null)   //modifying the original list itself
    {   
        next = head->next;
        head->next = prev;    
        prev = head;            
        head = next;                                 
    }

    return prev;
}

/* Someone claiming to be O(1) space, becz here we're taking into consideration the output space */

class Solution {
    //If list is immutable
    public ListNode reverseList(ListNode head) {
        if(head == null) return null;
        ListNode prev=null; 
        ListNode runner=head;
        ListNode newHead = new ListNode(runner.val);
        
        while(runner!=null){
            newHead = new ListNode(runner.val);
            newHead.next=prev;
            prev=newHead;
            runner=runner.next;                                                             
        }
        
        return prev;
    }
}