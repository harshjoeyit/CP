#include<bits/stdc++.h>
using namespace std;



struct DLLnode
{
    int data;
    struct DLLnode *next;
    struct DLLnode *prev;
};




void insert_node(struct DLLnode **head, int info, int pos)
{
    struct DLLnode *temp = new DLLnode;
    temp-> data = info;

    if(pos == 1)
    {
        (*head)->prev = temp;
        temp->next = *head;
        temp->prev = NULL;
        (*head) = temp;

        cout<<"added "<<endl;
        return;
    }

    int n=0; 
    struct DLLnode *ptr ,*last;
    ptr = *head;

    while(ptr != NULL)
    {
        ++n;
        last = ptr;
        ptr = ptr->next;
    }

    if(pos == n+1)
    {
        last->next = temp;
        temp->prev = last;
        temp->next = NULL;

        cout<<"added "<<endl;
        return;
    }

    else if(pos < n+1)
    {
        struct DLLnode *temp2 = *head,*temp3;

        pos = pos-2;
        while(pos--)
            temp2 = temp2->next;
        
        temp3 = temp2->next;

        temp->next = temp3;
        temp->prev = temp2;
        temp3->prev = temp2->next = temp;

        cout<<"added "<<endl;
        return;
        
    }

    else if(pos > n+1 )
    {
        cout<<"not possible"<<endl;
        return;
    }

}




void delete_node(struct DLLnode **head , int pos)
{
    if(*head == NULL)
    {
        cout<<"empty list"<<endl;
        return;
    }

    struct DLLnode *temp = *head;

    if(pos == 1)
    {
        *head = (*head)->next;
        if (*head != NULL) 
            (*head)->prev = NULL;  // if head == NULL then this is useless
        free(temp);

        cout<<"deleted"<<endl;
        return;
    }

    int n=0;
    struct DLLnode *temp2;
    struct DLLnode *temp3;

    while(temp != NULL)
    {
        ++n;
        temp = temp->next;
    }
    temp = *head;

    if( pos == n)
    {
        temp2 = temp->next;
        while(temp2->next != NULL)
        {
            temp2 = temp2->next;
            temp = temp->next;
        }

        temp->next = NULL;
        free(temp2);
        cout<<"deleted"<<endl;
        return;
    }

    else if( pos < n )
    {
        pos = pos-2;
        while(pos--)
            temp = temp->next;

        temp2 = temp->next;
        temp3 = temp2->next;

        temp->next = temp3;
        temp3->prev = temp;
        free(temp2);

        cout<<"deleted"<<endl;
        return;
    }

    else if( pos > n)
        cout<<"deletion not possible"<<endl;
    return;


}




void delete_list(struct DLLnode **head)
{
    while( *head != NULL)
    {
        struct DLLnode *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    cout<<"deleted"<<endl;
}




void display(struct DLLnode *head)
{
    struct DLLnode *temp = head;

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




void menu()
{
    cout<<endl<<"0. exit"<<endl;
    cout<<"1. add node"<<endl;
    cout<<"2. delete node"<<endl;
    cout<<"3. delete_list"<<endl;
    cout<<"4. show list"<<endl<<endl;
}





// driver program
int main()
{
    int choice,info,pos;

    cout<<endl<<"create linked list "<<endl;
    cout<<endl<<"data: ";

    struct DLLnode *head = new DLLnode;
    cin>>(head->data);
    head->next = NULL;
    head->prev = NULL;

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
                    cout<<"pos: ";
                    cin>>pos;
                    insert_node(&head,info,pos);
            break;
            
            case 2: cout<<"pos: ";
                    cin>>pos;
                    delete_node(&head,pos);
            break;

            case 3: delete_list(&head);
            break;

            case 4: display(head);
            break;

            default: cout<<"wrong choice"<<endl;
        }
        cout<<"enter choice: ";
        cin>>choice;
    } 
}