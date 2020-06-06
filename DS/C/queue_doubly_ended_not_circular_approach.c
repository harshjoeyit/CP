#include<stdio.h>
#include<stdlib.h>



struct DLLnode
{
    int data;
    struct DLLnode *next;
    struct DLLnode *prev;
};


struct Queue
{
    struct DLLnode *Front;
    struct DLLnode *Rear;
};



struct Queue* create_queue()
{
    struct Queue *Q = (struct Queue *)malloc(sizeof(struct Queue));
    if( !Q)
        return NULL;

    Q->Front = Q->Rear = NULL;
    return Q;
}



int is_empty_queue( struct Queue **Q )
{
    return ( (*Q)->Front == NULL );
}



void EnqueueFront (struct Queue **Q , int data )
{
    struct DLLnode *temp = (struct DLLnode *)malloc( sizeof(struct DLLnode) ); 
    temp->data = data ;
    temp->next = temp->prev = NULL;

    if( is_empty_queue(Q))
    {
        (*Q)->Front = (*Q)->Rear = temp;
    }
    else
    {
        temp->next = (*Q)->Front;
        (*Q)->Front->prev = temp;
        (*Q)->Front = temp; 
    }
}




void EnqueueRear (struct Queue **Q , int data )
{
    struct DLLnode *temp = (struct DLLnode *)malloc( sizeof(struct DLLnode) ); 
    temp->data = data ;
    temp->next = temp->prev = NULL;

    if( is_empty_queue(Q))
    {
        (*Q)->Front = (*Q)->Rear = temp;
    }

     else
    {
        (*Q)->Rear->next = temp;
        temp->prev = (*Q)->Rear;
        (*Q)->Rear = temp; 
    }
    
}




int DequeueFront (struct Queue **Q)
{
    struct DLLnode *temp = (*Q)->Front;
    int data;

    if( is_empty_queue(Q) )
    {
        printf("empty Queue\n");
        return -1;
    }

    else
    {
        (*Q)->Front = (*Q)->Front->next;
        data = temp->data;
        free(temp);
        if((*Q)->Front != NULL)
            (*Q)->Front->prev = NULL;
    }
    return data;
}




int DequeueRear (struct Queue **Q)
{
    struct DLLnode *temp = (*Q)->Rear;
    int data;

    if( is_empty_queue(Q) )
    {
        printf("empty Queue\n");
        return -1;
    }

    else
    {
        (*Q)->Rear = (*Q)->Rear->prev;
        data = temp->data;
        free(temp);
        if((*Q)->Rear != NULL )
            (*Q)->Rear->next = NULL;
    }
    return data;
} 




int size( struct Queue **Q )
{
    struct DLLnode *temp = (*Q)->Front;
    int count = 0;

    if(is_empty_queue(Q))
        return 0;

    while( temp != NULL )
    {
        ++count;
        temp = temp->next;
    }
    return count;
}




void display_queue( struct Queue **Q )
{
    struct DLLnode *temp = (*Q)->Front;

    printf("Queue: ");
    if(is_empty_queue(Q))
        printf("Empty \n");
    else
    {
        while( temp != NULL )
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
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

    struct Queue *Q = create_queue();
   
    menu();

    printf("choice :");
    while( scanf("%d",&choice) )
    {     
        switch(choice)
        {
            case 0: data = size(&Q);
                    printf("queue size: %d",data);
            break;

            case 1: printf("data: ");
                    scanf("%d",&data);
                    EnqueueFront(&Q,data);
            break;

            case 2: printf("data: ");
                    scanf("%d",&data);
                    EnqueueRear(&Q,data);
            break;

            case 3: data = DequeueFront(&Q);
                    printf("removed: %d\n",data);
            break;

            case 4: data = DequeueRear(&Q);
                    printf("removed: %d\n",data);
            break;

            case 5: if(is_empty_queue(&Q))
                        printf("empty Queue \n");
                    else
                        printf("not empty Queue \n");
            break;

            case 6: display_queue(&Q);
            break;

            case 7: exit(1);
            break;

            default: printf("wrong choice \n");
        }
        menu();
        printf("choice: ");
    } 
}