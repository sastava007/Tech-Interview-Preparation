#include<bits/stdc++.h>
using namespace std;
struct stack_array
{
    int top;
    int capacity;
    int *array;
};
struct stack_array *create_stack(int cap)
{
    struct stack_array *stack;
    stack=(struct stack_array *)malloc(sizeof(struct stack_array));
    stack->capacity=cap;
    stack->top=-1;
    stack->array=(int *)malloc(sizeof(int)*cap);
    return stack;
}
int isfull(struct stack_array *stack)
{
    if(stack->top==stack->capacity-1)
        return 1;
    else
        return 0;
}
int isempty(struct stack_array *stack)
{
    if(stack->top==-1)
        return 1;
    else
        return 0;
}
void push(struct stack_array *stack, int ele)
{
  if(isfull(stack))
            cout<<"Overflow"<<endl;
  else
  {
   stack->top++;
   stack->array[stack->top]=ele;
  }

}
void pop(struct stack_array *stack)
{
    if(isempty(stack))
        cout<<"Underflow"<<endl;
    else
    {
      int ele=stack->array[stack->top];
      stack->top--;
      cout<<ele<<endl;
    }

}
void print_stack(struct stack_array *stack)
{
    for(int i=stack->top;i<stack->capacity;i++)
        cout<<stack->array[i]<<" ";
}
int main()
{   struct stack_array *stack;
    stack=create_stack(4);
    push(stack,10);
    push(stack,20);
    push(stack,30);
    push(stack,40);
    pop(stack);
    pop(stack);pop(stack);
    //print_stack(stack);
    return 0;
}
