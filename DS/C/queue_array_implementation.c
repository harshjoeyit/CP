#include<stdio.h>
#include<stdlib.h>

// inefficient implementation / not circular 

struct ArrayQueue
{
    int front, rear;
    int capacity;
    int *array;
};


struct ArrayQueue* Queue( int size )
{
    struct ArrayQueue *Q = (struct ArrayQueue *)malloc( sizeof(struct ArrayQueue));
    if( !Q )
        return NULL;

    Q->capacity = size;
    Q->front = 0;                   // better , avoids any exception
    Q->rear = -1;   
    Q->array = (int *)malloc(sizeof(int)*Q->capacity);
    if( !Q->array)
        return NULL;
    
    return Q;
}


int is_empty_queue( struct ArrayQueue *Q)
{
    // if condition is true 1 is returned else 0 is returned 
    return( Q->front > Q->rear );
}


int is_full_queue( struct ArrayQueue *Q)
{
    return ( Q->rear = Q->capacity -1 );
}


int queue_size( struct ArrayQueue *Q )
{
    return ( Q->rear - Q->front + 1 );
}


void enqueue( struct ArrayQueue *Q , int data )
{
    if( is_full_queue(Q) )
    {   
        printf("queue is full\n");
        return;
    }
    else
        Q->array[++Q->rear] = data;
}


// some error, continues deleting in a loop
int dequeue( struct ArrayQueue *Q )
{
    int data = -1;

    if( is_empty_queue(Q) )
        printf("Queue is empty! \n");
    else
        data = Q->array[Q->front++];

    return data;
}



void delete_queue( struct ArrayQueue *Q )
{
    if(Q)
    {
        if(Q->array)
            free(Q->array);
        free(Q);
    }
}



void display_queue( struct ArrayQueue *Q )
{
    int index = Q->front;

    printf( "Queue : ");
    if(is_empty_queue(Q))
    {
        printf("Empty !\n");
        return;
    }

    while( index <= Q->rear )
    {
        printf(" %d",Q->array[index] );
        ++index;
    }
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

    int size , data , choice;
    printf( "\nQueue\n\nsize: ");
    scanf("%d",&size);

    struct ArrayQueue *Q = Queue(size);
   
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
                    enqueue(Q,data);
            break;

            case 2: data = dequeue(Q);
                    printf("removed: %d\n",data);
            break;

            case 3: if(is_empty_queue(Q))
                        printf("empty Queue \n");
                    else
                        printf("not empty Queue \n");
            break;
            
            case 4: if(is_full_queue(Q))
                        printf("full Queue \n");
                    else
                        printf("vacant Queue \n");
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