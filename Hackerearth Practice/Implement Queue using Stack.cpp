#include<bits/stdc++.h>
#define max 100
using namespace std;
struct stack_array
{
    int array[max];
    int top;
    int size;
}s1,s2;

bool isempty(struct stack_array s)
{
    if(s.top==-1)
        return true;
    else
        return false;
}
bool isfull(struct stack_array s)
{
    if(s.top==max-1)
        return true;
    else
        return false;
}
void push(struct stack_array *s,int ele)
{
    if(isfull(*s))
        cout<<"Overflow";
    else
    {
        s->top++;
        s->array[s->top]=ele;
        s->size++;
    }
}
int pop(struct stack_array *s)
{
    if(isempty(*s))
    {
        cout<<"Underflow";
    }
    else
    {
        int data=s->array[s->top];
        s->top--;
        s->size--;
        return data;
    }
}
void enqueue_array(int ele)
{
    push(&s1,ele);
}
int dequeue_array()
{
   if(s1.size==0&&s2.size==0)
    return -1;
   else if(s2.size==0)
   {
       int n=s1.size;
       for(int i=0;i<n;i++)
        push(&s2,pop(&s1));
   }
   return pop(&s2);
}
main()
{
    s1.top=-1,s2.top=-1;
    int ele,c;
    while(1)
    {
        cout<<"Enter Your Choice"<<endl<<"1. Enqueue"<<endl<<"2. Dequeue"<<endl<<" EXIT "<<endl;
        cin>>c;
        switch(c)
        {
            case 1: cin>>ele;
                    enqueue_array(ele);
                    break;
            case 2: cout<<dequeue_array()<<endl;
                    break;
            default: exit(1);
        }
    }

}

