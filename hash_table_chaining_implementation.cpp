#include<bits/stdc++.h>
using namespace std;


struct node 
{
    int roll;
    int key;
    struct node *next;
};

vector<struct node*> heads;

int hash_key(int x)
{
    return (x%10);
}


void insert( int key , int roll )
{
    struct node *temp = new node;
    temp->roll = roll;
    temp->next = NULL;
    temp->key = key;

    if(heads[key] == NULL )
        heads[key] = temp;

    else
    {
        struct node *ptr = heads[key];
        while( ptr->next != NULL )
            ptr = ptr->next;
        
        ptr->next = temp;
    }  
}


bool search( int key , int search_roll)
{
    struct node *temp = heads[key];

    while( temp != NULL)
    {
        if(temp->roll == search_roll)
            return 1; 

        temp = temp->next;
    }
    return 0;
}


void display()
{
    cout<<endl;
    struct node *temp;
    for(int i=0; i<8; i++)
    {
        temp = heads[i];
        cout<<i<<"=> ";
        while(temp != NULL )
        {
            cout<<" "<<(temp->roll)<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}


int main()
{
    int roll;

    for( int i =0; i<8; i++)
    {
        cin>>roll;
        insert( hash_key(roll) ,roll);
    }


     display();

     int search_roll;

    cout<<"search_roll: ";
    while( cin>>search_roll )
    {
        int key = hash_key(search_roll);
        bool b = search(key,search_roll);

        if(b)
            cout<<"present"<<endl;
        else
            cout<<"not present "<<endl;
        
        cout<<"search_roll: ";
    }
    
}