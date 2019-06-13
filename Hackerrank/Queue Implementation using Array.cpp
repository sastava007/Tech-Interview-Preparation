#include<bits/stdc++.h>
using namespace std;
struct queue_array
{
    int rear,front;
    int capacity;
    int *array;
};
struct queue_array * create_queue(int capacity)
{
   struct queue_array *q;
   q=(struct queue_array *)malloc(sizeof(struct queue_array));
   if(!q)
        return NULL;
   else
    {
        array=(int *)malloc(sizeof(int)*capacity);
        if(!array)
            return NULL;
        return q;
    }
}
int isfull(struct queue_array *q)
{
    if(q->rear+1%q->capacity==q->front)
        return 1;
    else
        return 0;
}
int isempty(struct queue_array *q)
{
    if(q->front==-1)
        return 1;
    else
        return 0;
}
void enqueue(struct queue_array *q,int ele)
{
   if(isfull(q))
        cout<<"Overflow";
   else
   {
       q->rear=(q->rear+1)%q->capacity;
       q->array[q->rear]=ele;
       if(front==-1)
        q->front=q->rear;
   }
}
int dequeue(struct queue_array *q)
{
    if(q->front==-1)
    {
        cout<<"Underflow";
        return -1;
    }
    else
    {
        int data=q->array[q->front];
        if(q->rear==q->front)
            q->rear=q->front=-1;
        q->front=(q->front+1)%q->capacity;
        return data;
    }
}
