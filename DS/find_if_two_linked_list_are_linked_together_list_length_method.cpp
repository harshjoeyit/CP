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



struct node* connecting_node( struct node **head1 , struct node **head2 )
{
    struct node *temp = *head1 , *cpl2 , *cpl1;
    int l1 , l2 , diff;
    l1 = l2 = 0;

    while(temp != NULL )
    {
        ++l1;
        temp = temp->next;
    }

    temp = *head2;
    while( temp != NULL)
    {
        ++l2;
        temp = temp->next;
    }

    if( l2 > l1 )                               // head1 points to list with more elements 
    {                                           // head2 points to the list with less elements 
        temp = *head1;
        *head1 = *head2;
        *head2 = temp;
    }

    diff = l1 - l2;
    cpl1 = (*head1)->next;                      // boundary condition , 2nd element of list 2 could be link , or the last element on list2 could be link 
    cpl2 = (*head2)->next;

    while( diff-- )                             // moving pointer on list 1 to ( 2 + (l1-l2) )th node for comparison
    {
        if( cpl1 == *head2 )                    // if onmoving list1 we come accross head of 2
        cpl1 = cpl1->next; 
    }

    while( cpl2 && cpl1 )
    {
        if( cpl1 == cpl2 )                      // check and move forward on both lists
            return cpl2;
        cpl1 = cpl1->next;
        cpl2 = cpl2->next;
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