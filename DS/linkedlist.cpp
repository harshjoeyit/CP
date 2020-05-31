#include<iostream>
using namespace std;

struct node
{
    int number;
    node *next;
};

// checking if the list is empty
bool isempty(node *head)
{
    if(head==NULL)
        return true;
    else
        return false;
}

//add first element
void  insertAsFirstElement(node *&head, node *&last, int number)
{
    node *temp= new node;
    temp->number = number;
    temp->next=NULL;

    head=temp;
    last=temp;

    cout<<"added"<<endl;
}

// adding other elements after the first elements are added
void insert1(node *&head, node *&last, int number)
{
    if(isempty(head))
        insertAsFirstElement(head,last,number);
    else
    {
        node *temp= new node;
        temp->number= number;
        temp->next=NULL;

        last->next=temp;
        last=temp;
    }

    cout<<"added"<<endl;
}

// adding a node at nth position
void addatn(node *&head, int addnum , int pos)
{
    if(pos == 1)
    {
        node *add = new node;  // creating new node 
        add->number = addnum;   // input
        add->next = head;     // linking to head as 1st element 
        head = add;          // head is changed to added node 
    }
    else // pos>1
    {
        node *add = new node;  // creating a node to be added 
        node *temp = head;    // temp node for pointing to n-1 position

        for(int i=1; i<pos-1; i++)
            temp = temp->next; // shifting temp to n-1 position

        add->number = addnum;      //value inputted
        add->next = temp->next;  // new node gets linked to next node
        temp->next = add;        // previous node gets linked to new node
    }

    cout<<"added\n";
}

// removes the node
void remove1(node *&head, node *&last)
{
    if(isempty(head))
        cout<<"can't remove , list is empty: "<<endl;
    else
    if(head==last)
    {
        delete head;
        head=NULL;
        last=NULL;
    }
    else
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
     cout<<"node removed! "<<endl;
}

void showlist(node *head)  // do not use the reference here since in the end head becomes NULL
{
    if(isempty(head))
        cout<<"empty"<<endl;
    else
    {
        node *temp = head;
        while(temp != NULL)
        {
            cout<<temp->number<<endl;
            temp = temp->next;
        }
    }
}

//reverse list ,if printed now it comes out to be backwards:

void reverse1(node *&head)
{
    node *p,*c,*n; //three pointers required
    p=NULL;       //previous     // draw diagram and position the pointers
    c=head;       //current
    n=c->next;    // next

    while(c! = NULL)
    {
        // pointing direction changed
        c->next=p;
        //shifting
        p=c;
        c=n;
        if(n!=NULL)  // if n reaches n NULL  the there is no element to move forward so this condition is required
        n=n->next;
    }
    head=p;
}

// deletes nth node
void delete1(int n,node *head, node *last)
{

        node *temp=head,*tempdel;
        for(int i=1; i<n-1; i++)// moves the temp to the n-1 th node
        temp= temp->next;
        tempdel=temp->next;
//IMP: copying the address of n-1 element into the n+ element
        temp->next= tempdel->next;
        delete tempdel;
        cout<<"successfully deleted."<<endl;


}

// finds and delete the node with the inputted value if present
void delete2(int delnum1, node *head, node *last)
{

    node *temp=head,*tempdel;
    int cnt=0;

    while(temp->number != delnum1)
    {
// a cnt variable is just used only because for locating the  NODE JUST BEFORE OUR REMOVABLR ELEMENT
        ++cnt;
        temp=temp->next;
    }
//changing back tem to the head for the functioning of the next loop
    temp=head;

    for(int i=1; i<cnt; i++)// moves the temp to the n-1 th node
    {
        temp= temp->next;
    }
    tempdel=temp->next;
//IMP: copying the address of n-1 element into the n+ element
    temp->next= tempdel->next;
    delete tempdel;

    cout<<"successfully deleted."<<endl;
}

void delete_node(int delnum, node *head , node *last)
{
    if(head == last )
        {
            delete head;
            head = NULL;
            last = NULL;
        }
    else
    {
        int count;
        node *tempdel = head,*temp = head;  // tempdel pointing to head
        while(tempdel->number != delnum)
        {
            ++count;
            tempdel = tempdel->next;  
        }                               // tempdel pointing to the node to be deleted 
        for(int i=0; i<count; i++)
        {
            temp = temp ->next;
        }// pointing to the node before the node to be delelted 

        temp->next = tempdel->next;
        delete tempdel;

    }
}

/* check if the function worls to delelte node
void delete_node2(int delnum, node *head, node* last)
{
    if(head == last )
    {
        delete head;
        head = NULL;
        last = NULL;
    }
    else
    {
        int flag = 1;
        node *temp = head;
        node *tempdel;

        while(flag == 1)
        {
            tempdel = temp ->next;
            if(tempdel->number == delnum)
                flag = 0;
            else
                temp = temp ->next;                          
        }
}*/

int menu()
{
    cout<<"MENU: "<<endl;
    cout<<"1. add a node "<<endl;  //done
    cout<<"2. remove an item from the top i.e. head "<<endl; // done
    cout<<"3. show the list."<<endl;  // done
    cout<<"4. remove node at position n"<<endl;
    cout<<"5. search the value,remove the node: "<<endl; 
    cout<<"6. add node at nth position: "<<endl;  // done
    cout<<"7. reverse the list: "<<endl;
    cout<<"8. system exit. "<<endl;  //done

    int choice;
    cin>>choice;
    return choice;
}


//...............MAIN.........................

main()
{
    node *head =NULL;
    node *last=NULL;

    int choice;

    do{   // only do-while is suitable here for our job

        choice = menu();
        switch(choice)
        {
            case 1: int number;
            cout<<"please enter the number: ";
            cin>>number;
            insert1(head,last,number);
            break;

            case 2:remove1(head, last);
            break;

            case 3: cout<<"list: "<<endl;
            showlist(head);
            break;

            case 4: int n;
            cout<<"enter n to delete nth node: ";
            cin>>n;
            delete1(n,head,last);
            break;

            case 5: int delnum;
            cout<<"input the number to delete the its node: ";
            cin>>delnum;
            delete2(delnum, head,last);
            break;

            case 6: int addnum,pos;
            cout<<"enter the number to be inputted: ";
            cin>>addnum;
            cout<<"enter the position: ";
            cin>>pos;
            addatn(head,addnum,pos);
            break;

            case 7: reverse1(head);
            cout<<"list reversed. "<<endl;
            break;

            case 8:cout<<"system exit: "<<endl;
            break;

            default: cout<<"invalid!"<<endl;
            break;
        }

    }while(choice!=8);  /*here u must use the semi colon important */

}

