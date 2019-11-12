#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node *link;
};



void insert_node(struct node **head , int info , int pos) // adding at a position means that in the final list that elenment will be at that given position
{
    struct node *temp = new node;
    temp-> data = info;

    if(*head == NULL)
    {
        *head = temp;
        (*head)->link = NULL;
        cout<<"added"<<endl;
        return;
    }

    if(pos == 1)
    {
       temp->link = *head;
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
        ptr = ptr->link;
    }

    if(pos == n+1)                                   // adding data after last node
    {
        last->link = temp;
        temp->link = NULL;
        cout<<"added "<<endl;
        return;
    }

    else if(pos < n+1)                           // adding in between nodes
    {
        struct node *temp2 = *head;
        
        pos = pos-2;
        while(pos--)
            temp2 = temp2->link;

        temp->link = temp2->link;
        temp2->link = temp;
        
        cout<<"added "<<endl;
        return;
    }

    else if(pos > n+1)                            // if nodes are less then position
    {
        cout<<"not possible"<<endl;
        return;
    }

}




// list must be sorted
void insert_in_sorted_list( struct node **head , int data)
{
    struct node *greater, *lesser,*temp;
    greater = lesser = *head;
    temp = new node;
    temp->data = data;
    int flag = 0;

    if( *head == NULL )
    {
        *head = temp;
        (*head)->link = NULL;
    }

    while( (greater != NULL) && (greater->data < data) )
    {
        flag = 1;
        lesser = greater;
        greater = greater->link;
    }

    if( flag )
    {
        temp->link = greater;
        lesser->link = temp;
    }
    else
    {
        temp->link = greater;
        *head = temp;
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
            temp = temp->link;
        }
    }
}



int main()
{
    struct node *head = NULL;
    int x;
    cout<<"insert a few elements in the list "<<endl;
    for(int i =0; i<5; i++)
    {
        cout<<"data: ";
        cin>>x;
        insert_in_sorted_list( &head , x );                       // inserting with the help of this function only
    }

    display(head);

    cout<<"insert in sorted ";
    while(cin>>x)
    {
        insert_in_sorted_list( &head, x );
        display(head);
        cout<<"insert in sorted "; 
    }
}