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




// or otherwise if we write complete function , then
// IMP : only change (in insert_at_end function ) is that *head = temp in the else part , rest is same.
void insert_at_beg(struct CLLnode **head, int info)
{
    flag = 1;
    insert_at_end(head,info);
}




void delete_at_end(struct CLLnode **head)           
{
    if(*head == NULL)                                 // no element
        cout<<"empty CLL , can't delete "<<endl;
    
    else if( (*head)->next == *head )                 // only one element 
    {
        free(*head);
        *head = NULL;
        cout<<"deleted"<<endl;
    }

    else
    {
        struct CLLnode *temp2, *temp = *head;

        temp2 = temp->next;                       // temp2 is on the last node
        while(temp2->next != *head)               // temp is on the second last node
        {
            temp2 = temp2->next;
            temp = temp->next;
        }

        temp->next = *head;
        free(temp2);
        cout<<"deleted"<<endl;
    }
}





void delete_at_begin(struct CLLnode **head)           
{
    if(*head == NULL)                                 // no element
        cout<<"empty CLL , can't delete "<<endl;
    
    else if( (*head)->next == *head )                 // only one element 
    {
        free(*head);
        *head = NULL;
        cout<<"deleted"<<endl;
    }

    else
    {
        struct CLLnode *temp2, *temp = *head;

        temp2 = temp->next;                       // temp2 is on the head node(it is deleted)
        while(temp2 != *head)                     // temp is on the last node
        {
            temp2 = temp2->next;
            temp = temp->next;
        }

        (*head) = (*head)->next;                 // new head is next node
        temp->next = *head;                      // temp (last) points to new head
        free(temp2);                             // temp is (previous head) deleted 
        cout<<"deleted"<<endl;
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
            cout<<temp->data<<endl;
            temp = temp->next;

        }while(temp != head);
    }
    
}


// to delete whole cicular list 
//convert it into a singly linked list 
// temp = head->next
// head->next = NULL;
// now run a loop untill temp becomes NULL
// the whole list is deleted

void menu()
{
    cout<<endl<<"0. exit"<<endl;
    cout<<"1. add node at the end"<<endl;
    cout<<"2. add node at the beginning"<<endl;
    cout<<"3. delete at the end "<<endl;
    cout<<"4. delete at the beginning"<<endl;
    cout<<"5. show list"<<endl<<endl;
}



//driver program

int main()
{
    int choice,info;
    struct CLLnode *head = NULL;

    cout<<endl<<"create CLL "<<endl<<"add a node "<<endl;

    menu();

    cout<<"enter choice: ";
    cin>>choice;
    while(choice != 0)
    {
        switch(choice)
        {
            case 0: exit(1);
            break;

            case 1: cout<<"data: ";
                    cin>>info;
                    insert_at_end(&head,info);
            break;

            case 2: cout<<"data: ";
                    cin>>info;
                    insert_at_beg(&head,info);
            break;

            case 3: delete_at_end(&head);
            break;

            case 4: delete_at_begin(&head);
            break;

            case 5: display(head);
            break;

            default: cout<<"wrong choice"<<endl;
        }
        menu();
        cout<<"enter choice: ";
        cin>>choice;
    }
}