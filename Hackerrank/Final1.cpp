#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
struct node *root1=NULL;

void insert(struct node **root, int data)
{
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    if(*root==NULL)
        *root=new_node;
    else
    {
        struct node *temp=*root;
        while(*root!=NULL)
        {
            if(data>temp->data)
            {
                if(temp->right==NULL)
                    {
                        temp->right=new_node;
                        break;
                    }
                else
                    temp=temp->right;
            }

            else if(data<temp->data)
            {
                if(temp->left==NULL)
                    {
                        temp->left=new_node;
                        break;
                    }
                else
                    temp=temp->left;
            }


        }
    }
}

void in_order(struct node *root)
{
    if(root)
    {
        in_order(root->left);
        cout<<root->data<<" ";
        in_order(root->right);

    }

}

int find_sum(struct node *root,int key)
{
    static int sum=0;
    if(root)
    {
        find_sum(root->left,key);
        if(root->data>key)
            sum+=root->data;
        find_sum(root->right,key);

    }
    return sum;
}
void find_greater(struct node *root,struct node *root1)
{
    if(root)
    {
        find_greater(root->left,root1->left);
        root1->data+=find_sum(root,root->data);
        find_greater(root->right,root1->right);
    }
}
int main()
{

    insert(&root,50);
    insert(&root1,50);

    insert(&root,30);
    insert(&root1,30);

    insert(&root,20);
    insert(&root1,20);

    insert(&root,40);
    insert(&root1,40);

    insert(&root,70);
    insert(&root1,70);

    insert(&root,60);
    insert(&root1,60);

    insert(&root,80);
    insert(&root1,80);

    find_greater(root,root1);
    in_order(root1);
    cout<<"\n\n";
}
