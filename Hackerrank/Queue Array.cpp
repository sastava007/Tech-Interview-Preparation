#include<bits/stdc++.h>
#define MAX 100
#define max_size 100
using namespace std;
struct queue_array
{
   int arr[MAX];
   int rear;
   int front;
   int size;
};
bool isempty(struct queue_array *q)
{
    if(q->front==-1 )
        return true;
    else
        return false;
}
// for Queue
bool isfull(struct queue_array *q)
{
    if((q->rear+1)%MAX==q->front)
        return true;
    else
        return false;
}
void enqueue_array(struct queue_array *q,int ele)
{
    if(isfull(q))
        cout<<"Overflow"<<endl;
    else
    {
        q->rear=(q->rear+1)%MAX;
        q->arr[q->rear]=ele;
        if(q->front==-1)
            q->front=q->rear;
        q->size++;
    }
}
int dequeue_array(struct queue_array *q)
{
    if(isempty(q))
        cout<<"Underflow";

    else
    {
        int data=q->arr[q->front];
        if(q->front==q->rear)
            q->rear=q->front=-1;
        else
        q->front=(q->front+1)%MAX;
        q->size--;
        return data;
    }
}
void print(struct queue_array *q)
{
    int i=q->front;
    while(i!=q->rear)
    {
        cout<<q->arr[i]<<" ";
        i=(i+1)%MAX;
    }
    if(i==q->rear)
        cout<<q->arr[i]<<endl;

}
/*Reverse A QUEUE using Stack*/
main()
{
    struct queue_array q;
    q.rear=-1;
    q.front=-1;
    q.size=0;
    int ele,c;
    while(1)
    {
        cout<<"Enter Your Choice"<<endl<<"1. INSERT REAR"<<endl<<"2. DELETE FRONT"<<endl<<"3. Print"<<endl<<" EXIT "<<endl;
        cin>>c;
        switch(c)
        {
            case 1: cin>>ele;
                    enqueue_array(&q,ele);
                    break;
            case 2: cout<<dequeue_array(&q)<<endl;
                    break;
            case 3: print(&q);
                    break;
            default: exit(1);
        }
    }
}
