#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *create_node()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
return temp;
}

void insert_node(int ele)     // INSERT AT LAST
{
    struct node *temp=create_node();
    temp->next=NULL;
    temp->data=ele;
    struct node *t;
    if(start==NULL)
        start=temp;
    else
    {
        t=start;
        while(t->next!=NULL)
            t=t->next;
        t->next=temp;
    }
}
void delete_ll()
{
    struct node *temp=start,*r;
    while(temp!=NULL)
    {
      r=temp->next;
        free(temp);
        temp=r;

       /* r=temp;
        temp=temp->next;
        free(r);*/
    }
    start=NULL;
}
//to print nth node from back
void nth(int size,int n)
{
    struct node *temp=start;
    for(int i=size;i>n;i--)
        temp=temp->next;
    printf("%d ",temp->data);
}
void reverse()
{
    struct node *prev=NULL,*next=NULL,*current=start;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    start=prev;
}
/* SWAP ALTERNATE NODE */
void swap_nodes()
{
    int t;
    struct node *temp=start;
    while(temp!=NULL&&temp->next!=NULL)
    {
       t=temp->data;
       temp->data=temp->next->data;
       temp->next->data=t;
       temp=temp->next->next;
    }
}
/* FIND THAT WHETHER A LOOP EXIST IN A LOOP OR NOT*/

void view_node()
{
    struct node *t;
    if(start==NULL)
        printf("Underflow\n");
    else
    {
        t=start;
        while(t!=NULL)
        {
            printf("%d ",t->data);
            t=t->next;
        }
        printf("\n");
    }
}
main()
{
    int n,ele;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ele);
        insert_node(ele);
    }
    view_node();
    swap_nodes();
   view_node();
}
