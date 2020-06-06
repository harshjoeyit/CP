#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20
#define N 5

struct array_stack
{
    int *top;             
    int *base;
    int *array;
};


//stack no start from 1 to N


struct array_stack *create_stack()
{
    struct array_stack *S = (struct array_stack *)malloc(sizeof(struct array_stack));
    if( !S )
        return NULL;

    S->top = (int *)calloc( 1 , N * sizeof(int) ); 
    S->base = (int *)calloc( 1 , N * sizeof(int) );

    for( int i = 0 , k = -1; i < N; i++ , k = k + MAXSIZE/N )
        S->top[i] = S->base[i] = k;

    S->array =  (int *)calloc(MAXSIZE, sizeof(int) );

    if( !S->top || !S->base || !S->array )
        return NULL;
    return S;
}


int is_empty_left(struct array_stack *S, int Stackno)       // 1 - N
{
    if(Stackno == 1)
        return (S->base[0] != -1);
    
    return (S->top[Stackno-2] < S->base[Stackno-1]);        // indexes: 0 -N-1
}



int is_empty_right(struct array_stack *S, int Stackno)
{
    if(Stackno == N)
        return (S->top[N-1] != MAXSIZE-1);
    
    return (S->top[Stackno-1] < S->base[Stackno]);
}



int is_full_stack(struct array_stack *S , int Stackno)
{
    return ( !is_empty_left(S, Stackno) && !is_empty_right(S, Stackno) );               
}   




void Push( struct array_stack *S , int data , int Stackno )  // stackNo - 1 begin of array stackNo - 0 bottom of array
{
    if(is_full_stack(S, Stackno))
    {
        printf("Stack Overflow\n");
        return;
    }

    int top = S->top[Stackno-1];
    int base = S->base[Stackno-1];
    int i;

    if(is_empty_right(S, Stackno))          // push without shifting 
    {
        S->array[++S->top[Stackno-1]] = data;
    }

    else if(is_empty_left(S, Stackno))      // shifting required 
    {
        for(i = base+1; i <= top; i++ )
            S->array[i-1] = S->array[i];
        
        S->array[top] = data;
        --S->base[Stackno-1];
        // base would come down
    }
    
}




int Pop( struct array_stack *S , int Stackno )   // stackNo - 1 for begin of array stackNo - 0 for end of array
{
    int data = -1;
    if( S->base[Stackno-1] == S->top[Stackno-1])
        printf("underflow\n");
    else
        data = S->array[S->top[Stackno-1]--];
    
    return data;
}





void display_stack(struct array_stack *S)
{
    if(S)
    {  
        for(int i = 0; i < N; i++ )
        {
            printf("Stack %d: ",i+1 );
            if( S->top[i] == S->base[i] )
            {
                printf("empty\n");
                continue;
            }

            for(int j = S->top[i];  j > S->base[i];  j--)
                printf("%d  ",S->array[j] );
            
            printf("\n");
        }
    }
}


void menu()
{
    printf("\n\n0. Exit \n");
    printf("1. Push \n");
    printf("2. Pop \n");
    printf("3. display \n\n");  
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
                    scanf("%d", &data);
                    printf("stackNo: ");
                    scanf("%d", &stackNo);
                    Push(S, data, stackNo);
            break;

            case 2: printf("stackNo: ");
                    scanf("%d",&stackNo);
                    printf("pop %d",Pop(S , stackNo));
            break;

            case 3: display_stack(S);
                    
            break;

            default: printf("wrong choice \n");
        }
        menu();
        printf("choice: ");
    } 
    
}