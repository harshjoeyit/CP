#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 8

struct array_stack
{
    int top1;             // for index in the array
    int top2;             // ''   ''   ''
    int base2;
    int *array;
};



struct array_stack *create_stack()
{
    struct array_stack *S = (struct array_stack *)malloc(sizeof(struct array_stack));
    if( !S )
        return NULL;

    S->top1 = -1;          
    S->top2 = MAXSIZE/2 - 1;
    S->base2 = S->top2;
    S->array =  (int *)calloc( 1 , MAXSIZE * sizeof(int) );

    return S;
}




int is_empty_stack( struct array_stack *S )
{
    return ( (S->top1 + 1) + (S->top2 - S->base2) != MAXSIZE ) ;                        // returns 1 if true , else returns 0
}




int is_full_stack(struct array_stack *S )
{
    return ( (S->top1 + 1) + (S->top2 - S->base2) == MAXSIZE );                // returns 1 if true , else return 0
}   //  meaning S->b is next index of S->t




void Push( struct array_stack *S , int data , int stackNo )  // stackNo - 1 begin of array stackNo - 0 bottom of array
{
    if( is_full_stack (S) )
        printf("Stack Overflow \n");  
    else
    {
        if( stackNo == 1)
        {
            if( S->top1 == S->base2 )
            {
                for( int i = S->top2+1; i > S->base2; i-- )
                    S->array[i] = S->array[i-1];
                ++S->base2; 
                ++S->top2;
            }
            S->array[ ++S->top1 ] = data;
        }
        else
        {
            if( S->top2 == MAXSIZE - 1 )
            {
                for( int i = S->base2; i < S->top2; i++ )
                    S->array[i] = S->array[i+1];
                --S->base2; 
                --S->top2;              // so that the statement ouside if, works
            }
            S->array[ ++S->top2 ] = data;
        }
    }
}




int Pop( struct array_stack *S , int stackNo )   // stackNo - 1 for begin of array stackNo - 0 for end of array
{
    if( stackNo == 1)
    {
        if( S->top1 == -1 )
            return -1;
        else
            return( S->array[S->top1--] );
    }

    else
    {
        if( S->top2 == S->base2 )
            return -1;
        else
            return( S->array[S->top2--] );
    }
}




void delete_stack( struct array_stack *S )
{
    if(S)
    {
        if(S->array)
            free(S->array);
        free (S);
    }
    printf("deleted\n");
    exit(1);
}





void display_stack(struct array_stack *S)
{
    if(S)
    {  
        printf("top:\t");

        if( S->top1 == -1 )
            printf("empty");
        else
        {
            for(int i = S->top1;  i > -1;  i--)
                printf("%d\t",S->array[i] );
        }
        // from bottom
        printf("\nbottom:\t");

        if( S->top2 == S->base2 )
            printf("empty");
        else
        {
            for(int i = S->top2;  i > S->base2;  i--)
                printf("%d\t",S->array[i] );
        }
        printf("\n");
        printf("top1: %d\n",S->top1);
        printf("top2: %d\n",S->top2);
        printf("base2: %d\n",S->base2);
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

    int  data , choice , stackNo;
   
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
                    printf("stackNo: ");
                    scanf("%d",&stackNo);
                    Push(S,data,stackNo);
            break;

            case 2: printf("stackNo: ");
                    scanf("%d",&stackNo);
                    printf("pop %d",Pop(S , stackNo));
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