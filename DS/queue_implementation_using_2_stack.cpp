#include<stdio.h>
#include<stdlib.h>


struct Stack 
{
    int data;
    struct Stack *next;
};

// IMP: how to define a sturcture 
struct Queue
{
    struct Stack *S1;            // pointer to the top of Stack1
    struct Stack *S2;            // pointer to the top of Stack2
};



struct Stack* create_stack()
{
     return NULL;
}


struct Queue* create_queue()
{
    struct Queue *Q = (struct Queue*)malloc( sizeof(struct Queue) );
    if( !Q )
        return NULL;

    Q->S1 = create_stack();
    Q->S2 = create_stack();
    return Q;
}



int is_empty_stack( struct Stack *S )
{   
    return( S == NULL );                         // returns 1 if true , else returns 0
}


int is_empty_queue( struct Queue *Q)
{
    return ( is_empty_stack(Q->S1) && is_empty_stack(Q->S2));
}




void Push( struct Stack **S , int data )
{
    struct Stack *temp = (struct Stack *)malloc(sizeof(struct Stack));
    temp->data = data;

    temp->next = *S;                                                // since S is intialized to be NULL , there is no need to make exception for head and other Stacks
    *S = temp;                                                  // all the Stacks get stacked over one another
}



int Pop( struct Stack **S )
{
    int data;
    if( is_empty_stack(*S) ) 
        return -1;
    
    else
    {
        struct Stack *temp = *S;
        *S = (*S)->next;
        data = temp->data;
        free(temp);
    }
    return data;
}




void en_queue( struct Queue *Q , int data )
{

    if( is_empty_stack(Q->S1) )         // we always push into S1 
    {                                       // is S1 is empty then elements are are in S2 , so pop s2 and push S1
        while( ! is_empty_stack(Q->S2) )
        {
            Push( &(Q->S1) , Pop(&(Q->S2)) );
        }
    }
    Push(&(Q->S1) , data );                 //in any condition a new element needs to be pushed
}





int de_queue( struct Queue *Q )
{
    if( is_empty_queue(Q) )
    {
        printf("Empty Queue \n");
        return -1;
    }

    else if ( is_empty_stack(Q->S2))
    {
        while( ! is_empty_stack(Q->S1) )        // if the elements are in S1 thn S2 is empty , pop S1 and push S1 
            Push( &(Q->S2) , Pop(&(Q->S1)) );   
    }

    return (Pop(&(Q->S2)));             // in any condition we pop one element out of S2
}




void display_stack(struct Stack *S, int number)
{
    if(is_empty_stack(S))
        printf("empty stack");
    else
    {
        printf("stack %d: ",number);
        struct Stack *temp = S;
        while( temp != NULL )
        {
             printf("\t%d",temp->data);
             temp = temp->next;
        }
    }
}




void display_queue( struct Queue *Q )
{
    if( is_empty_queue(Q) )
        printf("Empty Queue\n");
    else
    {
        display_stack(Q->S1 , 1 );
        printf("\n");
        display_stack(Q->S2 , 2);
    }
}



void menu()
{
    printf("\n1. Enqueue \n");
    printf("2. DeQueue \n");
    printf("3. is empty \n");
    printf("6. Display Queue\n");  
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