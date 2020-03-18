#include<stdio.h>

#define MAXSIZE 20

struct array_stack
{
    int top;
    int capacity;
    int *array;
};


struct array_stack *create_stack()
{
    struct array_stack *S =  (struct array_stack* )malloc( sizeof(struct array_stack));
    if( !S )
        return NULL;
    
    S->capacity = MAXSIZE;
    S->top = -1;
    S->array =  (int* )malloc( S->capacity*sizeof(int));

    return S;
}



int is_empty_stack( struct array_stack *S )
{
    return( S->top == -1 );                         // returns 1 if true , else returns 0
}



int is_full_stack(struct array_stack *S )
{
    return (S->top == S->capacity -1 );                // returns 1 if true , else return 0
}



void Push( struct array_stack *S , int data )
{
    // S->top == S->capacity- 1 indicates that the stack is full
    if( is_full_stack (S) )
        printf("stack overflow \n");
    else
    {
        S->array[++S->top] = data;
        printf("push success \n");
    }
}


int Pop( struct array_stack *S )
{
    // S->top == -1 
    if( is_empty_stack(S) ) 
    {
        printf("empty \n");
        return -1;
    }
    else
    return(S->array[S->top--]);
}


void delete_stack( struct array_stack *S)
{
    if(S)
    {
        if(S->array)
            free(S->array);
        free (S);
    }
}



void display_stack(struct array_stack *S)
{
    if(S)
    {   
        printf("stack : ");
        if(S->top == -1 )
            printf(" empty \n");
        else
        {
            for(int i = S->top; i>= 0; i--) // dislay from the top
                printf(" %d",S->array[i] );
        }
    }
}




void menu()
{

    printf("\n\n0. Exit \n");
    printf("1. Push \n");
    printf("2. Pop \n");
    printf("3. is empty \n");
    printf("4. is full \n");
    printf("5. delete stack \n");
    printf("6. display \n\n");  
}



// driver function
int main()
{
    struct array_stack *S = create_stack();

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
                    Push(S,data);
            break;

            case 2: printf("pop %d",Pop(S));
            break;

            case 3: if(is_empty_stack(S))
                        printf("empty stack \n");
                    else
                        printf("not empty stack \n");
            break;
            
            case 4: if(is_full_stack(S))
                        printf("full stack \n");
                    else
                        printf("vacant stack \n");
            break;

            case 5: delete_stack(S);
            break;

            case 6: display_stack(S);
            break;

            default: printf("wrong choice \n");
        }
        menu();
        printf("choice: ");
    } 
}