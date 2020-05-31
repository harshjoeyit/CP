#include<stdio.h>
#include<stdlib.h>



struct DLLnode
{
    int data;
    struct DLLnode *next;
    struct DLLnode *prev;
};

// we make a queue that is doublly linked list , so we do not need rear pointer, we only need head pointer

struct DLLnode* create_queue()
{
    return NULL;
}


int is_empty_queue( struct DLLnode **head )
{
    return ( *head == NULL );
}



void EnqueueRear (struct DLLnode **head , int data )
{
    struct DLLnode *temp = (struct DLLnode *)malloc( sizeof(struct DLLnode) ); 
    temp->data = data ;

    if( is_empty_queue(head))
    {
        printf("empty queue\n");
        temp->prev = temp;
        temp->next = temp;
        *head = temp;
    }

    else
    {
        temp->prev = (*head)->prev;
        temp->next = *head;
        (*head)->prev->next = temp;             // this step should always be before the next one
        (*head)->prev = temp;                   // because the prev pointer changes it node(value)
    }
    
}



void EnqueueFront (struct DLLnode **head , int data )
{
    EnqueueRear(head , data);
    *head = (*head)->prev;
}




int DequeueFront ( struct DLLnode **head )
{

    if( is_empty_queue(head))
    {
        printf("empty\n");
        return -1;
    }
    else
    {
        struct DLLnode *temp = *head;
        int data = temp->data;
        int flag = 0;
        *head = (*head)->next;
        if(*head == (*head)->next)
            flag = 1;
        temp->prev->next = *head;
        (*head)->prev = temp->prev;

        if(flag == 1)
            *head = NULL;

        free(temp);
        return data;
    }
    
}




int DequeueRear (struct DLLnode **head)
{
    if(is_empty_queue(head))
    {
        printf("empty queue\n");
        return -1;
    }
    else
    {
        *head = (*head)->prev;
        int data = DequeueFront(head);
        return data;
    }
} 




int size( struct DLLnode **head )
{
    struct DLLnode *temp = (*head);
    int count = 0;

    if(is_empty_queue(head))
        return 0;

    do
    {
        ++count;
        temp = temp->next;
    } while (temp != *head);

    return count;
}




void display_queue( struct DLLnode **head )
{
    struct DLLnode *temp = (*head);

    printf("Queue: ");
    if(is_empty_queue(head))
        printf("Empty \n");
    else
    {
        do
        {
            printf("%d  ",temp->data);
            temp = temp->next;
        } while (temp != *head);
    }
}




void menu()
{
    printf("\n\n0. Queue size \n");
    printf("1. Enqueue Front \n");
    printf("2. Enqueue Rear \n");
    printf("3. DeQueue Front\n");
    printf("4. Dequeue Rear \n");
    printf("5. is empty \n");
    printf("6. Display \n");  
    printf("7. exit\n\n");
}




// driver function
int main()
{

    int  data , choice;
    printf( "\nQueue\n ");
    struct DLLnode *head = create_queue();
   
    menu();

    printf("choice :");
    while( scanf("%d",&choice) )
    {     
        switch(choice)
        {
            case 0: data = size(&head);
                    printf("queue size: %d",data);
            break;

            case 1: printf("data: ");
                    scanf("%d",&data);
                    EnqueueFront(&head,data);
            break;

            case 2: printf("data: ");
                    scanf("%d",&data);
                    EnqueueRear(&head,data);
            break;

            case 3: data = DequeueFront(&head);
                    printf("removed: %d\n",data);
            break;

            case 4: data = DequeueRear(&head);
                    printf("removed: %d\n",data);
            break;

            case 5: if(is_empty_queue(&head))
                        printf("empty Queue \n");
                    else
                        printf("not empty Queue \n");
            break;

            case 6: display_queue(&head);
            break;

            case 7: exit(1);
            break;

            default: printf("wrong choice \n");
        }
        menu();
        printf("choice: ");
    } 
}