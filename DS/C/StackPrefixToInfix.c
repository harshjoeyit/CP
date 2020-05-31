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


struct evalStack *create_stack1()
{
    struct evalStack *S =  (struct evalStack* )malloc( sizeof(struct evalStack));
    if( !S )
        return NULL;
    
    S->capacity = MAXSIZE;
    S->top = -1;
    S->array =  (struct String* )malloc( S->capacity*sizeof(struct String));

    return S;
}


int is_empty_stack1( struct evalStack *S )
{
    return( S->top == -1 );                         // returns 1 if true , else returns 0
}


int is_full_stack1(struct evalStack *S )
{
    return (S->top == S->capacity -1 );                // returns 1 if true , else return 0
}



void Push1( struct evalStack *S , char a[] )
{
    // S->top == S->capacity- 1 indicates that the stack is full
    if( is_full_stack1 (S) )
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


char* Pop1( struct evalStack *S )
{
    // S->top == -1 
    if( is_empty_stack1(S) ) 
    {
        printf("empty \n");
        return NULL;
    }
    else
    return(S->array[S->top--].arr);
}





char* PrefixToInfix( struct evalStack *S , char Expr[] )
{
    char a[6] = {};          // upto 5 digit numbers , last block for '\0'
    int idx = 0; 
    int n = strlen(Expr);

    char expr[n];

    for( int i = 0; i < n ; i++ )       // expr is the reverse of the string passed 
        expr[i] = Expr[n-i-1];          //COPYING THE REVERSE STRING  
    
    for( int i = 0; i < n; i++ )
    {

        if( expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' || expr[i] == '^' || expr[i] == '$' )
        {
            int j = 0;
            char *B = Pop1(S);           // THE ORDER IS IMPORTANT 
            char *A = Pop1(S);           // B IS POP1PED EARLIER
            char val[20];

            val[j++] = ')';             // CHANGING THE OPENING BRACKET TO CLOSED(when comparing postfix version)
            
            for( int i = 0; i<strlen(A); i++ )
                val[j++] = A[i];
            
            val[j++] = expr[i];
            
            for( int i = 0; i<strlen(B); i++ )
                val[j++] = B[i];
            
            val[j++] = '(';             // CLOSED BRACKET IS CHANGED TO OPEN(when comparing postfix version) 
            val[j++] = '\0';

            Push1( S , val );
        }

        else if( expr[i] == ' ' )
        {
            if( idx != 0 )              // a has some value stored
            {
                a[idx++] = '\0';        // important the string must terminate
                Push1(S, a);
                idx = 0;
            }
        }

        else
            a[idx++] = expr[i];
    }

    char *res = Pop1(S);
    for( int i = 0; i < n ; i++ )           // REVERSING THE RESULT STRING 
        Expr[i] = res[n-1-i];

    return Expr;

}






// driver function
int main()
{
    struct evalStack *S = create_stack1();

    char expr[30];
    printf("enter space seperated prefix expression \n");
    gets(expr);         // for inputting space seperated

    char *infix = PrefixToInfix(S , expr);
    printf("infix : %s",infix);
}