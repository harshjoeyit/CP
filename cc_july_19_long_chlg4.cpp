#include<bits/stdc++.h>
using namespace std;

struct soldier
{
    int swordPower;
    struct soldier *next;
};


int main()
{
    ios_base::sync_with_stdio(false);

    int T;
    cin>>T;
    struct soldier *head;

    while(T--)
    {
        head = NULL;
        struct soldier *temp;
        int N , flag = 1;
        cin>>N;

        // insertion of N-1 soldiers in circular linked list
        for( int i = 0; i < N-1; i++ )
        { 
            temp = new soldier;
            temp->next = temp;                                  
            cin>>temp->swordPower;

            if( head == NULL )                                   
                head = temp;
            else
            {
                struct soldier *last = head;
                while( last->next != head )
                    last = last->next;

                temp->next = head;
                last->next = temp;
            }
        }

        int firepower;
        cin>>firepower;

        struct soldier *josh = new soldier;
        josh->swordPower = 0;               // initializing sword power = 0 , we use this to calculate his Defence power , the defense power needed to survive
        josh->next = josh;  
        
        // finding the correct spot for Josh to be inserted in the linked list circle
        int pos = 1;
        head = temp;        // starting from 1 before the original head , temp points to the last node added 
        do
        {
            if( temp->next->swordPower <= firepower )
            {
                flag = 0;
                break;
            }
            temp = temp->next;
            ++pos;
        }while(temp != head);

        if( flag == 1)                  // if none soldier has sword Power < fire power ,then regardless of where we put josh , he will die 
        {
            cout<<"impossible"<<endl;
            continue;
        }//else possible                               // when loop breaks , temp is previous of the element with sword power <= firepower 
        

        josh->next = temp->next;                // inserting josh in the circle 
        temp->next = josh;
        head = head->next;          // reposiitoning head at the original position

        struct soldier *sword , *killed , *prev;                        // prev - previous of killed person
        sword = killed = prev = head;                                   // all start from head 

        while( josh->next->next != josh )       // elminating the all soldiers except josh and his next soldier
        {
            if( prev == josh )
                prev = prev->next;            // josh does not use sword      

            killed = prev->next;                                        // killed is next to prev
            sword = killed->next;                                       // the next alive person gets the sword , 1 person alive after the killed person , even if he had the sword previously

            if( killed == josh )                // if josh is attacked he defenses , increment swordpower to calculate - defense required 
                josh->swordPower += prev->swordPower;
            else
            {
                prev->next = prev->next->next;
                delete killed;
            }
            prev = sword;                                                // start next iteration form the next person to the killed person
        }
        // only two soldiers including josh remain
        josh->swordPower += firepower;                      // josh needs more defense power just equal to firepower -
        cout<<"possible"<<endl;
        cout<<pos<<" "<<josh->swordPower<<endl;

    }
}