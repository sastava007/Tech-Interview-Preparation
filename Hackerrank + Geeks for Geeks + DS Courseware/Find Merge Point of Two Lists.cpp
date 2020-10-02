int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) 
{
    SinglyLinkedListNode* tmp1=head1;
    SinglyLinkedListNode* tmp2=head2;
    while(tmp1!=tmp2)
    {
        tmp1=tmp1->next;
        tmp2=tmp2->next;
        if(tmp1==NULL)
        {
            tmp1=head2;
        }
        if(tmp2==NULL)
        {
            tmp2=head1;
        }
    }
    return tmp1->data;
}