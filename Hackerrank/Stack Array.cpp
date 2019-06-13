#include<bits/stdc++.h>
#define max 10
using namespace std;
struct stack_array
{
    int array[max];
    int top;
    int size;
}s1;
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
void pop(struct stack_array *s)
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
    }
}

void print(struct stack_array *s)
{
    if(isempty(s))
        cout<<"Stack is empty"<<endl;
    else
    {
        for(int i=s->top;i>=0;i--)
            cout<<s->array[i]<<" ";
    }
    cout<<endl;
}
 main()
 {
     s1.top=-1,s1.size=0;
     int c,ele;
     while(1)
     {
         cout<<"1. PUSH 2. POP 3. PEEP 4. PRINT 5. EXIT"<<endl;
         cin>>c;
             if(c==1)
             {
                 cin>>ele;
                push(&s1,ele);
             }

                else if(c==2)
                pop(&s1);

                else if(c==3)
                {
                    cout<<s1.array[s1.top]<<endl;
                }
                else if(c==4)
                 print(&s1);
                else if(c==5)
                exit(1);

        }

 }
