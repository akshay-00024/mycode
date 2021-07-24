#include<stdio.h>
#define Max 10

struct STACK
{
    int arr[Max];
    int top;
};

int isfull(struct STACK *stack)
{
    if(stack->top==Max-1)
    return 1;
    return 0;
}

int isempty(struct STACK *stack)
{
    if(stack->top==-1)
    return 1;
    return 0;
}
void push(struct STACK *stack)
{int v;
    if(isfull(stack))
    {
       printf("Stack Overflow\n");
       }
    else
    {
        printf("Enter the value\n");
        scanf("%d",&v);
        (stack->top)++;
        stack->arr[stack->top]=v;
    
       
    }

}
void pop(struct STACK *stack)
{
    if(isempty(stack))
    {
         printf("Stack Underflow\n");
        
    }
    else{
       printf("Pop element:%d\n",stack->arr[stack->top]);
        (stack->top)--;
    }
}
void display(struct STACK *stack)
{ 
    if(isempty(stack))
    {
        printf("Stack is empty\n");

    }
    else{
        for(int i=stack->top;i>=0;i--)
            {
                printf("%d\n",stack->arr[i]);
            }
    }
}
void main()
{   int ch;
    struct STACK stack;
    stack.top=-1;
    do
    {
        printf("1.push\n2.pop\n3.display\n4.isfull\n5.isempty\n6.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                push(&stack);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                if(isfull(&stack))
                {
                    printf("Stack is Full\n");
                }
                else
                {
                    printf("%d positons are vacant\n",Max-stack.top-1);
                }
                break;
            case 5:
                  if(isempty(&stack))
                  {
                      printf("Stack is Empty\n");
                  }
                  else{
                      printf("Filled positions=%d\n",stack.top+1);
                  }
                  break;

    
        }
    }while(ch!=6);
}