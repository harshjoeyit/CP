#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};




void insert_node(struct node **head , int info , int pos)                   // adding at a position means that in the final list that elenment will be at that given position
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
    struct node *ptr,*last;                  // if we want to work with one poiter the (last) then below cpde must be changed and n must be initialized to 1
    ptr = *head;

    while(ptr != NULL)
    {
        ++n;
        last = ptr;
        ptr = ptr->next;
    }

    if(pos == n+1)                                   // adding data after last node
    {
        last->next = temp;
        temp->next = NULL;
        cout<<"added "<<endl;
        return;
    }

    else if(pos < n+1)                           // adding in between nodes
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

    else if(pos > n+1)                            // if nodes are less then position
    {
        cout<<"not possible"<<endl;
        return;
    }

}




struct node *merge_lists_with_sort( struct node **head1 ,struct node **head2 )
{
    struct node *new_head = NULL, *remove , *last;
    while( *head1 && *head2 )
    {
        if( (*head1)->data < (*head2)->data)                                 // comparing the head elements of both nodes
        {
            remove = *head1;
            *head1 = (*head1)->next;
            remove->next = NULL;                                            // remove the lesser one
        }
        else
        {
            remove = *head2;
            *head2 = (*head2)->next;
            remove->next = NULL;
        }

        if( new_head == NULL )                                               // for the first removed element becomes the new head
        {
            new_head = remove;                                              // new head is new_head
            last = new_head;
        }
        else                                                                // rest of the removed elements are linked afterwards 
        {
            last->next = remove;                                            // make a new linked list by linking  removed items  one by one
            last = last->next;
        }
    }

    if( *head1 )                                                            // one of the list terminates as its head becomes null
        last->next = *head1;
    if( *head2 )
        last->next = *head2;                                                //link the other list ( with remaining elements ) to new list right away

    *head1 = new_head;
    *head2 = NULL;
    return (*head1);                                                        // make head1 the new head

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
        cout<<endl;
    }
    
}




int main()
{
    struct node *head1 = NULL , *head2 = NULL ;
    int n, data;
    cout<<"nodes: ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<i+1<<". data: ";
        cin>>data;
        insert_node(&head1,data,i+1);
    }
    display(head1);

    cout<<"nodes: ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<i+1<<". data: ";
        cin>>data;
        insert_node(&head2,data,i+1);
    }
    display(head2);

    head1 = merge_lists_with_sort( &head1 ,&head2 );
    display( head1);
}