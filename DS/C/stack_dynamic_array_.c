#include<stdio.h>
#include<stdlib.h>

struct dyn_array_stack
{
    int top;
    int capacity;
    int *array;
};


struct dyn_array_stack *create_stack()
{
    struct dyn_array_stack *S = (struct dyn_array_stack *)malloc(sizeof(struct dyn_array_stack));
    if( !S )
        return NULL;
    S->capacity = 1;
    S->top = -1;
    S->array =  (int *)malloc(S->capacity * sizeof(int));         // S->array is a pointer to int array
    if( !S )
        return NULL;
    return S;
}



int is_empty_stack( struct dyn_array_stack *S )
{
    return( S->top == -1 );                         // returns 1 if true , else returns 0
}



int is_full_stack(struct dyn_array_stack *S )
{
    return (S->top == S->capacity -1 );                // returns 1 if true , else return 0
}



void Push( struct dyn_array_stack *S , int data )
{
    // S->top == S->capacity- 1 indicates that the stack is full
    if( is_full_stack(S) )                              // if stack is full increse the array size by twice 
    {
        S->capacity = 2*S->capacity;
        S->array = (int * )realloc(S->array, S->capacity*sizeof(int));
    }
    S->array[++S->top] = data;

    printf("capacity: %d\n",S->capacity);
}


int Pop( struct dyn_array_stack *S )
{
    // S->top == -1 maeans emty stack
    if( is_empty_stack(S) ) 
    {
        printf("empty stack \n");
        return -1;
    }
    else
    {
        return( S->array[S->top--]);

        // int pop_val = S->array[S->top];                  // we could decrese the capacity if the no of element fall below a cartain level, but that would cost more time for push operation performed later 
        
        // if( 2*S->top == S->capacity )
        // {
        //     S->capacity = S->capacity/2;
        //     S->array = (int *)realloc(S->array,S->capacity*sizeof(int));
        // }
        // --S->top;
        // printf("capacity: %d\n",S->capacity);
        // return pop_val;
    }
}


void delete_stack( struct dyn_array_stack *S)
{
    if(S)
    {
        if(S->array)
            free(S->array);
        free (S);
    }
}



void display_stack(struct dyn_array_stack *S)
{
    if(S)
    {   
        printf("stack:\t");
        if(S->top == -1 )
            printf("empty \n");
        else
        {
            for(int i = S->top; i>= 0; i--)
                printf("%d\t",S->array[i] );
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
    struct dyn_array_stack *S = create_stack();

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