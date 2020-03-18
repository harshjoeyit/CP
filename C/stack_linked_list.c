#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int data;
    struct Stack *next;
};



struct Stack* create_stack()
{
    return NULL;
}



int is_empty_stack( struct Stack **S )
{
    return( *S == NULL );                         // returns 1 if true , else returns 0
}



void Push( struct Stack **S , int data )
{
    struct Stack *temp = (struct Stack *)malloc(sizeof(struct Stack));
    temp->data = data;

    temp->next = *S;                                                // since S is intialized to be NULL , there is no need to make exception for head and other Stacks
    *S = temp;      
    printf("push success \n") ;                                               // all the Stacks get stacked over one another
}


void Pop( struct Stack **S )
{
    if( is_empty_stack(S) ) 
        printf("empty stack \n");
    
    else
    {
        struct Stack *temp = *S;
        *S = (*S)->next;
        printf("pop %d\n",temp->data);
        free(temp);
    }
}


void delete_stack( struct Stack **S)
{
    struct Stack *temp;
    while( (*S) != NULL)
    {
        temp = *S;
        *S = (*S)->next;
        free(temp);
    }
    printf("deleted\n");
}




void display_stack(struct Stack **S)
{
    if( *S == NULL)
        printf("empty stack \n");
    else
    {
        printf("stack: ");
        struct Stack *temp = *S;
        while( temp != NULL )
        {
             printf("\t%d",temp->data);
             temp = temp->next;
        }
    }
}




void menu()
{
    printf("\n\n0. Exit \n");
     printf("1. Push \n");
    printf("2. Pop \n");
    printf("3. is empty \n");
    printf("4. delete stack \n");
    printf("5. display \n\n");  
}



// driver function
int main()
{
    struct Stack *S = create_stack();                            // S - top - head of the list, stack
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
                    Push(&S,data);
            break;

            case 2: Pop(&S);
            break;

            case 3: if(is_empty_stack(&S))
                        printf("empty stack \n");
                    else
                        printf("not empty stack \n");
            break;
        
            case 4: delete_stack(&S);
            break;

            case 5: display_stack(&S);
            break;

            default: printf("wrong choice \n");
        }
        menu();
        printf("choice: ");
    } 
}