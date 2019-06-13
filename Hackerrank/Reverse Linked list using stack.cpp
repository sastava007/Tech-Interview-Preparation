#include<bits/stdc++.h>
#define max 10
using namespace std;
struct node
{
int data;
struct node *next;
};
struct stack_array
{
    int array[max];
    int top;
    int size;
}s1;
struct node *start=NULL;

bool isempty(struct stack_array *s)
{
    if(s->top==-1)
        return true;
    else
        return false;
}
bool isfull(struct stack_array *s)
{
    if(s->top==max-1)
        return true;
    else
        return false;
}
void push(struct stack_array *s,int ele)
{
    if(isfull(s))
        cout<<"Overflow";
    else
    {
        s->top=s->top+1;
        s->array[s->top]=ele;
        s->size++;
    }
}
int pop(struct stack_array *s)
{
    if(isempty(s))
    {
        cout<<"Underflow";
    }
    else
    {
        int data=s->array[s->top];
        s->top=s->top-1;
        s->size--;
        return data;
    }
}

struct node* create_node()
{
  struct node *new_node;
  new_node=(struct node*)malloc(sizeof(struct node));
  return new_node;
}
void insert(int ele)
{
  struct node *new_node=create_node();
  new_node->data=ele;
  new_node->next=NULL;
  if(start==NULL)
    start=new_node;
  else
  {
      struct node *t=start;
      while(t->next!=NULL)
        t=t->next;
      t->next=new_node;
  }
}

int delete_first()    // DELETE FROM FIRST
{
    struct node *r;
    if(start==NULL)
        cout<<"Underflow"<<endl;
    else
    {
        r=start;
        int data=start->data;
        start=r->next;
        return data;
        free(r);
    }
}
void reverse(struct stack_array *s)
{
    struct node *temp=start;
    while(temp!=NULL)
    {
        push(s,delete_first());
        temp=temp->next;
    }
}
main()
{
    struct stack_array s1;
    s1.top=-1;
    s1.size=0;
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    reverse(&s1);
    while(s1.size!=0)
        cout<<pop(&s1)<<endl;
}
