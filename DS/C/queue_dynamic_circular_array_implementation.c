#include<stdio.h>
#include<stdlib.h>

struct DynArrayQueue
{
    int front, rear;
    int capacity;
    int *array;
};


struct DynArrayQueue* Queue()
{
    struct DynArrayQueue *Q = (struct DynArrayQueue *)malloc( sizeof(struct DynArrayQueue));
    if( !Q )
        return NULL;

    Q->capacity = 1;
    Q->front = -1;
    Q->rear = -1;
    Q->array = (int *)malloc(sizeof(int)*Q->capacity);
    if( !Q->array)
        return NULL;
    return Q;
}


int is_empty_queue( struct DynArrayQueue *Q)
{
    // if condition is true 1 is returned else 0 is returned 
    return( Q->front == -1);
}


int is_full_queue( struct DynArrayQueue *Q)
{
    return (( Q->rear + 1) % Q->capacity == Q->front);
}


int queue_size( struct DynArrayQueue *Q )
{
    if( (Q->capacity -( Q->front - Q->rear - 1)) % Q->capacity  == 0 )
        return Q->capacity;
    else
        return ( (Q->capacity -( Q->front - Q->rear - 1)) % Q->capacity );
}



void resize( struct DynArrayQueue *Q )
{
    int size = Q->capacity;
    Q->capacity *= 2;
    Q->array = ( int * )realloc(Q->array , sizeof(int) * Q->capacity );
    if( !Q->array )
    {
        printf("memory error\n");
        return;
    }

    if( Q->front > Q->rear )        // if there are elements in the array before front , i.e. rear is before front , then
    {
        for( int i = 0; i< Q->front; i++ )
            Q->array[ i+size ] = Q->array[i];           // copying elements before front to copy elemnts in reallocated array
        
         Q->rear = Q->rear + size;       // rear is changed to new value 0
    }
}



void en_queue( struct DynArrayQueue *Q , int data )
{
    if( is_full_queue(Q) )
    {   
        resize(Q);
    }
    Q->rear = (Q->rear + 1) % Q->capacity;
    Q->array[Q->rear] = data;
    if( Q->front == -1 )                    // if the queue is empty and we want to make one
        Q->front = Q->rear;
}


// some error, continues deleting in a loop
int de_queue( struct DynArrayQueue *Q )
{
    int data = 0;
    if( is_empty_queue(Q) )
        printf("Queue is empty! \n");
    else
    {
        data = Q->array[Q->front];
        if( Q->front == Q->rear )
        {
            Q->front = -1;
            Q->rear = -1;
        }
        else
            Q->front = ( Q->front + 1 ) % Q->capacity;
    }
    return data;
}



void delete_queue( struct DynArrayQueue *Q )
{
    if(Q)
    {
        if(Q->array)
            free(Q->array);
        free(Q);
    }
}



void display_queue( struct DynArrayQueue *Q )
{
    int index = Q->front;

    printf( "Queue : ");
    if(is_empty_queue(Q))
    {
        printf("Empty !\n");
        return;
    }

    do
    {
        printf("%d ",Q->array[index]);
        index = (index + 1) % Q->capacity;
    }
    while( index != (Q->rear + 1) % Q->capacity );
    printf("\n");
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
    printf( "\nQueue\n"); 

    struct DynArrayQueue *Q = Queue();
   
    menu();

    printf("choice :");
    while( scanf("%d",&choice) )
    {     
        switch(choice)
        {
            case 0: data = queue_size(Q);
                    printf("queue size: %d\n",data);
                    data = Q->capacity;
                    printf("capacity: %d\n",data);
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