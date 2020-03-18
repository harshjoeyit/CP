#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
    
};

typedef  struct node Node;


Node* insert_node(Node *head, int coeff)
{
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->next = NULL;

    if(head == NULL )
        return newNode;
     
    Node* temp = head;
    while(temp->next != NULL )
        temp = temp->next;
        temp->next = newNode;
    
    return head;
}

void display(Node *head)
{   
    Node* ptr = head;
    if(head == NULL)
    {
        printf("list is empty: \n");
        return;
    }
    printf("info:");
    while(ptr != NULL)
    {
        printf("%d ",ptr -> coeff);
        ptr = ptr->next;
    }
    printf("\n");
}


int find_size(Node *head)
{
    if(head == NULL )
        return 0;

    return 1 + find_size(head->next);
}



Node* mid_node( Node *head )
{
    Node *fastptr , *slowptr;
    fastptr = slowptr = head;

    while( (fastptr->next != NULL) && ( fastptr->next->next != NULL ))
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }
    return slowptr;
}




Node* merge_list(Node *head)
{
    if(head == NULL || head->next == NULL)
        return head;
    
    Node *mid = mid_node(head);
    Node *mid_next = mid->next;
    mid->next = NULL;
    Node *temp = mid_next;
    
    while( temp->next != NULL )
        temp = temp->next;
    
    temp->next = head;
    return mid_next;
}


void menu()
{
    printf("\n1. insert_node \n") ; 
    printf("2. display\n"); 
    printf ("3. find size \n");
    printf("4. merge list\n\n");
}

int main()
{
    Node* head = NULL;
    int choice, coeff;

    menu();
    printf("choice: ");

    while(scanf("%d", &choice))
    {
        switch(choice)
        {
            case 1: 
                printf("coeff: ");
                scanf ( "%d" , &coeff) ; 
                head = insert_node(head, coeff);
            break;

            case 2: display(head);
            break;

            case 3: printf("size: %d", find_size(head));
            break;

            case 4: head = merge_list(head);
                    printf("merged: "); 
                    display(head);
            break;

        }
        menu();
        printf("\nchoice: ");
    }
}