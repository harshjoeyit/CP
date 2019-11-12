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



struct node* reverse_till_k( struct node *head , int k )
{
    struct node *c , *p , *n;
    p = NULL;
    c = head;
    n = c->next;
    int i = k;

    if( k == 0 || k == 1)
        return head;

    while( (i != 0 ) && c )
    {
        c->next = p;
        p = c;
        c = n;
        if(n)
            n = n->next;
        --i;
    }

    if( i == 0 )
    {
        head->next = c;
        head = p;
    }
    else
    {
        cout<<"list has only: "<<(k-i)<<" nodes , can't reverse "<<endl;
        head = reverse_till_k( p , (k-i) );
    }
    return head;
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

    cout<<"enter position : ";
    cin>>n;
    head = reverse_till_k( head , n );
    display(head);

}