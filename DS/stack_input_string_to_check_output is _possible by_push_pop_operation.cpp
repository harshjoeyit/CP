#include <iostream> 
#include <sstream> 
using namespace std; 
  

struct node
{
    int data;
    struct node *next;
};

struct node* create_stack()
{
    return NULL;
}

int is_empty_stack( struct node **S )
{
    return( *S == NULL );                         // returns 1 if true , else returns 0
}

void Push( struct node **S , int data )
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;

    temp->next = *S;                                                // since S is intialized to be NULL , there is no need to make exception for head and other nodes
    *S = temp;                                                    // all the nodes get stacked over one another
}

int Pop( struct node **S )
{
    if( is_empty_stack(S) ) 
        return -1;
    
    else
    {
        struct node *temp = *S;
        *S = (*S)->next;
        int pop_val = temp->data;
        free(temp);
        return pop_val;
    }
}




int num( char ch )
{
    return ( ch - '0');
}

char ch( int num)
{
    return ( num + '0');
}


// problem
// input : 246531 (a)
// array:  123456 (b)
// now we can take values form array and push into stack (any amount of values)
// let pushed be 2 1 (2 is top)
// then we can pop any no. of values from stack let 2 pops
// we store popped values in result[size]
// we repeat until array elements are finished 

// algorithm prints the closest possible result to input
// if input is a possible answer 
// then result and input are same  

int main()
{
    string s;
    cout<<"enter string: ";
    cin>>s;

    int size = s.length();
    int a[size] , b[size] , start , result[size];

    for( int i=0; i<size; i++)          // string string in int array
    {
         a[i] = num(s[i]);
         b[i] = i+1;
    }
    
    struct node *S = create_stack();   // stack for push & pop

    for( int i = 0 , j = 0 , k =0 ; i<size; )      // i for a , j for b 
    {
        int count = 1;
        // push the stack until a[i] is the top element 
        while( (j <= size) && (b[j] <= a[i]) )
        {
            Push( &S , b[j] );
            ++j;
        }

        while( (i<size) && (a[i] > a[i+1]) )
        {
            ++count;
            ++i;
        }
        ++i;

        for( int x = 0; x < count; x++,k++ )
        {
            result[k] = Pop( &S );
        }
    }

    for( int i = 0; i<size; i++)
    {
        cout<<"result[i]: "<<result[i]<<", a[i]: "<<a[i]<<endl;
    }
}