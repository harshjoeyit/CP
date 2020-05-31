#include<stdio.h>
#include<stdlib.h>


struct node 
{
    int data;
    struct node *next;
};



struct LinkedQueue
{
    struct node *front , *rear;
};



struct LinkedQueue* create_queue()
{
    struct LinkedQueue *Q = (struct LinkedQueue*)malloc( sizeof(struct LinkedQueue) );
    if( !Q )
        return NULL;

    Q->front = Q->rear = NULL;
    return Q;
}



int is_empty_queue( struct LinkedQueue *Q )
{
    return(Q->front == NULL );
}



int queue_size( struct LinkedQueue *Q )
{
    struct node *temp = Q->front;
    int count = 0;

    if(temp == NULL )
        return 0;
    
    while( temp != NULL )
    {
        ++count;
        temp = temp->next;
    }
    return count;
}



void en_queue( struct LinkedQueue *Q , int data )
{
    struct node *temp = ( struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if( Q->front == NULL )
        Q->front = Q->rear = temp;                            // making it a circular linked 
   
    else
    {
        Q->rear->next = temp;
        Q->rear = temp;
    }
}


int de_queue( struct LinkedQueue *Q )
{
    struct node *temp = Q->front;
    int data = temp->data;
    if( is_empty_queue(Q) )
    {
        printf("Queue is Empty !");
        return 0;
    }

    else
    {
        if( Q->front == Q->rear )
            Q->front = Q->rear = NULL;
        else
            Q->front = Q->front->next;

        free(temp);
        return data;
    }
}



void display_queue( struct LinkedQueue *Q )
{
    struct node *temp = Q->front;

    printf("Queue: ");
    if(is_empty_queue(Q))
    {
        printf("empty");
        return;
    }
    
    while( temp != NULL )
    {
        printf("%d ",temp->data );
        temp = temp->next;
    }
    printf("\n");
}



void interleaving_Queue( struct LinkedQueue *Q)
{
    //  step 1 count elements 
    int n = queue_size(Q);
    // create two queues for storing the each half
    struct LinkedQueue *Q1 = create_queue();
    struct LinkedQueue *Q2 = create_queue();

    //step 2: deque the two halves
    n = (n+1)/2;
    while( n-- )
        en_queue(Q1,de_queue(Q));
        
    while( !is_empty_queue(Q) )
        en_queue(Q2,de_queue(Q));

    // step 3 dequeueing two queues alternatively to form 1 queue again
    while( !is_empty_queue(Q1) )
    {
        en_queue( Q , de_queue(Q1) );
        if( !is_empty_queue(Q2))
            en_queue( Q , de_queue(Q2) );
    }
}



// driver function
int main()
{
    struct LinkedQueue *Q = create_queue();

    int n, data;
    printf("n: ");
    scanf("%d",&n);

    while(n--)
    {
        printf("data: ");
        scanf("%d",&data);
        en_queue(Q,data);
    }
    interleaving_Queue(Q);  // call function
    // displaying he finaL RESUlt
    display_queue(Q);
}