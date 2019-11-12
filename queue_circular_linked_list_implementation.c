#include<stdio.h>
#include<stdlib.h>


struct CLLnode
{
    int data;
    struct CLLnode *next;
};



struct CircularLinkedQueue
{
    struct CLLnode *front ,*rear;
};



struct CircularLinkedQueue* create_queue()
{
    struct CircularLinkedQueue *Q = (struct CircularLinkedQueue*)malloc( sizeof(struct CircularLinkedQueue) );
    if( !Q )
        return NULL;

    Q->front = Q->rear = NULL;
    return Q;
}



int is_empty_queue( struct CircularLinkedQueue *Q )
{
    return(Q->front == NULL );
}



int queue_size( struct CircularLinkedQueue *Q )
{
    struct CLLnode *temp = Q->front;
    int count = 0;

    if(temp == NULL )
        return 0;
    do 
    {
        count++;
        temp = temp->next;
    }
    while( temp != Q->front );

    return count;
}



void en_queue( struct CircularLinkedQueue *Q , int data )
{
    struct CLLnode *temp = ( struct CLLnode *)malloc(sizeof(struct CLLnode));
    temp->data = data;

    if( Q->front == NULL )
    {
        Q->front = Q->rear = temp;
        Q->rear->next = temp;           // making it a circular linked 
    }
   
    else
    {
        temp->next = Q->front;
        Q->rear->next = temp;
        Q->rear = temp;
    }
}



int de_queue( struct CircularLinkedQueue *Q )
{
    int data;
    struct CLLnode *temp = Q->front;
    if( is_empty_queue(Q) )
        printf("Queue is Empty !");

    else
    {
        if( Q->front == Q->rear )
            Q->front = Q->rear = NULL;
        else
        {
            Q->front = Q->front->next;
            Q->rear->next = Q->front;
        }
        data = temp->data;
        free(temp);
    }
    return data;
}



void delete_queue( struct CircularLinkedQueue *Q )
{
    struct CLLnode *temp;

    if( Q->front == NULL )
        printf("Empty Already !\n");
    else
    {
        while( Q->front != Q->rear )
        {
            temp = Q->front;
            Q->front = Q->front->next;
            free(temp);
        }
        free(Q->rear);
        printf("deleted\n");
    }    
}



void display_queue( struct CircularLinkedQueue *Q )
{
    struct CLLnode *temp = Q->front;

    printf("Queue: ");
    if(is_empty_queue(Q))
    {
        printf("empty\n");
        return;
    }
    
    do
    {
        printf("%d ",temp->data );
        temp = temp->next;
    }
    while( temp != Q->front);
}


void menu()
{
    printf("\n\n0. Queue size \n");
    printf("1. Enqueue \n");
    printf("2. DeQueue \n");
    printf("3. is empty \n");
    printf("4. is full \n");
    printf("5. Delete Queue \n");
    printf("6. Display \n");  
    printf("7. exit\n\n");
}





// driver function
int main()
{

    int  data , choice;
    printf( "\nQueue\n ");

    struct CircularLinkedQueue *Q = create_queue();
   
    menu();

    printf("choice :");
    while( scanf("%d",&choice) )
    {     
        switch(choice)
        {
            case 0: data = queue_size(Q);
                    printf("queue size: %d",data);
            break;

            case 1: printf("data: ");
                    scanf("%d",&data);
                    en_queue(Q,data);
            break;

            case 2: data = de_queue(Q);
                    printf("removed: %d\n",data);
            break;

            case 3: if(is_empty_queue(Q))
                        printf("empty Queue \n");
                    else
                        printf("not empty Queue \n");
            break;

            case 5: delete_queue(Q);
            break;

            case 6: display_queue(Q);
            break;

            case 7: exit(1);
            break;

            default: printf("wrong choice \n");
        }
        menu();
        printf("choice: ");
    } 
}