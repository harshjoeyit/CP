#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 20

struct array_stack
{
    int top;
    int capacity;
    char *array;
};


struct array_stack *create_stack()
{
    struct array_stack *S =  (struct array_stack* )malloc( sizeof(struct array_stack));
    if( !S )
        return NULL;
    
    S->capacity = MAXSIZE;
    S->top = -1;
    S->array =  (char* )malloc( S->capacity*sizeof(char));

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




void Push( struct array_stack *S , char data )
{
    // S->top == S->capacity- 1 indicates that the stack is full
    if( is_full_stack (S) )
        printf("stack overflow \n");
    else
    {
        S->array[++S->top] = data;
    }
}


char Pop( struct array_stack *S )
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



void display_stack(struct array_stack *S)
{
    if(S)
    {   
        printf("stack : ");
        if(S->top == -1 )
            printf(" empty \n");
        else
        {
            for(int i = 0; i<= S->top; i++ ) // dislay from the top
                printf(" %c ",S->array[i] );
        }
        printf("\n");
    }
}









// checks if the character is an operator or not
int operators( char ch )
{
    if( ch == '+' || ch == '-' || ch == '*' || ch == '/'  ||  ch  == '^' || ch == '$'  )
        return 1;
    else 
        return 0;
}



// reveres the string and changes the brackets 
void reverse( char expr[] , int n )
{
    char aux[n];
    int i;

    for( i = 0; i <n; i++ )
        aux[i] = expr[ n -i - 1];
    aux[i] = '\0';
    for( i = 0; i <= n; i++ )
    {
        if( aux[i] == '(' )
            expr[i] = ')';
        else if( aux[i] == ')')
            expr[i] = '(';
        else
            expr[i] = aux[i];
    }
}




int precedence( char ch )
{
    if( ch == '^' || ch == '$' )
        return 2;
    else if( ch == '/' || ch == '*' )
        return 1;
    else if( ch == '+' || ch == '-' )
        return 0;

    return 3;
}



// fully parenthesized
void infixToPostfix( struct array_stack *S , char expr[] , int n )
{
    char res[20];
    int index = 0;
    char open_bracket;

    for( int i = 0; i < n; i++ )
    {
        if( expr[i] == '(' || operators(expr[i]) )
            Push( S , expr[i] );
        
        else if( expr[i] == ')' )
        {
            while( S->array[S->top] != '(' )
                res[index++] = Pop(S);
            open_bracket = Pop(S);
        }
        else
            res[index++] = expr[i];
    }
    res[index++] = '\0';
    printf("\npostfix expr: %s\n", res);
}



// fully parenthesized 
void infixToPrefix( struct array_stack *S , char expr[] , int n )
{
    char res[20];
    int index = 0;
    char open_bracket;
                                    // reversing
    reverse( expr , n );
                                    // finding postfix expr
    for( int i = 0; i < n; i++ )
    {
        if( expr[i] == '(' || operators(expr[i]) )
            Push( S , expr[i] );
        
        else if( expr[i] == ')' )
        {
            while( S->array[S->top] != '(' )
                res[index++] = Pop(S);
            open_bracket = Pop(S);
        }
        else
            res[index++] = expr[i];
    }
    res[index++] = '\0';
                                // reversing
    reverse( res , strlen(res) );
    printf("\nprefix expr: %s\n", res);
}



// partially parenthesized 
void infixToPostfix2( struct array_stack *S , char expr[] , int n )
{
    char res[20];
    int index = 0;
    char open_bracket;

    for( int i = 0; i < n; i++ )
    {
        //...opening bracket....................
        if( expr[i] == '(' ) 
            Push( S , expr[i] );

        //....operators.....................
        else if( operators(expr[i]) )    
        {    
            // .....all the pushing conditions...............
            // empty                opening bracket               if operator if a exponent                                 precedence higher
            if((S->top == -1) ||   (S->array[S->top] == '(') || ( expr[i]  == '^' || expr[i] == '$' )  || (precedence(expr[i]) > precedence( S->array[S->top])) )
                Push( S , expr[i] );
            // .....else pop
            else
            {
                do 
                {
                    res[index++] = Pop(S);
                // pop until
                //      stack is not empty          untill ( is not found          precedence of top element is higher or equal to expr[i]
                }while( !is_empty_stack(S) && (S->array[S->top] != '(' ) && precedence(S->array[S->top]) >= precedence(expr[i]) );
                    
                // push the cureent element after popping
                Push( S , expr[i] );
            }
        }

        //.....pop on closing bracket................
        else if( expr[i] == ')' )
        {
            while( S->array[S->top] != '(' )
                res[index++] = Pop(S);
            open_bracket = Pop(S);
        }

        //...if operand .......................
        else
            res[index++] = expr[i];
    }
    
    // pop the remaining char if any 
    while( ! is_empty_stack(S) )
        res[index++] = Pop(S);

    res[index++] = '\0';
    printf("\npostfix expr: %s\n", res);
}



// partially parenthesized 
void infixToPrefix2( struct array_stack *S , char expr[] , int n )
{
    char res[20];
    int index = 0;
    char open_bracket;

    reverse( expr , n );

    for( int i = 0; i < n; i++ )
    {
        //...opening bracket....................
        if( expr[i] == '(' ) 
            Push( S , expr[i] );

        //....operators.....................
        else if( operators(expr[i]) )    
        {    
            // .....all the pushing conditions...............
            // empty                opening bracket               if operator if a exponent                                 precedence higher
            if((S->top == -1) ||   (S->array[S->top] == '(' ) || (precedence(expr[i]) > precedence( S->array[S->top])) )
                Push( S , expr[i] );

            /*IMPORTANT: the only change here with respect to the postfix conversion is that we are comparing precedence os the $ , ^ operators too ,
             on the other hand we were pushing them on the stack in postfix evaluation  without checking precedence 
            ( in short for prefix evaluation ---- $ cannot be pushed over the other $ as they have same priority)
            ( while it is not the case with the evaluation of the postfix expression where one $ can be pushed over the other $ , following the right to left evaluation )*/

            // .....else pop
            else
            {
                do 
                {
                    res[index++] = Pop(S);
                // pop until
                //      stack is not empty          untill ( is not found          precedence of top element is higher or equal to expr[i]
                }while( !is_empty_stack(S) && (S->array[S->top] != '(' ) && precedence(S->array[S->top]) >= precedence(expr[i]) );
                    
                // push the cureent element after popping
                Push( S , expr[i] );
            }
        }

        //.....pop on closing bracket................
        else if( expr[i] == ')' )
        {
            while( S->array[S->top] != '(' )
                res[index++] = Pop(S);
            open_bracket = Pop(S);
        }

        //...if operand .......................
        else
            res[index++] = expr[i];
    }
    
    // pop the remaining char if any 
    while( ! is_empty_stack(S) )
        res[index++] = Pop(S);

    res[index++] = '\0';

    reverse( res , strlen(res) );

    printf("\nprefix expr: %s\n", res);
}





void menu()
{
    printf("1. infix to postfix \n");
    printf("2. infix tp prefix \n");    
    printf("3. infix tp postfix (partially parenthesized)\n");
    printf("4. infix tp prefix (partially parenthesized)\n");
}






// driver function
int main()
{
    struct array_stack *S = create_stack();
    char expr[20];

    printf("infix expr( <20 char): ");
    scanf("%s", expr );

    int choice;
    menu();
    printf("choice: ");
    scanf("%d",&choice);

        switch(choice)
        {
            case 0: exit(1);
            break;

            case 1: infixToPostfix( S , expr , strlen(expr) );
            break;

            case 2: infixToPrefix( S , expr , strlen(expr) );
            break;

            case 3: infixToPostfix2( S , expr , strlen(expr) );
            break;

            case 4: infixToPrefix2( S , expr , strlen(expr) );
            break;

            default: printf("wrong choice \n");
        }

}