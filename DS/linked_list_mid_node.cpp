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

// for even no. of nodes mid nod = n/2
// for odd no. of nodes mid node p= (n+1)/2 or n/2 + 1


struct node* return_mid_node( struct node **head )
{
    struct node *fastptr , *slowptr;
    fastptr = slowptr = *head;

    while( (fastptr->next != NULL) && ( fastptr->next->next != NULL ))
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }
    return slowptr;
}




bool odd_or_even( struct node **head )
{
    struct node *fastptr = *head;
    while( fastptr && fastptr->next )
        fastptr= fastptr->next->next;
    if(fastptr)
        return 0;
    else
        return 1;
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

    struct node *mid = return_mid_node( &head );
    cout<<"mid_node: "<<(mid->data)<<endl;

    bool x = odd_or_even(&head);
    if(x)
        cout<<"even";
    else
        cout<<"odd";
}