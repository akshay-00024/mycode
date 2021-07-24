#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node* creatnode()
{
    struct node *nn=NULL;
    nn=(struct node*)malloc(sizeof(struct node));
    if(nn==NULL)
    {
        printf("memory not alloacted");
    }

    else
    {
        nn->prev=NULL;
        printf("enter data\n");
        scanf("%d",&(nn->data));
        nn->next=NULL;

    }
    return nn;
}

void creatlinklist(struct node** head_first,struct node** head_last)
{
    struct node* nn=NULL;
    nn=creatnode();
    if(*head_first==NULL)
    {
        *head_first=*head_last=nn;
    }
    else
    {
        nn->prev=*head_last;
        (*head_last)->next=nn;
        *head_last=nn;
    }
}

void insert_at_first(struct node **head_first,struct node **head_last)
{
    struct node *nn=NULL;
    nn=creatnode();
    if(*head_first==NULL)
    {
        *head_first=*head_last=nn;
    }
    else
    {
        nn->next=*head_first;
        (*head_first)->prev=nn;
        *head_first=nn;
    }
}

void insert_at_last(struct node** head_first,struct node **head_last)
{
    
  creatlinklist(head_first,head_last);  
}

void insert_at_position(struct node** head_first,struct node **head_last)
{
    int pos,i=1;
    printf("enter the position\n");
    scanf("%d",&pos);
    struct node* nn=NULL;
    struct node* temp=*head_first;
    if(pos<1)
    {
        printf("Invalid position\n");
        insert_at_position(head_first,head_last);
    }
    else if(pos==1)
    {
        insert_at_first(head_first,head_last);
    }
    else
    {
        nn=creatnode();
        while(i<pos-1)
        {
            temp=temp->next;
            i++;

        }
        nn->next=temp->next;
    
        nn->prev=temp;
        
        
        if(temp==*head_last)
        {
           
            *head_last=nn;
        }
        else
        {
            temp->next->prev=nn;
        }
        
        temp->next=nn;
    }

}

void delete_at_first(struct node **head_first,struct node **head_last)
{
    struct node* temp=NULL;
    
    if(*head_first==NULL )
    {
        printf("linked list not exist\n");
    }
    else if(*head_first==*head_last)
    {
        temp=*head_first;
        *head_first=NULL;
        *head_last=NULL;
        free(temp);
    }
    else
    {
        temp=*head_first;
        *head_first=(*head_first)->next;
        (*head_first)->prev=NULL;
        free(temp);
    }

}

void delete_at_last(struct node **head_first,struct node **head_last)
{
      struct node* temp=NULL;
    
    if(*head_first==NULL )
    {
        printf("linked list not exist\n");
    }
    else if(*head_first==*head_last)
    {
        temp=*head_first;
        *head_first=NULL;
        *head_last=NULL;
        free(temp);
    }
    else
    {
        temp=*head_last;
        *head_last=(*head_last)->prev;
        (*head_last)->next=NULL;
        free(temp);
    }

}

void delete_at_position(struct node** head_first,struct node** head_last)
{int pos,i=1;
    struct node *temp=NULL;
    printf("enter the position\n");
    scanf("%d",&pos);
    if(pos<1)
    {
        printf("Invalid position\n");
    }
    else if(pos==1)
    {
        delete_at_first(head_first,head_last);
    }
    else
    {
        temp=*head_first;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        if(temp==*head_last)
        {
            *head_last=temp->prev;
        }
        else
        {
            temp->next->prev=temp->prev;
        }
        free(temp);
        
     }
}

void display(struct node* head)
{
    if(head==NULL)
    {
        printf("linklist not exist\n");
    }
    else{
    while(head!=NULL)
    {
        printf("%d=>",head->data);
        head=head->next;
    }
    }
    printf("\n");
}

void reverse(struct node* last)
{
    if(last==NULL)
    {
         printf("linklist not exist\n");
    

    }
    else
    {
    while(last!=NULL)
    {
        printf("%d=>",last->data);
        last=last->prev;
    }
    }
    printf("\n");
}

void main()
{
    struct node* first=NULL;int ch;
    struct node* last=NULL;
    do{
    printf("1.creatlinklist\n");
    printf("2.display\n");
    printf("3.reverse\n");
    printf("4.insert_at_first\n");
    printf("5.insert_at_last\n");
    printf("6.insert_at_position\n");
    printf("7.delete_at_first\n");
    printf("8.delete_at_last\n");
    printf("9.delete_at_position\n10.exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            creatlinklist(&first,&last);
            break;
        case 2:
            display(first);
            break;
        case 3:
            reverse(last);
            break;
        case 4:
            insert_at_first(&first,&last);
            break;
        case 5:
            insert_at_last(&first,&last);
            break;
        case 6:
            insert_at_position(&first,&last);
            break;
        case 7:
            delete_at_first(&first,&last);
            break;
        case 8:
            delete_at_last(&first,&last);
            break;
        case 9:
            delete_at_position(&first,&last);
            break;
        
    
    }
    }while(ch!=10);

}

