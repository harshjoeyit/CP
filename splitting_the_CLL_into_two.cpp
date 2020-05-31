#include<bits/stdc++.h>
using namespace std;



struct CLLnode
{
    int data;
    struct CLLnode *next;
};


int flag = 0;



void insert_at_end( struct CLLnode **head, int info )
{
    struct CLLnode *temp = new CLLnode;
    temp->next = temp;                                  // next pointer points to itself
    temp->data = info;

    if( *head == NULL )                                    // if list is empty, no element 
    {
        *head = temp;
        if(flag == 1)
            flag = 0;
    }

    else
    {
        struct CLLnode *last = *head;
        
        while( last->next != *head )
            last = last->next;

        temp->next = *head;
        last->next = temp;
        if(flag == 1)
        {
            *head = temp;
            flag = 0;
        }
    }
}





void display(struct CLLnode *head)
{
    struct CLLnode *temp = head;

    if(head == NULL)                                   // no element 
        cout<<"empty CLL"<<endl;

    else
    {
        cout<<"CLL: "<<endl;
        do
        {
            cout<<temp->data<<" ";
            temp = temp->next;

        }while(temp != head);
    }
    cout<<endl;
    
}




void split_into_two( struct CLLnode *head )
{
    struct CLLnode *fptr , *sptr , *head2;                              // head 2 for the second circular list that will be formed 
    fptr = sptr = head;

    while( (fptr->next != head ) && (fptr->next->next != head ) )
    {
        fptr = fptr->next->next;
        sptr = sptr->next;
    }

    if(head->next == head)                                                  // condition for 1 node list
    {
        head2 = NULL;                                                       // if there is only 1 node then second list is empty    
    }
    else if( fptr->next == head )                                            // if nodes are odd the this condition is true
    {
        head2 = fptr->next = sptr->next;                                
    }
    else                                                                    // if nodes are even then this condition is ture 
    {
        head2 = fptr->next->next = sptr->next;
    }
    sptr->next = head;

    display( head );
    display( head2 );
}




//driver program
int main()
{
    struct CLLnode *head = NULL;

    int n,data;
    cout<<"nodes: ";
    cin>>n;

    while(n--)
    {
        cout<<"data: ";
        cin>>data;
        insert_at_end(&head , data);
    }

    display(head);

    split_into_two(head);
}