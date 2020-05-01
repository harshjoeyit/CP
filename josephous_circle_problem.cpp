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




struct CLLnode *josephus_circle1( struct CLLnode **head , int M)
{
    struct CLLnode *sword , *killed , *prev;                        // prev - previous of killed person
    sword = killed = prev = *head;                                  // all start from head 

    while( prev->next != prev )
    {
        for(int i = 3; i<= M; i++ )                                 // decided by , for 2 no shift, for 3 , 1 shift , for 4 , 2 shift 
        {
            prev = prev->next;              
        }

        killed = prev->next;                                        // killed is next to prev 
        if(killed == *head)
            *head = (*head)->next;                                  // head is saved
        
        sword = killed->next;                                       // the next alive person gets the sword , 1 person alive after the killed person , even if he had the sword previously
        
        prev->next = prev->next->next;                               // deleting the node
        prev = sword;                                                // start next iteration form the next person to the killed person
    }
    return *head;
}



void josephus_circle2()
{
    int N, M;
    struct CLLnode *p ,*q;
    cout<<"N: ";
    cin>>N;

    cout<<"M: ";
    cin>>M;

    // CLL

    p = q = new CLLnode;
    p->data = 1;
    for( int i= 2; i<=N; ++i)
    {
        p->next = new CLLnode;
        p = p->next;
        p->data = i;
    }
    // close list
    p->next = q;                                // here p is not the head , it is the previous of head , head is q
    for( int count = N; count>1; --count)
    {
        for(int i = 0; i<M-1; i++)              // p starts from prev of head 
            p = p->next;
        p->next = p->next->next;                // in next iteration , p continues from prev of person removed
    }
    cout<<"f winner2: "<<p->data;
}


// using a deque
int josephus(int n, int k)
{
    if(n==1)
        return 1;
        
    deque<int>dq;
    for(int i=1;i<=n;i++)
    {
        dq.push_back(i);
    }
    while(dq.size()>1)
    {
        for(int i=1;i<k;i++)
        {
            int f = dq.front();
            dq.pop_front();
            dq.push_back(f);
        }
        dq.pop_front();
    }
    return dq.front();
}


// using vector 
int josephus(int n, int k)
{
    vector <int> v;
    for(int i = 0;i<n;i++)
        v.push_back(i);
    
    if(v.size()==1)
        return 1;
    int kill = k-1;
    
    while(v.size()>1)
    {
        v.erase(v.begin()+kill);
        kill= (kill+k-1)%v.size();
    }
    return v[0] +1;
}


// O(n) solution 



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
    int n,data,M;
    cout<<"nodes: ";
    cin>>n;

    for( int i = 0; i<n; i++)
    {
        cout<<"data ";
        cin>>data;
        insert_at_end( &head, data );
    }

    display(head);

    struct CLLnode *winner1 , *winner2;
    cout<<"M: ";
    cin>>M;
    winner1 = josephus_circle1( &head, M );
    cout<<"winner 1: "<<winner1->data<<endl;

    josephus_circle2();
}