#include<stdio.h>
#include<stdlib.h>

// a structure that has both the top pointers of
//ELEMENTAL Stack
// & MINIMUM value stack;
struct advance_node
{
    struct node *S;
    struct node *MIN;
};


struct node
{
    int data;
    struct node *next;
};




int is_empty_stack( struct node *S )
{
    return( S == NULL );                         // returns 1 if true , else returns 0
}



void Push( struct advance_node **A , int data )
{
    struct node *temp = (struct node *)malloc( sizeof(struct node) );
    struct node *min_temp = (struct node *)malloc( sizeof(struct node) );
    int min = data;

    if( (*A)->MIN != NULL )
    {
        if( (*A)->MIN->data < data )
            min = (*A)->MIN->data;                  // changing min only if min < value already in min stack
    }                                               // else value remains the same 
    
    temp->data =  data;
    min_temp->data = min;

    temp->next = (*A)->S;
    (*A)->S = temp;

    min_temp->next = (*A)->MIN;
    (*A)->MIN = min_temp;

    printf("push success \n");
}





void Pop( struct advance_node **A )
{
    if( is_empty_stack( (*A)->S) )
        printf("empty stack \n");
    
    else
    {
        struct node *temp = (*A)->S;
        (*A)->S = (*A)->S->next;
        printf("pop: %d\n",temp->data);
        free(temp);

        temp = (*A)->MIN;
        (*A)->MIN = (*A)->MIN->next;
        printf("pop from min: %d\n",temp->data);
        free(temp);
        
        printf("deleted\n");
    }
}





int min_value( struct advance_node **A )
{
    if( (*A)->S )
        return( (*A)->MIN->data);
    return __INT_MAX__;
}





void display( struct node *P )
{
    printf("stack: ");
    struct node *temp = P;
    while( temp != NULL )
    {
        printf(" \t%d",temp->data );
        temp = temp->next;
    }
    printf("\n");
}

void display_stack( struct advance_node **A )
{
    if( (*A)->S == NULL )
        printf("empty stack \n");
    else
    {
        display( (*A)->S );
        printf("min ");
        display( (*A)->MIN );
    }
}




void menu()
{
    printf("\n\n0. Exit \n");
    printf("1. Push \n");
    printf("2. Pop \n");
    printf("3. is empty \n");
    printf("4. min value \n");
    printf("5. display \n\n");  
}



// driver program
int main()
{
    printf( "hello" );
    struct advance_node *A = (struct advance_node *)malloc( sizeof( struct advance_node ) );
    A->MIN = NULL;
    A->S = NULL;

    int  data , choice ;

    menu();

    printf("choice: ");
    while( scanf("%d",&choice) )
    {
        switch(choice)
        {
            case 0: exit(1);
            break;

            case 1: printf("data: ");
                    scanf("%d",&data);
                    Push(&A,data);
            break;

            case 2: Pop(&A);
            break;

            case 3: if(is_empty_stack( A->S ) )
                        printf("empty stack \n");
                    else
                        printf("not empty stack \n");
            break;
        
            case 4: printf("min_value: %d", min_value(&A));
            break;

            case 5: display_stack(&A);
            break;

            default: printf("wrong choice \n");
        }
        menu();
        printf("choice: ");
    }
}
