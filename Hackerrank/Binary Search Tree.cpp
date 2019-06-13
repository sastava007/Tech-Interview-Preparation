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
struct queue
{
    struct node *data;
    struct queue *next;

};
struct queue_LL
{
    struct queue *rear;
    struct queue *front;
}q;
void init(struct queue_LL *q)
{
    q->rear=NULL;
    q->front=NULL;
}
void enqueue_ll(struct queue_LL *q,struct node *data)
{
    struct queue *new_node=(struct queue*)malloc(sizeof(struct queue));
    new_node->data=data;
    new_node->next=NULL;
    if((q->rear==q->front)&&q->front==NULL)
    {
        q->rear=new_node;
        q->front=new_node;
    }
    else
    {
        q->rear->next=new_node;
        q->rear=new_node;
    }
}
struct node *dequeue_ll(struct queue_LL *q)
{
        struct queue *r;
        r=q->front;
        struct node *data=q->front->data;
        q->front=q->front->next;
        free(r);
        return data;
}
bool isempty(struct queue_LL *q)
{
    if(q->front==NULL)
        return true;
    else
        return false;
}

void level_order(struct node *root)
{
    if(root)
    {
        enqueue_ll(&q,root);
        while(q.front!=NULL)
        {
            struct node *temp=dequeue_ll(&q);
            cout<<temp->data<<" ";
           if(temp->left!=NULL)
                enqueue_ll(&q,temp->left);
            //cout<<temp->left->data<<" ";

            if(temp->right!=NULL)
                enqueue_ll(&q,temp->right);
                //cout<<temp->right->data<<" ";

        }
    }
}
struct node *find(struct node *root, int key)
{
    if(root==NULL)
    return NULL;
    else
    {
        if(key == root->data)
        return root;
        else if(key>root->data)
            find(root->right,key);
        else if(key<root->data)
            find(root->left,key);
    }

}
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
        while(temp!=NULL)
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
void pre_order(struct node *root)
{
    if(root)
    {
        //print only internal nodes
        if(root->left!=NULL&&root->right!=NULL)
        cout<<root->data<<" ";
        pre_order(root->left);
        pre_order(root->right);
    }
}
void post_order(struct node *root)
{
    if(root)
    {
       post_order(root->left);
       post_order(root->right);
       cout<<root->data;


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
        root1->data=find_sum(root,root->data);
        find_greater(root->right,root1->right);
    }
}
void print_rtl(struct node * root)
{
    if(root)
    {
        print_rtl(root->right);
        if(root->left==NULL&&root->right==NULL)
            cout<<root->data<<" ";
        print_rtl(root->left);
    }
}

struct node * minValueNode(struct node* node)
{
    struct node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

main()
{
    init(&q);
    insert(&root1,50);

    //insert(30);
    insert(&root1,30);

    //insert(20);
    insert(&root1,20);

    //insert(40);
    insert(&root1,40);

    //insert(70);
    insert(&root1,70);

    //insert(60);
    insert(&root1,60);

    //insert(80);
    insert(&root1,80);

    in_order(root1);
    //cout<<"\n\n";


}
