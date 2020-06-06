#include<stdio.h>
#include<stdlib.h>


struct node         // for hlding the individual elements
{
    int data;
    struct node *next;
};

struct Queue                // has two pinters to nodes
{
    struct node *Front;
    struct node *Rear;
};

// implementing a stack with the help of 2 queues 
struct Stack                                                // har two pointers each pointing to a queue
{
    struct Queue *Q1;
    struct Queue *Q2;
};



// CREATE QUEUE

struct Queue* create_queue()                            // creating each queue
{
    struct Queue *Q = (struct Queue*)malloc( sizeof(struct Queue) );
    if( !Q )
        return NULL;

    Q->Front = Q->Rear = NULL;
    return Q;
}



// CREATE STACK

struct Stack *create_stack()                                // creating stack and queue within
{
    struct Stack *S = (struct Stack *)malloc(sizeof( struct Stack));
    S->Q1 = create_queue();
    S->Q2 = create_queue();
    return S;
}



// IS EMPTY QUEUE

int is_empty_queue( struct Queue *Q )
{
    return(Q->Front == NULL );
}



// IS EMPTY STACK

int is_empty_stack( struct Stack *S )                       // stack is empty only if both the queues are empty
{
    return ( is_empty_queue(S->Q1) && is_empty_queue(S->Q2) );
}



// ENQUEUE

void en_queue( struct Queue *Q , int data )                         // adding an element in a queue
{
    struct node *temp = ( struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if( Q->Front == NULL )
        Q->Front = Q->Rear = temp;                            // making it a circular linked 
   
    else
    {
        Q->Rear->next = temp;
        Q->Rear = temp;
    }
}



// PUSH

void Push( struct Stack *S , int data )            // IMPORTANT:  pushing an element in one of the queues , whichever has elements already
{
    if( is_empty_stack(S) )                         // if stack is empty ,we chose to enQueue in Q1 , default
        en_queue(S->Q1 , data);
    
    else if( ! is_empty_queue(S->Q1) )           // enqueues in whichever queue has already elements in it , i.e. is not empty
        en_queue(S->Q1 , data);
    else
        en_queue(S->Q2 , data);
}



// removing items from 1 stack and copying into another and deleting the last element

int copy_and_remove( struct Queue *Q1, struct Queue *Q2)                // function for dequeueing n-1 elements form Q1 and enqueueing same in  Q2 and removing last element 
{                                                                        // or vice-versa
    while( Q1->Front != Q1->Rear )
    {
        int data = Q1->Front->data;
        en_queue( Q2 , data );
        Q1->Front = Q1->Front->next;
    }
    int data = Q1->Rear->data;
    free(Q1->Rear);
    Q1->Front = Q1->Rear = NULL;
    return data;
}



// POP

int Pop( struct Stack *S )              // function calls copy and remove on the basis of
{                                       // whichever is not empty and whichever is empty
    int data;
    if( is_empty_stack(S))
    {
        printf("empty stack\n");
        return -1;
    }
    else
    {
        if( ! is_empty_queue(S->Q1) )
            data = copy_and_remove( S->Q1 , S->Q2 );
        else
            data = copy_and_remove( S->Q2 , S->Q1 );
    }
    return data;
}



//DISPLAY QUEUE

void display_queue( struct Queue *Q , int number)               // display individual queues
{
    struct node *temp = Q->Front;

    printf("Queue %d: ",number);
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
    
}



// DISPLAY STACK

void display_stack(struct Stack *S)                 // display both the queues 
{
    if( is_empty_stack(S))
        printf("empty stack \n");
    else
    {
        printf("stack \n");
        display_queue(S->Q1 , 1);
        printf("\n");
        display_queue(S->Q2 , 2);
    }
}




//MENU
void menu()
{
    printf("\n\n0. Exit \n");
     printf("1. Push \n");
    printf("2. Pop \n");
    printf("3. is empty \n");
    printf("6. display \n\n");  
}




// driver function
int main()
{
    struct Stack *S = create_stack();                            // S - top - head of the list, stack
    int  data , choice ;
   
    menu();

    printf("choice :");
    while( scanf("%d",&choice) )
    {     
        switch(choice)
        {
            case 0: exit(1);
            break;

            case 1: printf("data: ");
                    scanf("%d",&data);
                    Push(S,data);
            break;

            case 2: data = Pop(S);
                    printf("pop %d\n",data);
            break;

            case 3: if(is_empty_stack(S))
                        printf("empty stack \n");
                    else
                        printf("not empty stack \n");
            break;

            case 6: display_stack(S);
            break;

            default: printf("wrong choice \n");
        }
        menu();
        printf("choice: ");
    } 
}