#include<stdio.h>
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



//to reverse the part of linked list
struct node *reverse(struct node *temp)
{
    struct node *prev=NULL,*next=NULL,*current=temp;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }

    return prev;
}



void reverse_otherhalf(int n)
{
    struct node *temp=start;
    for(int i=0;i<n/2-1;i++){         //error 3 (i<n-2/2  ki jagah i<n/2-1 )
        temp=temp->next;}
    temp->next=reverse(temp->next);
}

//to print the LL
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
    printf("After reversing\n");
    //pallindrome(n);                 error 2(no such function exist)
    reverse_otherhalf(n);
    view_node();
}
