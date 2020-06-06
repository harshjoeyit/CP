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




vector<struct node*> node_address;                                          // stores the address of the node
struct node* nth_from_the_end_hashing( struct node **head , int n )         // time complexity = O(n) , one time traversal approach 
{
    struct node *temp = *head;
    int i;

    for( i= 0; temp != NULL; i++)                                   // insertion
    {
        node_address.push_back(temp);
        temp = temp->next;
    } 
    
    if(n<=i)
        return (node_address[i-n]);
    else
        return NULL;
}





struct node *connecting_node( struct node **head1,  struct node **head2 )
{
    struct node *ptr1 = *head1, *ptr2;

    while( ptr1 != NULL )
    {
        struct node *ptr2 = *head2; 
        while( ptr2->next != NULL )
        {
            if( ptr1->next == ptr2->next )
                return (ptr1->next);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return NULL;
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
    struct node *head1 = NULL ,*head2 = NULL;
    int n, data;
    cout<<"nodes: ";                                //list 1
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<i+1<<". data: ";
        cin>>data;
        insert_node(&head1,data,i+1);
    }
    display(head1);
    
    cout<<"nodes: ";                                //list 2
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<i+1<<". data: ";
        cin>>data;
        insert_node(&head2,data,i+1);
    }
    display(head2);


    struct node *last2 = head2 ,*ptr ,*link;
    while(last2->next != NULL)
        last2 = last2->next;

    
    cout<<" n pointer_link from last: ";                    // to make list circular n < total nodes , else n > nodes 
    cin>>n;
    last2->next = nth_from_the_end_hashing( &head1, n );
    node_address.clear();

    link = connecting_node( &head1 , &head2 );
    if(link)
        cout<<"link: "<<(link->data)<<endl;
    else
        cout<<"no link "<<endl;
    
    
}