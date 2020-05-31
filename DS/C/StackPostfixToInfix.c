#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define MAXSIZE 20

struct String
{
    char arr[20];
};

struct evalStack
{
    int top;
    int capacity;
    struct String *array;
};


struct evalStack *create_stack()
{
    struct evalStack *S =  (struct evalStack* )malloc( sizeof(struct evalStack));
    if( !S )
        return NULL;
    
    S->capacity = MAXSIZE;
    S->top = -1;
    S->array =  (struct String* )malloc( S->capacity*sizeof(struct String));

    return S;
}


int is_empty_stack( struct evalStack *S )
{
    return( S->top == -1 );                         // returns 1 if true , else returns 0
}


int is_full_stack(struct evalStack *S )
{
    return (S->top == S->capacity -1 );                // returns 1 if true , else return 0
}



void Push( struct evalStack *S , char a[] )
{
    // S->top == S->capacity- 1 indicates that the stack is full
    if( is_full_stack (S) )
        printf("stack overflow \n");
    else
    {
        int i;
        ++S->top;

        for( i = 0; i< strlen(a) ; i++  )
            S->array[S->top].arr[i] = a[i];

        S->array[S->top].arr[i] = '\0';
    }
}


char* Pop( struct evalStack *S )
{
    // S->top == -1 
    if( is_empty_stack(S) ) 
    {
        printf("empty \n");
        return NULL;
    }
    else
    return(S->array[S->top--].arr);
}


void display_stack(struct evalStack *S)
{
    if(S)
    {   
        printf("stack from top: \n");
        if(S->top == -1 )
            printf(" empty \n");
        else
        {
            for(int i = S->top; i>= 0; i--) // dislay from the top
                printf(" %s\n", S->array[i].arr );
        }
    }
}





char* PostfixToInfix( struct evalStack *S , char expr[] )
{
    char a[6] = {};          // upto 5 digit numbers , last block for '\0'
    int idx = 0; 
    
    for( int i = 0; i < strlen(expr) ; i++ )
    {

        if( expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' || expr[i] == '^' || expr[i] == '$' )
        {
            int j = 0;
            char *B = Pop(S);           // THE ORDER IS IMPORTANT 
            char *A = Pop(S);           // B IS POPPED EARLIER
            char val[20];

            val[j++] = '(';
            
            for( int i = 0; i<strlen(A); i++ )
                val[j++] = A[i];
            
            val[j++] = expr[i];
            
            for( int i = 0; i<strlen(B); i++ )
                val[j++] = B[i];
            
            val[j++] = ')';
            val[j++] = '\0';

            Push( S , val );
        }

        else if( expr[i] == ' ' )
        {
            if( idx != 0 )     // a has some value stored
            {
                a[idx++] = '\0';        // important the string must terminate
                Push(S, a);
                idx = 0;
            }
        }

        else
            a[idx++] = expr[i];
    }
    return Pop(S);

}




// driver function
int main()
{
    struct evalStack *S = create_stack();

    char expr[30];
    printf("enter space seperated postfix expression \n");
    gets(expr);         // for inputting space seperated

    char *infix = PostfixToInfix(S , expr);
    printf("infix : %s",infix);
}