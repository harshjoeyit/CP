#include<bits/stdc++.h>
using namespace std;

#define MAXSIZE 20

struct array_stack
{
    int top;
    int capacity;
    int *array;
};


struct array_stack *create_stack()
{
    struct array_stack *S = new array_stack;
    if( !S )
        return NULL;
    S->capacity = MAXSIZE;
    S->top = -1;
    S->array =  new int[S->capacity * sizeof(int)];         // S->array is a pointer to int array
    if( !S )
        return NULL;
    return S;
}



int is_empty_stack( struct array_stack *S )
{
    return( S->top == -1 );                         // returns 1 if true , else returns 0
}



int is_full_stack(struct array_stack *S )
{
    return (S->top == S->capacity -1 );                // returns 1 if true , else return 0
}



void Push( struct array_stack *S , int data )
{
    // S->top == S->capacity- 1 indicates that the stack is full
    if( is_full_stack (S) )
        cout<<"Stack Overflow "<<endl;
    else
    {
        S->array[++S->top] = data;
        cout<<"push success"<<endl;
    }
}


int Pop( struct array_stack *S )
{
    // S->top == -1 
    if( is_empty_stack(S) ) 
    {
        cout<<"empty stack "<<endl;
        return INT_MIN;
    }
    else
    return(S->array[S->top--]);
}


void delete_stack( struct array_stack *S)
{
    if(S)
    {
        if(S->array)
            free(S->array);
        free (S);
    }
}



void display_stack(struct array_stack *S)
{
    if(S)
    {   
        cout<<"stack: "<<endl;
        if(S->top == -1 )
            cout<<"empty"<<endl;
        else
        {
            for(int i = S->top; i>= 0; i--) // dislay from the top
                cout<<S->array[i]<<" ";
        }
    }
}




void menu()
{
    cout<<endl<<"1. Push "<<endl;
    cout<<"2. Pop "<<endl;
    cout<<"3. Is Empty "<<endl;
    cout<<"4. Is Full "<<endl;
    cout<<"5. Delete stack "<<endl;
    cout<<"6. Display "<<endl;
    cout<<"7. Exit "<<endl;
}



// driver function
int main()
{
    struct array_stack *S = create_stack();

    int  data , choice ;
   
    menu();

    cout<<"choice: ";
    while( cin>>choice )
    {     
        switch(choice)
        {
            case 1: cout<<"data: ";
                    cin>>data;
                    Push(S,data);
            break;

            case 2: cout<<"pop: "<<Pop(S);
            break;

            case 3: if(!is_empty_stack)
                        cout<<"empty stack"<<endl;
                    else
                        cout<<"not empty stack"<<endl;
            break;
            
            case 4: if(!is_full_stack)
                        cout<<"full stack"<<endl;
                    else
                        cout<<"vacant stack"<<endl;
            break;

            case 5: delete_stack(S);
            break;

            case 6: display_stack(S);
            break;

            case 7: exit(1);
            break;

            default: cout<<"wrong choice" <<endl;
        }
        menu();
        cout<<"choice: ";
    } 
}