#include<bits/stdc++.h>
#define max 10
using namespace std;
struct stack_array
{
    int array[max];
    int top;
    int size;
}s1,s2;
bool isempty(struct stack_array *s)
{
    if(s->top==-1)
        return true;
    else
        return false;
}
bool isfull(struct stack_array *s)
{
    if(s->top==max-1)
        return true;
    else
        return false;
}
void push(struct stack_array *s,int ele)
{
    if(isfull(s))
        cout<<"Overflow";
    else
    {
        s->top=s->top+1;
        s->array[s->top]=ele;
        s->size++;
    }
}
int pop(struct stack_array *s)
{
    if(isempty(s))
    {
        cout<<"Underflow";
            }
    else
    {
        int data=s->array[s->top];
        s->top=s->top-1;
        s->size--;
        return data;
    }
}
void sort(struct stack_array *s1, struct stack_array *s2)
{
    int temp;
    while(s1->size!=0)
    {
        temp=pop(s1);
        while(s2->size!=0 && s2->array[s2->top]>temp)
            push(s1,pop(s2));
        push(s2,temp);
    }
}
main()
{
    s1.top=-1,s1.size=0,s2.top=-1,s2.size=0;
    push(&s1,40);
    push(&s1,30);
    push(&s1,5);
    push(&s1,8);
    push(&s1,4);
    sort(&s1,&s2);
    cout<<pop(&s2)<<endl;
    cout<<pop(&s2)<<endl;
    cout<<pop(&s2)<<endl;
    cout<<pop(&s2)<<endl;
    cout<<pop(&s2)<<endl;
}
