#include<bits/stdc++.h>
using namespace std;



struct CLLnode
{
    int data;
    struct CLLnode *next;
};


int flag = 0;


void insert_at_end( struct CLLnode **head, int info )
{
    struct CLLnode *temp = new CLLnode;
    temp->next = temp;                                  // next pointer points to itself
    temp->data = info;

    if( *head == NULL )                                    // if list is empty, no element 
    {
        *head = temp;
        if(flag == 1)
            flag = 0;
    }

    else
    {
        struct CLLnode *last = *head;
        
        while( last->next != *head )
            last = last->next;

        temp->next = *head;
        last->next = temp;
        if(flag == 1)
        {
            *head = temp;
            flag = 0;
        }
    }
}





void display(struct CLLnode *head)
{
    struct CLLnode *temp = head;

    if(head == NULL)                                   // no element 
        cout<<"empty CLL"<<endl;

    else
    {
        cout<<"CLL: "<<endl;
        do
        {
            cout<<temp->data<<" ";
            temp = temp->next;

        }while(temp != head);
    }
    cout<<endl;
    
}




//driver program
int main()
{
    struct CLLnode *head = NULL;
    int n,data;
    cout<<"nodes: ";
    cin>>n;

    for( int i = 0; i<n; i++)
    {
        cout<<"data ";
        cin>>data;
        insert_at_end( &head, data );
    }

    display(head);
}