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




struct node *alternate_merge(struct node **head1, struct node **head2 )
{
    struct node *r , *last , *new_head;
    new_head == NULL;
    int flag = 1;

    while( *head1 && *head2 )
    {
        if(flag == 1)
        {
            r = *head1;
            *head1 = (*head1)->next;
            r->next = NULL;
            flag = 0;
        }
        else
        {
            r = *head2;
            *head2 = (*head2)->next;
            r->next = NULL;
            flag = 1;
        }

        if(new_head == NULL )
        {
            new_head = r;
            last = r;
        }
        else
        {
            last->next = r;
            last = r;
        }
    }
    if( *head1 )
        last->next = *head1;
    if( *head2 )
        last->next = *head2;

    *head1 = new_head;
    head2 = NULL;
    return *head1;
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
    struct node *head1 = NULL , *head2 = NULL;
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

    head1 = alternate_merge( &head1 , &head2 );
    display(head1);
}