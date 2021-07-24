#include<stdio.h>
#define Max 10

struct QUEUE
{
    int arr[Max];
    int front;
    int rear;
};

void init_queue(struct QUEUE *queue)
{
    queue->front=queue->rear=-1;
}

int isfull(struct QUEUE *queue)
{
    if(queue->rear==Max-1)
     return 1;
    return 0;
}

int isempty(struct QUEUE *queue)
{
    if(queue->front==queue->rear)   
         return 1;
    return 0;     
}

void enqueue(struct QUEUE *queue)
{int value;
    if(isfull(queue))
    {
        printf("Queue is Full\n");
    }
    else
    {
        printf("Enter data\n");
        scanf("%d",&value);
        (queue->rear)++;
        queue->arr[queue->rear]=value;
    }
}

void dequeue(struct QUEUE *queue)
{
    if(isempty(queue))
    {
        printf("Queue is empty\n");
    }
    else{
        (queue->front)++;
        printf("Dequeue element=%d\n",queue->arr[queue->front]);
    }
}

void display(struct QUEUE *queue)
{   if(isempty(queue))
    {
        printf("Queue is empty! Nothing to display\n");
    }
    else{
    for(int i=(queue->front)+1;i<=queue->rear;i++)
    {
        printf("%d--",queue->arr[i]);
    }
    }
}
void main()
{   int ch;
    struct QUEUE queue;
    init_queue(&queue);
    do{
        printf("1.Enqueue\n2.Dequeue\n3.isFull\n4.isEmpty\n5.Display\n6.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                enqueue(&queue);
                break;
            case 2:
                dequeue(&queue);
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
        
    if(queue.front==queue.rear)   
       {
           queue.front=queue.rear=-1;
       }
    }while(ch!=6);


}