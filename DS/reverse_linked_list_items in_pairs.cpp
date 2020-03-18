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




struct node* reverse_in_pairs( struct node **head )
{
    struct node *p , *c ,*n ,*th1 ,*th2 ;                           //p - previous , c - current , n - next 
    c = *head;                                                      // th1 - temp head of pair removed from list
    *head = NULL;                                                   // th2 - temp head of next pir removed from list
    n = c->next;                                                    
    p = NULL;

    while( (c) && (c->next) )                                       // terminating condition
    {
        int i=2;                                                    // since we want to remove & reverse a pair at once
        th1 = p;
        p = NULL;

        while( i-- )                                                
        {                   
            c->next = p;                                            // reversing & removing 2 nodes at once
            p = c;
            c = n;
            if(n)                                                   // if n becomes null before 2 iterations
                n = n->next;
        }

        th2 = p;                                                    
        if( *head == NULL )                                        // *head points to the head of 1st pair reversed and removed 
            *head = th2;
        if(th1)                                                     // for the first iteration of the outer while loop th1 is NULL
            th1->next->next = th2;                                  // the tail of one removed pair points to the head of next removed pair
    }                                                               // all the iterations have ended th2 points to the head of last pair removed 
    th2->next->next = c;                                            // for odd no of elements , 1 elements remains , c points to last element ,so for linking it 
    return *head;                                                   // for even elements , c = NULL 
}       




// same approach but easier implementation
struct node* recursive_reverse_in_pairs( struct node *head )
{
    if( head == NULL || head->next == NULL )                                // terminating condition
        return head;                                                        // in case of odd nodes , returns the head pointing to last node
                                                                            // in case of even returns NULL
    struct node *p , *n;
    int i =2;
    p = NULL;               // p - previous
    n = head->next;         // n - next

    while(i--)                                                              // removing and reversing a pair
    {
        head->next = p;
        p = head;
        head = n;
        if(n)   
            n = n->next; 
    }

    p->next->next = recursive_reverse_in_pairs( head );                     // the tail of 1st removed pair points to the head of next, and so on
    
    return p;                                                               // returnnig the temporary head pointer of removed and reversed pair
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
    struct node *head1 = NULL;
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

    head1 = reverse_in_pairs( &head1 );
    display( head1);

    head1 = recursive_reverse_in_pairs( head1 );
    display( head1);
}