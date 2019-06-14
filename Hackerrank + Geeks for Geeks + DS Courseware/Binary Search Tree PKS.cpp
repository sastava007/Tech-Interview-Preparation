#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *father;
    struct node *right;

};
struct node *root=NULL;

struct node *create_node()
{
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    new_node->father=NULL;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

void insert_node(int x)
{
    struct node *new_node=create_node();
    new_node->data=x;
    if(root==NULL)
        root=new_node;
    else
    {
        struct node *temp=root;
        while(root!=NULL)
        {
            if(x>=temp->data)
              {
                  if(temp->right==NULL)
                    {
                    new_node->father=temp;
                    temp->right=new_node;
                    break;
                    }
                    else
                        temp=temp->right;
              }

            else if(x<temp->data)
                {
                   if(temp->left==NULL)
                      {
                        new_node->father=temp;
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
        if(root->father==NULL)
            cout<<"NULL\n";
        else
            cout<<root->father->data<<"\n";
        in_order(root->right);

    }

}
bool isLeftChild(struct node *root){
    if (root->father == NULL)
        return false;
    else if (root->father->data > root->data)
        return true;
}
bool isRightChild(struct node *root){
    if (root->father == NULL)
        return false;
    else if (root->data >= root->father->data)
        return true;
}

struct node * minValueNode(struct node* node)
{
    struct node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

void delete_node(struct node *root,int x)
{
    struct node *temp=root;
    if(x<temp->data)
        delete_node(temp->left,x);
    else if(x>temp->data)
        delete_node(temp->right,x);
    else
    {
        if(temp->left==NULL)
        {
            if(isLeftChild(temp))
            {
                struct node *r=temp;
                r->father->left=temp->right;
                free(r);
            }
            else if(isRightChild(temp))
            {
                struct node *r=temp;
                r->father->right=temp->right;
                free(r);
            }
        }
        else if(temp->right==NULL)
        {
            if(isLeftChild(temp))
            {
                struct node *r=temp;
                r->father->left=temp->left;
                free(r);
            }
            else if(isRightChild(temp))
            {
                struct node *r=temp;
                r->father->right=temp->left;
                free(r);
            }
        }
        else
        {
            struct node *t=minValueNode(root->right);
            temp->data=t->data;
            delete_node(temp->right,temp->data);
        }
    }

}
main()
{
    insert_node(50);
    insert_node(30);
    insert_node(20);
    insert_node(40);
    insert_node(70);
    insert_node(60);
    insert_node(80);
    in_order(root);
    cout<<"\n";
    delete_node(root,70);
    in_order(root);
}
