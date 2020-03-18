// cloning a linked list that has
// data
// next pointer
// a random pointer


/*
given list Y
new list X


struct node
{
    int data;
    struct node *next, *random;
}


struct hash
{
    int data;
    struct node *address;
}



void clone_list( struct node *head1)
{



hash a[100];
struct node *temp , *temp2 , *head2 ;

if( head1 != NULL )
{
    head2 = new node;
    head2 ->data = head1->data;
    head2->next = NULL;
    hash.data = head1->data;
    hash.address = head1;
}
else
{
    cout<<"list is empty cloning not possible"<<endl;
    return ;
}

temp = head->next;
temp2 = head2;



loop 1 
-scanning the list Y 
-copying data to list x node by node
-setting the next pointer 
- making the has table 
-key is data , value - address of each node 

while( temp != NULL )
{
    struct *NEW = new node;
    NEW->data = temp->data;
    NEW->next = NULL;
    NEW->random = NULL;
    temp2->next = NEW;
    temp2 = NEW;

    hash.data = temp->data;
    hash.address = temp;
}


loop2 for 
- directiing the random pointers from hash table

temp2 = head;
temp = head;

while( temp2 != NULL &&  temp != NULL )
{
    int data = temp->random->data;              // data gets the data value to which the random pointer is pointing to 
    temp2->random = a[ data ].address;          // from hash table we get address coressponding to that data then, assign that address to tep->random
}






}
*/