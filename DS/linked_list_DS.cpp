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



void delete_node(struct node **head,int pos)    
{
    if(*head == NULL)
    {
        cout<<"empty list"<<endl;
        return;
    }

    struct node *temp = *head;

    if(pos == 1)                             // deleting head node
    {
        *head = (*head)->link;               // (*head)->link is NULL, so *head is assingned NULL
        free(temp);
        cout<<"deleted"<<endl;
        return;
    }

    int n = 0;                           // n= number of elements in the list
    struct node *temp2;

    while(temp != NULL)
    {
        ++n;
        temp = temp->link;
    }
    temp = *head;

    if( pos == n)                                   // deleting the last element
    {
        temp2 = temp->link;                       // temp2 is on the link to be deleted
        while(temp2->link != NULL)               // temp is on the second last element
        {
            temp2 = temp2->link;
            temp = temp->link;
        }

        temp->link = NULL;
        free(temp2);
        cout<<"deleted"<<endl;
        return;
    }

    else if( pos < n)
    {
        pos = pos-2;
        while(pos--)
            temp = temp->link;

        temp2 = temp->link;
        temp->link = temp2->link;
        free(temp2);
        cout<<"deleted"<<endl;
        return;
    }

    else if( pos > n)
        cout<<"deletion not possible"<<endl;
    return;

}


void delete_list(struct node **head)
{
    struct node *temp;
    while( *head != NULL)
    {
        temp = *head;
        *head = (*head)->link;
        free(temp);
    }
    cout<<"deleted"<<endl;
}



void nth_from_the_end( struct node **head , int n )       // time complexity = O(n^2)
{
    struct node *temp, *temp2;
    temp = *head;
    int count;

    do
    {
        temp2 = temp->link;
        count = 0;
        while(temp2 != NULL)
        {
            ++count;
            temp2 = temp2->link;
        }

    }while( count > (n-1) && (temp = temp->link) );

    cout<<"1. value: "<<temp->data<<endl;
}




void nth_from_the_end2( struct node **head , int n )       // time complexity = O(n) + O(n) ~ O(n)
{
    struct node *temp = *head;
    int count = 0;

    while(temp != NULL)
    {
        ++count;
        temp = temp->link;
    }

    if(n > count)
        cout<<"2. list has only "<<count<<" elements "<<endl;
    else
    {
        temp = *head;
        int M = count -n + 1;
        while(--M)
            temp = temp->link;

        cout<<"2. value: "<<temp->data<<endl;
    }
    
}




void nth_from_the_end4( struct node **head , int n )       // time complexity = O(n) , pointer approach 
{
    struct node *temp, *temp2;                             // finally temp2 points to NULL and temp point to required element 
    temp = *head;                                          // temp2 is n ahead of temp
    temp2 = *head;

    while(n--)
    {
        if(temp2 != NULL)
            temp2 = temp2->link;
    }

    while(temp2 != NULL)
    {
        temp = temp->link;
        temp2 = temp2->link;
    }
    
    if(temp)
        cout<<"4. value: "<<temp->data<<endl;
    else
        cout<<"3. not possible "<<endl;
}




vector<int> heads;                                                  // stores the node's data
vector<struct node*> node_address;                                  // stores the address of the node

void nth_from_the_end_hashing( struct node **head , int n )         // time complexity = O(n) , one time traversal approach 
{
    struct node *temp = *head;
    int i;

    for( i= 0; temp != NULL; i++)                                   // insertion
    {
        heads.push_back(temp->data);
        node_address.push_back(temp);
        temp = temp->link;
    } 
    
    if(n<=i)
        cout<<"5. value: "<<heads[i-n]<<" "<<(node_address[i-n])->data;
    else
        cout<<"5. list has only "<<i<<" elements"<<endl;

    heads.clear();                                                   // each time vector is cleared
}



bool check_circular( struct node *head)  // check error cannot return the coreect pointer where h == t
{
    struct node *h = head;
    struct node *t = head;

    while( t && h && (h->link) )
    {
        t = t->link;
        h = h->link->link;

        if( h == t )
            return 1;
    }
    return 0;
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





void menu()
{
    cout<<endl<<"0. exit"<<endl;
    cout<<"1. add node"<<endl;
    cout<<"2. delete node"<<endl;
    cout<<"3. delete_list"<<endl;
    cout<<"4. nth element from the end"<<endl;
    cout<<"5. check if list has a loop"<<endl;
    cout<<"6. show list"<<endl<<endl;
}




// driver program 

int main()
{
    int choice,info,pos;
    struct node *head = NULL;

    cout<<endl<<"linked list "<<endl;

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
                    if(head != NULL)                        // if head == NULL , then this is the first node , no need of position
                    {
                        cout<<"pos: ";
                        cin>>pos;
                    }
                    insert_node(&head,info,pos);
            break;
            
            case 2: cout<<"pos: ";
                    cin>>pos;
                    delete_node(&head,pos);
            break;

            case 3: delete_list(&head);
            break;

            case 4: cout<<"n: ";
                    cin>>pos;
                    nth_from_the_end( &head , pos ); 
                    nth_from_the_end2( &head , pos );
                    nth_from_the_end4( &head , pos );
                     nth_from_the_end_hashing( &head , pos );

            break;

            case 5: if(check_circular(head))
                        cout<<"has a loop "<<endl;
                    else
                        cout<<"no loop"<<endl;
                    
            break;

            case 6: display(head);
            break;

            default: cout<<"wrong choice"<<endl;
        }
        menu();
        cout<<"enter choice: ";
        cin>>choice;
    } 
}