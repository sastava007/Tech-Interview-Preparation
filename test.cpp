#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct Node
{
  int val;
  struct Node* next;

  Node(int n = 50)
  {
    val = n;
    next = NULL;
  }
};



void fun(Node *head)
{
  head->val = 10*head->val;
  head->next = new Node();
  
  // head = head->next;

  /*
    When passing a pointer to a function, you are still passing it by value.
    The address it contains is copied into the function. Modifying that pointer
    inside the function will not change the pointer outside the function
    however, modifying the object it points to will change the object outside the function.
  */

}

void print(Node* head)
{
  while(head!=NULL)
  {
    cout<<head->val<<" ";
    head = head->next;
  }
}

int main()
{
  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);

  fun(head);

  print(head);
  cout<<"\n\n";
  // print(temp);
}