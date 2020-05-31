#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

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
        S->array[++S->top] = data;
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


// returns after operating on two operands
int operation( int A, char oper , int B )
{                   

    if( oper == '+' )
        return( A + B );
    else if( oper == '-')
        return( A - B );
    else if( oper == '*')
        return( A * B );
    else if( oper == '/')
        return( A / B );
    else 
        return( pow(A,B));
}


// convers the char array to respective int value 
int Int( char s[] )             
{
    int val = 0 , x ,j = 1;
    int i = strlen(s) - 1;

    while( i >= 0 )
    {
        x = s[i] - '0';
        val += x*j;
        j = j*10;
        i--;
    }
    return val;
}


// evaluates a postfix expression
int evaluate_postfix( struct array_stack *S , char expr[] )
{
    char a[6] = {};          // upto 5 digit numbers , last block for '\0'
    int idx = 0 , A , B , val;

    for( int i = 0; i < strlen(expr) ; i++ )
    {

        if( expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' || expr[i] == '^' || expr[i] == '$' )
        {
            A = Pop(S);
            B = Pop(S);
            val = operation( B,expr[i],A );
            Push( S , val );
        }
               
        else if(expr[i] == ' ')
        {
            if( idx != 0 )     // a has some value stored
            {
                a[idx++] = '\0';        // important the string must terminate
                Push(S, Int(a));
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
    struct array_stack *S = create_stack();
    char expr[20];
    printf("enter space seperated postfix expression \n");
    gets(expr);         // for inputting space seperated

    int value = evaluate_postfix(S , expr);
    printf("value of postfix : %d",value);
}