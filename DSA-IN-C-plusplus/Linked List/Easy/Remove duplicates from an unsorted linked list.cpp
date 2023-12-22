/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     unordered_map<int, int>freq;
     Node* curr = head;
     freq[curr->data] = 1;
     while(curr->next){
         if(freq.count(curr->next->data)){
             curr->next = curr->next->next;
         }
         
         else{
             curr = curr->next;
             freq[curr->data]++;
         }
     }
     
     return head;
    }
};
