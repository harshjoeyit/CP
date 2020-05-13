#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *start = NULL;

// menu
int menu()
{
    printf("1. Create List \n") ; 
    printf("2. Add at begining\n"); 
    printf ("3. Add after \n");
    printf("4. Delete\n"); 
    printf("5. Display\n"); 
    printf("6. Search\n") ; 
    printf("7. Reverse\n") ;
    printf("8. Quit\n");

    int choice;
    scanf("%d",&choice);
    return choice;
}

void create_list(int data)
{
    struct node *q;
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp ->info  = data;
    temp ->link = NULL;

    if(start == NULL ) // if the list is empty
        start = temp;
    else
    { // element to be inserted at the end 
        q = start;
        while(q->link!=NULL)
        q = q->link;
        q->link = temp;
    }
}

void addatbeg(int data)  // making this node the new head 
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp-> info = data;
    temp ->link = start;
    start = temp;
}

void addafter(int data , int pos)
{
    struct node *temp, *q;
    int i;
    q = start;
    for(i=1; i<pos; i++)
    {
        q = q->link;
        if(q==NULL)
        {
            printf("there are less than %d elements \n",pos);
            return ;
        }
    }
    temp =(struct node*) malloc(sizeof(struct node));
    temp ->info = data;
    temp -> link = q->link;
    q->link = temp;
}

void del(int data)
{
    struct node *temp,*q;
    if(start-> info ==  data)
    {
        temp = start;
        start = start-> link ;
        free(temp);
        return;
    }
    q = start;
    while(q-> link->link != NULL)
    {
        if( q-> link -> info == data)
        {
            temp = q->link;
            q->link = temp ->link;  // address of next node stored  in the node previous to be deleted
            free(temp);
            return;
        }
        q = q->link;
    }
    if(q -> link->info == data ) // last element deleted 
    {
        temp = q->link;
        free(temp);
        q->link = NULL;
        return;
    }
    else
        printf("could not find the element: \n");
}


void search(int data)
{
    struct node *ptr = start;
    int pos = 1;
    while(ptr != NULL)
    {
        if(ptr->info == data)
        {
            printf("\ndata found -> %d at the position %d\n",data,pos);
            return;
        }
        ptr = ptr ->link;
        pos++;
    }
    if(ptr == NULL)
        printf("\nitem %d not found in the list \n",data);
}

// printing the list 
void display()
{   
    struct node* ptr = start;
    if(start == NULL)
    {
        printf("list is empty: \n");
        return;
    }
    printf("info:");
    while(ptr != NULL)
    {
        printf("%d,",ptr -> info);
        ptr = ptr->link;
    }
    printf("\n");
}

// check this function 
/*void reverse()
{
    struct node *p1,*p2,*p3;
    if(start->link = NULL)
        return ;

    p1= start;
    p2 = p1->link;
    p3 = p2->link;

    p1 ->link = NULL;
    p2 ->link = p1;
    while(p3!=NULL)
    {
        p1=p2;
        p2=p3;
        p3=p2->link;
        p2->link = p1;
    }
    start = p2;
}
*/ 

//..................MAIN...........................

int main()
{
    int choice,nodes,i,node_value,pos;

    do{  //// only do-while is suitable here for our job
        choice = menu();

        switch(choice)
        {
            case 1: 
                printf("number of nodes");
                scanf ( "%d" , &nodes) ; 
                for(i=0; i<nodes; i++) 
                {
                    printf("enter element: ");
                    scanf("%d",&node_value);
                    create_list(node_value);
                }
            break;

            case 2:
                printf("enter element: ");
                scanf("%d",&node_value);
                addatbeg(node_value);
            break;

            case 3:
                printf("enter the element: ");
                scanf("%d",&node_value);
                printf("position: ");
                scanf("%d",&pos);
                addafter(node_value,pos);
            break;

            case 4:
                if(start == NULL)
                    printf("list is empty: \n");
                else
                {
                    printf("delete: ");
                    scanf("%d",&node_value);
                    del(node_value);
                }     
            break;

            case 5:
                display();
            break;

            case 6:
                printf("search: ");
                scanf("%d",&node_value);
                search(node_value);
            break;

            case 7:
                reverse();
            break;

            case 8:
                printf("exiting: ");
                exit(1); 
            break;

            default: printf("\n invalid choice \n");
            break;
        }

    }while(choice!=8);  /*here u must use the semi colon important */
}