#include<stdio.h>
#include<stdlib.h>

struct node
{

    int data;
    struct node* next;

};

struct node* creatnode()
{
    struct node* nn=NULL;
    nn=(struct node*)malloc(sizeof(struct node));
    if(nn==NULL)
    {
        printf("memory is not allocated\n");

    }
    else
    {
        
        printf("enter data");
        scanf("%d",&(nn->data));
        nn->next=NULL;
    }
    return nn;
}

void createlinklist(struct node **head)
{
    struct node* nn=NULL;
    struct node *temp=*head;
    nn=creatnode();
    if(*head==NULL)
    {
        *head=nn;
    }
    else{
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
      temp->next=nn;
    }

}
void insert_at_first(struct node **head)
{ struct node *nn=creatnode();
    if(*head==NULL)
    {
        *head=nn;
        
    }
    else{
        nn->next=*head;
        *head=nn;
    }

}
void insert_at_position(struct node **head)
{int pos,i=1;
    struct node *nn=NULL;
    struct node *temp=*head;
    printf("enter the position\n");
    scanf("%d",&pos);
    if(pos<1)
    {
        printf("enter valid pos\n");
        insert_at_position(head);
    }
    else if(pos==1)
    insert_at_first(head);
    else 
    {
        nn=creatnode();
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        nn->next=temp->next;
        temp->next=nn;

    }
    

}

void insert_at_last(struct node **head)
{
    createlinklist(head);
}

void delete_at_first(struct node **head)
{
    if(*head==NULL)
    {
        printf("linked list not exist\n");
    }
    else{
        struct node *temp=*head;
        *head=(*head)->next;
        free(temp);
    }

}

void delete_at_last(struct node **head)
{ struct node *temp=*head;
    if(*head==NULL)
    {
        printf("linked list not exist\n");
    }

    else{
            struct node *prev=NULL;
            while(temp->next!=NULL)
            {   prev=temp;
                temp=temp->next;
            }
            if(prev)
            {
            prev->next=NULL;
            }
            else{
                *head=NULL;
            }
            free(temp);

    }
}

void delete_at_position(struct node **head)
{
    int pos,i=1;
    printf("enter the position\n");
    scanf("%d",&pos);
    if(pos<1)
    {
        printf("invalid position\n");
        delete_at_position(head);
    }
    else if(pos==1)
    {
        delete_at_first(head);
    }
    else{
        struct node *temp=*head;
        struct node *prev=NULL;
        while(i<pos)
        {
            prev=temp;
            temp=temp->next;
            i++;
        }
        prev->next=temp->next;
        free(temp);

    }
}
void display(struct node *head)
{
    if(head==NULL)
    {
        printf("linked list not exist\n");
    }
    else{
    while(head!=NULL)
    {
        printf("%d=>",head->data);
        head=head->next;
    }
    printf("\n");
    }
}

void main()
{
    struct node* first=NULL;
    int ch;
    do
    {
        printf("1.createlinklist\n2.display\n3.insert_at_first\n4.insert_at_last\n5.insert_at_position\n");
        printf("6.delete_at_first\n7.delete_at_last\n8.delete_at_position\n9.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                createlinklist(&first);
                break;
            case 2:
                display(first);
                break;
            case 3:
                insert_at_first(&first);
                break;
            case 4:
                insert_at_last(&first);
                break;
            case 5:
                insert_at_position(&first);
                break;
            case 6:
                delete_at_first(&first);
                break;
            case 7:
                delete_at_last(&first);
                break;
            case 8:
                delete_at_position(&first);
                break;
        }
    }while(ch!=9);
}