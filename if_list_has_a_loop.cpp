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




bool check_circular( struct node *head)                                     // the two pointers may be meeting at any one node in the loop 
{                                                                           // IMP :  they only meet at head when the linked list is snake 
    struct node *h = head;                                  
    struct node *t = head;                                  

    while( t && h && (h->next) )
    {
        t = t->next;
        h = h->next->next;

        if( h == t )
        {
            if( h == head )
                cout<<"snake"<<endl;
            else
                cout<<"snail"<<endl;             
            return 1;
        }
    }
    return 0;
}





struct node* snake_or_snail( struct node **head )
{
    struct node *h = *head;                                  
    struct node *t = *head;  
    bool if_loop = 0;                                

    while( t && h && (h->next) )
    {
        t = t->next;
        h = h->next->next;

        if( h == t )
        {
            if_loop = 1;
            break;
        }
    }

    if(if_loop == 1)
    {
        t = *head;                                                   // reposition t to head 
        while( t != h )
        {
            t = t->next;
            h = h->next; 
        }
        if( t == *head )
            cout<<"snake"<<endl;
        else
            cout<<"snail"<<endl;

        return t;                                                    // t == h is the head of the loop whether it is asnail or it is a snake 
                                                                // by this technoque loops can be easily removed
    }
    else
    {
        cout<<"not circular "<<endl;
        return NULL;
    }
    
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



// driver unction
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

    struct node *last = head ,*ptr;
    while(last->next != NULL)
        last = last->next;

    cout<<" n pointer_link from last: ";                    // to make list circular n < total nodes , else n > nodes 
    cin>>n;
    ptr = nth_from_the_end_hashing( &head , n );
    node_address.clear();
    last->next = ptr; 
    
    bool cc =  check_circular( head );
    if(cc)
        cout<<"circular "<<endl;
    else
        cout<<"not circular"<<endl;

    struct node *sos = snake_or_snail( &head );
    if(sos)
        cout<<"loop head : "<<(sos->data);
}