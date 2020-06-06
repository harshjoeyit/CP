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




// there is one fault i.e algorithm still takes O(n) even if the list is already even first odd later 
void even_first( struct node **head )
{
    struct node *p , *head2 , *last , *r ;                  //p - previous node , r - removed node , last - last node on list 2( of even no. )
    r = p = *head;
    head2 = NULL;

    while( p->next != NULL )
    {
        if( (*head)->data % 2 == 0 )
        {
            *head = (*head)->next;                          // removing the head   
            p = *head;                                      // since p is initialized as head so if head is removed then p also shifts
            r->next = NULL;                                 // since r points to head , so remove r
        } 
        else
        {
            r = p->next;                                    // each time r is next node of p
            if( r->data % 2 == 0)
            {
                p->next = r->next;                          // deleting the node in between
                r->next = NULL;
            }
            else
            {
                p = p->next;                                // is node pointed by r is of odd data , 
                continue;                                   // then just go to next node , skip rest code 
            }   
        }

//.............making list 2 for even no.s............
        if( head2 == NULL )                                  // pointing head2 for even nodes
        {
            head2 = r;
            last = r;
        }
        else                                                  
        {
            last->next = r;                                 // keeping a last pointer
            last = r;
        }
        r = p;
    } 
    if(head2)                                               // for the condition that there may be only odd data nodes so head2 remains NULL, head remains the same 
    {
        last->next = *head;
        *head = head2;
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

    even_first( &head );

    cout<<endl<<"new ";
    display(head);

}