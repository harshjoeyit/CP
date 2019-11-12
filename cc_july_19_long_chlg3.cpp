#include<bits/stdc++.h>
using namespace std;

struct CLLnode 
{
    string data;
    struct CLLnode *next;
};

// inserting in the circular linked list
void insert( struct CLLnode **head, string d )
{
    struct CLLnode *temp = new CLLnode;
    temp->next = temp;                                  
    temp->data = d;

    if( *head == NULL )                                     
        *head = temp;
    else
    {
        struct CLLnode *last = *head;
        while( last->next != *head )
            last = last->next;

        temp->next = *head;
        last->next = temp;
    }
}

// adding and returning two strings 
string addStrings( string &s1 , string &s2 )
{
    stack< char,string > S1(s1);        // creating stack and initializing with the string 
    stack< char,string > S2(s2);        // creating stack

    string add = "";                // the add string initialized to be empty 
    int carry=0, val;

    while( !S1.empty() || !S2.empty() )     // iteraton continue until each of the stack becomes empty 
    {
        val = 0;                            //variable for cureent sum of values at each index 
        if( !S1.empty() )
        {
            val += static_cast<int>(S1.top()) - '0';        // converting to int adding to value
            S1.pop();
        }
        if( !S2.empty() )
        {
            val += static_cast<int>(S2.top()) - '0';            // converting to int and adding to val
            S2.pop();
        }

        val += carry;               // adding the carry from previous sum

        if( val - 9 > 0 )           // we use the carry if value of sum > 10
        {
            carry = 1;
            add += ( static_cast<char>( val - 10 ) + '0' );     // addding the value converted to ASCII to the present string 
        }
        else
        {
            carry = 0;
            add += ( static_cast<char>( val ) + '0' );          // if there is no carry 
        }
    }
    if( carry == 1)                         // at the end when all the stacks are empty 
                                            // and stilll thew carry exist we add "1" to the number 
    add.insert( add.size() , "1" );         //inserting at last 
    reverse( add.begin() , add.end() );      // present string is reversed of the actual value 
    
    return add;
}


// driver program
int main()
{
    int T;
    cin>>T;

    while( T-- )
    {
        int N;
        long long int Ai;
        cin>>N;

        struct CLLnode *head = NULL;

        while( N-- )                    // make circular linked list 
        {
            cin>>Ai;                    // for space seperated input 
            insert( &head , to_string(Ai) );
        }


        struct CLLnode *temp ,*q;
        string score = "" , aplusb;
        string::size_type size_min , size_apb;
        
        while( head->next != head )     // continue until there is a single element in the linked list
        {
            string min = "999999999999999999999";
            temp = head;
            do
            {
                aplusb = addStrings( temp->data , temp->next->data );
                size_min = min.size();
                size_apb = aplusb.size();

                if( ((size_apb == size_min)&&(aplusb < min)) || (size_apb < size_min) )     /// comparing min and aplusb for values 
                {
                    min = aplusb;
                    q = temp;
                }
                
                temp = temp->next;
            }while( temp != head );

            temp = q->next;                         // node to be deleted 
            q->data = addStrings( q->data , temp->data );
            q->next = temp->next;  
            
            score = addStrings( score , q->data );                    // adding to the score 
            delete temp;                               // deallocating the memory
            head = q;

        }
        cout<<score<<endl;
        delete head;
    }
}

/*
#include<bits/stdc++.h>
using namespace std;

struct CLLnode 
{
    unsigned long long int data ;
    struct CLLnode *next;
};

// inserting in the circular linked list
void insert( struct CLLnode **head, unsigned long long int  d )
{
    struct CLLnode *temp = new CLLnode;
    temp->next = temp;                                  
    temp->data = d;

    if( *head == NULL )                                     
        *head = temp;
    else
    {
        struct CLLnode *last = *head;
        while( last->next != *head )
            last = last->next;

        temp->next = *head;
        last->next = temp;
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
    
}


// driver program
int main()
{
    int T;
    cin>>T;

    while( T-- )
    {
        int N;
        unsigned long long int Ai;
        cin>>N;

        struct CLLnode *head = NULL;

        while( N-- )                    // make circular linked list 
        {
            cin>>Ai;                    // for space seperated input 
            insert( &head , Ai );
        }
        display(head);

        struct CLLnode *temp ,*q;
        unsigned long long int score = 0 , aplusb;
        
        while( head->next != head )     // continue until there is a single element in the linked list
        {
            unsigned long long int min = INT_MAX;
            temp = head;
            do
            {
                aplusb = temp->data + temp->next->data;

                if( aplusb < min )     /// comparing min and aplusb for values 
                {
                    min = aplusb;
                    q = temp;
                }
                
                temp = temp->next;
            }while( temp != head );

            cout<<"min: "<<q->data<<endl;

            temp = q->next;                         // node to be deleted 

            cout<<"removed: "<<temp->data;

            q->data = q->data + temp->data;
            q->next = temp->next;  
            
            score = score  + q->data;                    // adding to the score 
            delete temp;                               // deallocating the memory
            head = q;
            
            display(head);
            cout<<"score: "<<score<<endl;

        }
        cout<<score<<endl;
        delete head;
    }
}
 */