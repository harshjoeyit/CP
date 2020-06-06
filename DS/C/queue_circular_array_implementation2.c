#include<stdio.h>
#include<stdlib.h>

// implementation difference 
// Q->front = 0
// Q->rear = -1
/// in the starting 

struct QCircularArray
{
    int front, rear;
    int capacity;
    int *array;
};


struct QCircularArray* Queue( int size )
{
    struct QCircularArray *Q = (struct QCircularArray *)malloc( sizeof(struct QCircularArray));
    if( !Q )
        return NULL;

    Q->capacity = size;
    Q->front = 0;
    Q->rear = -1;
    Q->array = (int *)malloc(sizeof(int)*Q->capacity);
    if( !Q->array)
        return NULL;
    return Q;
}



int is_empty_queue( struct QCircularArray *Q)
{  
    return( Q->rear == -1 );
}



int is_full_queue( struct QCircularArray *Q)
{
    return (( Q->rear + 1) % Q->capacity == Q->front) && ( Q->rear != -1 );
}


//IMP
int queue_size( struct QCircularArray *Q )
{
    return ( Q->rear == -1 ) ? 0 : ( (Q->capacity + Q->rear - Q->front ) % Q->capacity + 1 );
}          




void en_queue( struct QCircularArray *Q , int data )
{
    if( is_full_queue(Q) )
    {   
        printf("queue is full\n");
        return;
    }
    else
    {
        Q->rear = (Q->rear + 1) % Q->capacity;
        Q->array[Q->rear] = data;
    } 
}



// some error, continues deleting in a loop
int de_queue( struct QCircularArray *Q )
{
    int data = 0;
    if( is_empty_queue(Q) )
        printf("Queue is empty! \n");
    else
    {
        data = Q->array[Q->front];
        if( Q->front == Q->rear )
        {
            Q->front = 0;
            Q->rear = -1;
        }
        else
            Q->front = ( Q->front + 1 ) % Q->capacity;
    }
    return data;
}



void delete_queue( struct QCircularArray *Q )
{
    if(Q)
    {
        if(Q->array)
            free(Q->array);
        free(Q);
    }
}



void display_queue( struct QCircularArray *Q )
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
    while( index != (Q->rear + 1) % Q->capacity );      // % used for condition when rear is at last index of the array 
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
    printf( "\nQueue\n\nsize: ");
    scanf("%d",&size);

    struct QCircularArray *Q = Queue(size);
   
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