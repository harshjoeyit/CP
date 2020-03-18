#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};



void insert_node(struct node **head , int info , int pos)            // adding at a position means that in the final list that elenment will be at that given position
{
    struct node *temp = new node;
    temp-> data = info;

    if(*head == NULL)
    {
        *head = temp;
        (*head)->next = NULL;
        cout<<"added"<<endl;
        return;
    }

    if(pos == 1)
    {
       temp->next = *head;
       *head = temp;
       cout<<"added "<<endl;
       return;
    } 

    int n=0;
    struct node *ptr,*last;                                     // if we want to work with one pointer the (last) then below cpde must be changed and n must be initialized to 1
    ptr = *head;

    while(ptr != NULL)
    {
        ++n;
        last = ptr;
        ptr = ptr->next;
    }

    if(pos == n+1)                                              // adding data after last node
    {
        last->next = temp;
        temp->next = NULL;
        cout<<"added "<<endl;
        return;
    }

    else if(pos < n+1)                                           // adding in between nodes
    {
        struct node *temp2 = *head;
        
        pos = pos-2;
        while(pos--)
            temp2 = temp2->next;

        temp->next = temp2->next;
        temp2->next = temp;
        
        cout<<"added "<<endl;
        return;
    }

    else if(pos > n+1)                                            // if nodes are less then position
    {
        cout<<"not possible"<<endl;
        return;
    }

}





void sort_list( struct node **head )
{
    struct node *temp = new node;                               // adding a temporary node and making t head of the lonked list;
    temp->data = INT_MAX;                                       // for the sake of condition 1
    temp->next = *head;
    *head = temp;                                               

    struct node *head2 = NULL , *p ,*r ,*last;                 // p - pointer to previous node to be unlinked , r -  pointer to node to be unlinked
    int min;

    while( (*head)->next != NULL )                             // finally there is only 1 element in the linked list , head points to it
    {
        temp = *head;
        min = INT_MAX;

        while( temp->next != NULL )                            // on each traversal , min is, p -s pointer to previous node to min 
        {
 /*1*/      if( temp->next->data < min )
            {
                min = temp->next->data;
                p = temp;
            }
            temp = temp->next;
        }                                                       // unlinking the min value node
        r = p->next;
        p->next = r->next;
        r->next = NULL;


        if( head2 == NULL )                                    // creating the new head , last (for the sake of linking other nodes in the list)
        {
            head2 = r;
            last = r;
        }
        else                                                   // linking the rest
        {
            last->next = r;
            last = r;
        }

    }
    *head = head2;                                               // reassigning the value of the head
}




void display(struct node *head)
{
    struct node *temp = head;

    if(head == NULL)
        cout<<"empty list"<<endl;

    else
    {
        cout<<"list: "<<endl;
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
    
}





int main()
{
    struct node *head = NULL;
    int n, data;
    cout<<"nodes: ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<i+1<<". data: ";
        cin>>data;
        insert_node(&head,data,i+1);
    }
    
    display(head);

    sort_list( &head );

    cout<<endl<<"sorted ";
    display(head);

}