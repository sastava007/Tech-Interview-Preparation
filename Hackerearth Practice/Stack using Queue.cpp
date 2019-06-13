#include<bits/stdc++.h>
#define MAX 10
using namespace std;
struct queue_array
{
   int arr[MAX];
   int rear;
   int front;
   int size;
}q1,q2;
bool isempty(struct queue_array *q)
{
    if(q->front==-1)
        return true;
    else
        return false;
}
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

// Maked push operation costly
void push(int ele)
{
   enqueue_array(&q1,ele);
   int n=q1.size;
   for(int i=0;i<n-1;i++)
   {
       enqueue_array(&q2,dequeue_array(&q1));

   }
   for(int j=0;j<n-1;j++)
        enqueue_array(&q1,dequeue_array(&q2));
}
int pop()
{
    int data=dequeue_array(&q1);
    return data;
}
main()
{
    q1.front=-1,q1.rear=-1,q1.size=0,q2.front=-1,q2.rear=-1,q2.size=0;
    int c,ele;
    while(1)
    {
        cout<<"Enter Your Choice"<<endl<<"1. PUSH"<<endl<<"2. POP"<<endl<<" EXIT "<<endl;
        cin>>c;
        switch(c)
        {
            case 1: cin>>ele;
                    push(ele);
                    break;
            case 2: cout<<pop();
                    break;
            default: exit(1);
        }
    }

}
