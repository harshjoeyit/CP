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



// issue if k > nodes - resolve
// approach - break a set of k nodes at a time and then link this set next set of k nodes , if  set of k is not formed , then link to rest list unchanged
struct node* reverse_in_groups_of_k( struct node **head , int k )
{

    struct node *c ,*p, *n, *tt , *new_head;           //c = current, p = previous, tt = tail of the set formed of k nodes
    c = *head;                                          // start from head 
    n = c->next;
    new_head = NULL;
    int i;

    while( c != NULL )                                 // untill c reaches NULL
    {
        p = NULL;                                       // to make set of k , we need p pointer to be NULL in each iteration
        tt = c;                                         // c becomes tt in each iteration
    
        label:
        i = 1;
        while( (i<=k) && c )                            // removing and reversing k nodes 
        {
            c->next = p;
            p = c; 
            c = n;
            if(n)
                n = n->next;
            ++i;
        }

        if( (i-1) != k)                                 // if there are less than k nodes ,  
        {
            c = p;                                      // REREVERSING THE REVERSED ELEMENTS IN THE previous while loop ,which terminates when c becomes NULL 
            p = NULL;
            n = c->next;
            k = i-1;                                    // no wwe want the label loop to run for i-1 times so k = i-1 as remaining nodes = i-1                  // we start 
            goto label;                                 // go to loop agian 
        }                                               // now if condition is checked again then i-1 = k

        if(new_head == NULL)
            new_head = p;                               // making new_head exception for 1st run
        if( tt != *head )                               // exception for 1st run
            (*head)->next = p;
        *head = tt;                                     // changing head to tail of next set of k nodes
    }
    *head = new_head;
    return *head;

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

    cout<<"k: ";
    cin>>n;
    head = reverse_in_groups_of_k( &head ,n);
    display(head);
}