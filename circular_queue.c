#include<stdio.h>
#define MAX 5
int count=0;
struct QUEUE{
    int arr[MAX];
    int front;
    int rear;

};

int isfull(struct QUEUE *queue)
{
    if(count==MAX)
        return 1;
    return 0;
}

int isempty(struct QUEUE *queue)
{
    if(count==0)
     return 1;
     return 0;
}
void Enqueue(struct QUEUE *queue)
{   int value;
    if(isfull(queue))
    {
        printf("QUEUE IS FULL\n");
    }
    else
    {
        queue->rear=(queue->rear+1)%MAX;
        printf("Enter data\n");
        scanf("%d",&value);
        queue->arr[queue->rear]=value;
        count++;

    }
}
void display(struct QUEUE *queue)
{
    if(isempty(queue))
    {
        printf("QUEUE is empty! Nothing to display\n");
    }
    else{
            int i=0;
            int j=queue->front+1;
            while(i<count)
            {
                printf("%d--",queue->arr[j]);
                j=(j+1)%MAX;
                i++;
            }
            printf("\n");
    }
}
void Dequeue(struct QUEUE* queue)
{
    if(isempty(queue))
    {
        printf("QUEUE is Empty\n");
    }
    else
    {   count--;
        queue->front=(queue->front+1)%MAX;
        printf("DEQUEUE element:%d\n",queue->arr[queue->front]);
    }
}
void init_queue(struct QUEUE *queue)
{
    queue->front=-1;
    queue->rear=-1;
}
void main()
{ int ch;
    struct QUEUE queue;
    init_queue(&queue);
    do{
        printf("1.Enqueue\n 2.Dequeue\n 3.isfull\n 4.isempty\n 5.display\n6.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                   Enqueue(&queue);
                   break;
            case 2:
                   Dequeue(&queue);
                   break;
            case 3:
                    if(isfull(&queue))
                        printf("YES\n");
                    else
                        printf("NO\n");
                    break;
            case 4:
                    if(isempty(&queue))
                        printf("YES\n");
                    else
                        printf("NO\n");
            
                    break;
            case 5:

                    display(&queue);
                    break;
            
        }
    }while(ch!=6);
}