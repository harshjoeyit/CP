#include<stdio.h>
#include<stdlib.h>


struct node 
{
    int data;
    struct node *next;
};



struct LinkedQueue
{
    struct node *front , *rear;
};



struct LinkedQueue* create_queue()
{
    struct LinkedQueue *Q = (struct LinkedQueue*)malloc( sizeof(struct LinkedQueue) );
    if( !Q )
        return NULL;

    Q->front = Q->rear = NULL;
    return Q;
}



int is_empty_queue( struct LinkedQueue *Q )
{
    return(Q->front == NULL );
}



int queue_size( struct LinkedQueue *Q )
{
    struct node *temp = Q->front;
    int count = 0;

    if(temp == NULL )
        return 0;
    
    while( temp != NULL )
    {
        ++count;
        temp = temp->next;
    }
    return count;
}





void en_queue( struct LinkedQueue *Q , int data )
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if(!new_node)   
    {
        printf("memory error\n");
        return ;
    }
        
    new_node->next = NULL;
    new_node->data = data;

    if(Q->rear)
        Q->rear->next = new_node;
        
        Q->rear = new_node;
    
    if(Q->front == NULL )
        Q->front = Q->rear;
}




int de_queue( struct LinkedQueue *Q )
{
    struct node *temp;
    int data = 0;
    if( is_empty_queue(Q) )
    {
        printf("Queue is Empty !");
        return 0;
    }

    else
    {
        temp = Q->front;
        data = Q->front->data;
        Q->front = Q->front->next;
        free(temp);
    }
    return data;
}




void delete_queue( struct LinkedQueue *Q )
{
    struct node *temp;

    if( Q->front == NULL )
        printf("Empty Already !\n");
    else
    {
        while( !is_empty_queue(Q) )
        {
            temp = Q->front;
            Q->front = Q->front->next;
            free(temp);
        }
        printf("deleted\n");
    }    
}




void display_queue( struct LinkedQueue *Q )
{
    struct node *temp = Q->front;

    printf("Queue: ");
    if(is_empty_queue(Q))
    {
        printf("empty\n");
        return;
    }
    
    while( temp != NULL )
    {
        printf("%d ",temp->data );
        temp = temp->next;
    }
}





void menu()
{
    printf("\n\n0. Queue size \n");
    printf("1. Enqueue \n");
    printf("2. DeQueue \n");
    printf("3. is empty \n");
    printf("4. is full \n");
    printf("5. Delete Queue \n");
    printf("6. Display \n");  
    printf("7. exit\n\n");
}





// driver function
int main()
{

    int  data , choice;
    printf( "\nQueue\n ");

    struct LinkedQueue *Q = create_queue();
   
    menu();

    printf("choice :");
    while( scanf("%d",&choice) )
    {     
        switch(choice)
        {
            case 0: data = queue_size(Q);
                    printf("queue size: %d",data);
            break;

            case 1: printf("data: ");
                    scanf("%d",&data);
                    en_queue(Q,data);
            break;

            case 2: data = de_queue(Q);
                    printf("removed: %d\n",data);
            break;

            case 3: if(is_empty_queue(Q))
                        printf("empty Queue \n");
                    else
                        printf("not empty Queue \n");
            break;

            case 5: delete_queue(Q);
            break;

            case 6: display_queue(Q);
            break;

            case 7: exit(1);
            break;

            default: printf("wrong choice \n");
        }
        menu();
        printf("choice: ");
    } 
}