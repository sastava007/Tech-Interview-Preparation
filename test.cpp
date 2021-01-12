#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct Node
{
  int val;
  struct Node* next;

  Node(int n = 0)
  {
    val = n;
    next = NULL;
  }
};

void fun(Node* head)
{
  // Node* temp = root;
  // temp->val = 20;
  // temp->next = NULL;

  delete head;
  // while(head!=NULL)
  // {
  //   cout<<head->val<<" ";
  //   head = head->next;
  // }

  
  // return head;
}


int main()
{
  Node* head = new Node();
  head->next = new Node(2);
  head->next->next = new Node(3);

  // fun(head);
  // cout<<"\n\n";

  while(head!=NULL)
  {
    cout<<"Hello!";
    cout<<head->val<<" ";
    head = head->next;
  }

}