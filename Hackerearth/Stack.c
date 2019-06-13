#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 20
struct stack
{
    int top;
    int array[STACKSIZE];
} ;
static int min;
int empty(struct stack *s)
{
    return(s->top==-1);
}
int isfull(struct stack *s)
{
    return (s->top==STACKSIZE-1);
}
int pop(struct stack *s)
{
    int data;
    if(empty(s))
    {
        printf ("\nUNDERFLOW");
        return -1;
    }
    data=s->array[s->top];
    s->top--;
    return data;
}
void push(struct stack *s,int data)
{
    if(isfull(s))
        printf ("\n OVERFLOW");
    else
    {
            if(s->top==-1)
                {
                    min=data;
                    s->top++;
                    s->array[s->top]=data;
                }
            else if(data<min)
            {
                s->top++;
                s->array[s->top]=data;
                min=data;
            }
    }

}
int main()
{
    struct stack s;
    s.top=-1;
    int c,data,x;
    while(1)
    {
    printf ("\n\n 1.TO PUSH THE ELEMENT\n");
    printf ("2.TO POP THE ELEMENT\n");
    printf ("3.DISPLAY THE STACK\n");
    printf ("4. GET MIN\n");
    printf("5. EXIT\n");
    printf ("Enter your choice:");
    scanf ("%d",&c);
    switch(c)
    {
    case 1:
        printf ("Enter no:");
        scanf ("%d",&data);
        push(&s,data);
        break;
    case 2:
        x=pop(&s);
        printf("Poped element:%d",x);
        break;
    case 3:
        if(empty(&s))
            printf ("STACK IS EMPTY");
        else
        {
            for(int i=0;i<=s.top;i++)
                printf(" %d",s.array[i]);
        }
        break;
    case 4:
        printf("%d",min);
        break;
    case 5:
        exit(1);
    default:
        printf ("WRONG CHOICE");

    }
    }
    return 0;
}
