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
void dup_delete()
{
    struct node *temp1=start,*temp2,*r;
    while(temp1->next!=NULL)
    {
        temp2=temp1;
        while(temp2->next!=NULL)
        {
            if(temp2->next->data==temp1->data)
            {
                r=temp2->next;
                temp2->next=temp2->next->next;
                free(r);
            }
            else
            temp2=temp2->next;
        }
        temp1=temp1->next;
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
    dup_delete();
    view_node();
}
