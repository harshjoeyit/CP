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



void reverse( struct node **head)
{
    struct node *C,*N,*P;
    N = C = P = *head;

    while( C != NULL )
    {
        N = N->next;

        if( C == *head )
            C->next = NULL;
        else
        {
            C->next = P;
            P = C;
        }

        C = N;
    }
    *head = P;
}




struct node* recursive_reverse( struct node *head )
{
    if( head == NULL )
        return NULL;
    if( head->next == NULL )
        return head;
    
    struct node *sec_ele = head->next;
    // unlink head , trap in loop
    head->next = NULL;
    //reverse everything from second element onwards
    struct node *reverse_rest = recursive_reverse( sec_ele );   // reverse_rest is the head pointer of fina list
    // reconnect sec element to unlinked node
    sec_ele->next = head;
    return reverse_rest;            // this is the head node returns in all recursive just as it is 
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
            cout<<temp->data<<endl;
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

    reverse(&head);
    cout<<"recursive reverse : "<<endl;
    display(head);

    head = recursive_reverse( head );
    cout<<"recursive reverse : "<<endl;
    display(head);


}