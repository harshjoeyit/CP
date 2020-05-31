#include<stdio.h>
#include<stdlib.h>


#define MAXSIZE 20
#define N 5


struct ArrayQueue
{
    int *front;             
    int *rear;
    int *array;
};


struct ArrayQueue* Queue()
{
    struct ArrayQueue *Q = (struct ArrayQueue *)malloc( sizeof(struct ArrayQueue));
    if( !Q )
        return NULL;

    Q->front = (int *)calloc( 1 , N * sizeof(int) );
    if( !Q->front)
        return NULL;
    Q->rear = (int *)calloc( 1 , N * sizeof(int) );
    if( !Q->rear )
        return NULL;

    for( int i = 0 , k = -1; i < N; i++ , k = k + MAXSIZE/N )
    {

        Q->front[i] = k+1;
        Q->rear[i] = k;
    }

    Q->array = (int *)calloc(MAXSIZE, sizeof(int));
    
    if( !Q->array )
        return NULL;
    
    return Q;
}



int is_empty_left(struct ArrayQueue *Q, int Qno)       // 1 - N
{
    if(Qno == 1)
        return (Q->front[0] != 0);
    
    return (Q->rear[Qno-2] < Q->front[Qno-1] - 1);        // indexes: 0 -N-1
}


int is_empty_right(struct ArrayQueue *Q, int Qno)
{
    if(Qno == N)
        return (Q->rear[N-1] != MAXSIZE-1);

    return (Q->rear[Qno-1] < Q->front[Qno] - 1);
}


int is_full_queue(struct ArrayQueue *Q, int Qno)
{
    return ( !is_empty_left(Q, Qno) && !is_empty_right(Q, Qno) );               
}   



void enqueue( struct ArrayQueue *Q , int data, int Qno )
{
    if(is_full_queue(Q, Qno))
    {
        printf("Overflow\n");
        return;
    }

    int front = Q->front[Qno-1];
    int rear = Q->rear[Qno-1];
    int i;

    if(is_empty_right(Q, Qno))          // enqueue without shifting 
    {
        Q->array[++Q->rear[Qno-1]] = data;
    }

    else if(is_empty_left(Q, Qno))      // shifting required 
    {
        for(i = front; i <= rear; i++ )
            Q->array[i-1] = Q->array[i];
        
        Q->array[rear] = data;
        --Q->front[Qno-1];
        // front would come down
    }
}



int dequeue( struct ArrayQueue *Q, int Qno )
{
    int data = -1;
    if( Q->rear[Qno-1] < Q->front[Qno-1])
        printf("underflow\n");
    else
        data = Q->array[Q->front[Qno-1]++];
    
    return data;
}




void display_queue( struct ArrayQueue *Q )
{
    if(Q)
    {  
        for(int i = 0; i < N; i++ )
        {
            printf("Queue %d: ",i+1 );
            if( Q->front[i] > Q->rear[i] )
            {
                printf("empty\n");
                continue;
            }

            for(int j = Q->front[i];  j <= Q->rear[i];  j++ )
                printf("%d  ",Q->array[j] );
            
            printf("\n");
        }
    }
}



void menu()
{
    printf("\n\n0. Exit \n");
    printf("1. Enqueue \n");
    printf("2. DeQueue \n");
    printf("3. Display \n\n");  
 
}



// driver function
int main()
{

    int data, choice, Qno;
    struct ArrayQueue *Q = Queue();
   
    menu();

    printf("choice :");
    while( scanf("%d",&choice) )
    {     
        switch(choice)
        {
            case 0: exit(0);
            break;

            case 1: printf("data: ");
                    scanf("%d",&data);
                    printf("Qno: ");
                    scanf("%d", &Qno);
                    enqueue(Q,data,Qno);
            break;

            case 2: printf("Qno: ");
                    scanf("%d", &Qno);
                    data = dequeue(Q,Qno);
                    printf("removed: %d\n",data);
            break;

            case 3: display_queue(Q);
            break;

            default: printf("wrong choice \n");
        }
        menu();
        printf("choice: ");
    } 
}