#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int data;
    struct Stack *next;
};

struct Queue
{
    struct Stack *front , *rear;
};


int is_empty_Stack( struct Stack **S )
{
    return( *S == NULL );                         // returns 1 if true , else returns 0
}


void Push( struct Stack **S , int data )
{
    struct Stack *temp = (struct Stack *)malloc(sizeof(struct Stack));
    temp->data = data;

    temp->next = *S;                                                // since S is intialized to be NULL , there is no need to make exception for head and other Stacks
    *S = temp;                                                    // all the Stacks get Stacked over one another
}


int Pop( struct Stack **S )
{
    int data;
    if( is_empty_Stack(S) ) 
        return -1;
    
    else
    {
        struct Stack *temp = *S;
        data = temp->data;
        *S = (*S)->next;
        free(temp);
    }
    return data;
}


int is_empty_queue( struct Queue *Q )
{
    return(Q->front == NULL );
}


void en_queue( struct Queue *Q , int data )
{
    struct Stack *temp = ( struct Stack *)malloc(sizeof(struct Stack));
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



int de_queue( struct Queue *Q )
{
    struct Stack *temp = Q->front;
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


void display_stack(struct Stack **S)
{
    if( *S == NULL)
        printf("empty stack \n");
    else
    {
        printf("stack: ");
        struct Stack *temp = *S;
        while( temp != NULL )
        {
             printf("\t%d",temp->data);
             temp = temp->next;
        }
    }
}



void display_queue( struct Queue *Q )
{
    struct Stack *temp = Q->front;

    printf("Queue: ");
    if(is_empty_queue(Q))
    {
        printf("empty\n");
        return;
    }
    
    while( temp != NULL )
    {
        printf("\t%d",temp->data );
        temp = temp->next;
    }
}


int check_consecutive( struct Stack **S )
{
    int x,y;

    while(!is_empty_Stack(S))
    {
        x = Pop(S);
        if( !is_empty_Stack(S))
            y = Pop(S);
        else
            break;
        printf("\nx: %d\t y: %d",x,y);
        if( abs(x-y) != 1)
            return 0;
    }
    return 1;
}


// driver fuction 
int main()
{
    struct Stack *S = NULL;
    struct Queue *Q = (struct Queue *)malloc(sizeof(struct Queue));
    Q->front = NULL;
    Q->rear = NULL;

    int n,data;
    printf("n: ");
    scanf("%d",&n);

    while(n--)
    {
        printf("data: ");
        scanf("%d",&data);
        Push(&S,data);
    }

    display_stack(&S);

    while( !is_empty_Stack(&S) )
    {
        en_queue(Q,Pop(&S));
    }
    printf("\n");
    display_queue(Q);

    while( !is_empty_queue(Q))
    {
        Push(&S,de_queue(Q));
    }
    printf("\n");
    display_stack(&S);

    int x = check_consecutive(&S);
    if(x)
        printf("true");
    else
        printf("false");
}