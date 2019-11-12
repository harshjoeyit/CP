



 // error: cannot insert at position block_size+1 th position
 // works fine if all the elements are added at k=0




#include<stdio.h>
#include<string.h.>
#include<stdlib.h>
#include<math.h>
#include<time.h>


int block_size;                             //max number of nodes in the block


struct list_node
{
    struct list_node *next;
    int value;
};


struct linked_block
{
    struct linked_block *next;
    struct list_node *head;
    int node_count;
};



struct linked_block *block_head;                // auto initialized NULL and its components too are auto initialized 


//function to create an emty block, and return pointer to the new linked_block
struct linked_block *new_linked_block()
{
    struct linked_block *block = (struct linked_block *)malloc (sizeof(struct linked_block) );
    block->next = NULL;
    block->head = NULL;
    block->node_count = 0;
    return block;
}


//function to create list node , and return a pointer to that node;
struct list_node *new_list_node(int value)
{
    struct list_node *temp = (struct list_node *)malloc( sizeof(struct list_node) );
    temp->next = NULL;
    temp ->value = value;
    return temp;
}


// function to search element 
void search_element( int k , struct linked_block **flinked_block , struct list_node **flist_node )
{
    int j = ( k + block_size - 1)/block_size;                     // kth node is in jth block

    struct linked_block *p = block_head;
    while(--j)
        p = p->next;
    
    *flinked_block = p;

    //find node
    struct list_node *q = p->head;

    k = k % block_size;
    if(k==0)
        k=block_size;
    k = p->node_count + 1 - k;
    while(k--)
        q = q->next;
    
    *flist_node = q;
}


/// start shift opertion from block *p

void shift( struct linked_block *A )
{
    struct linked_block *B;
    struct list_node *temp;

    while( A->node_count > block_size )                     // if this block still have to be shift 
    {
        if( A->next == NULL )                               // if it is last block_node 
        {
            A->next = new_linked_block();                   // creating a new block node
            B = A->next;
            temp = A->head->next;
            A->head->next = A->head->next->next;
            B->head = temp;
            A->node_count--;
            B->node_count++;
        }

        else
        {
            B = A->next;
            temp = A->head->next;
            A->head->next = A->head->next->next;
            temp->next = B->head->next;
            B->head->next = temp;
            B->head = temp;
            A->node_count--;
            B->node_count++;
        }
        A = B;
    }
}



void add_element( int k, int x )           
{
    struct linked_block *r;
    struct list_node *p, *q;

    if( !block_head )                                           //block_head points to null - no blocks , so creste one and add element 
    {   
        block_head = new_linked_block();
        block_head->head = new_list_node(x);                       // we created a block , now add a list_node to block
        block_head->head->next = block_head->head;                 // pointing to itself , a circular linked list 
        block_head->node_count++;                                 // one node now 
    }

    else
    if(k == 0)                                                  // k - probably denotes the position to add the new node 
    {
        p = block_head->head;
        q = p->next;
                                                                    // whole process for adding the node at beginning      
        p->next = new_list_node(x);
        p->next->next = q;
        block_head->head = p->next;
        block_head->node_count++;
        shift(block_head);                                      // since there is extra node in here so shiftin operation
    }

    else
    {
        search_element( k, &r, &p);
        q = p;
        while( q->next != p)
            q = q->next;
        q->next = new_list_node(x);
        q->next->next = p;
        r->node_count++;
        shift(r);

    }
        
}
    


int Search_element( int k )                                                   // return s the value at the position
{
    struct linked_block *q;
    struct list_node *p;
    search_element(k, &q, &p );
    return( p->value );
}



double test_unrolled_list()
{
    double start = clock();
    int m, i, k, x;
    char cmd[10];
    
    scanf("%d",&m);
    block_size = (int)(sqrt(m-0.001)) +1;

    for( i =0; i<m; i++)
    {
        scanf("%s",cmd);

        if(strcmp( cmd, "add") == 0)
        {
            scanf("%d%d",&k,&x);
            add_element(k,x);
        }
        else if( strcmp(cmd,"search") == 0 )
        {
            scanf("%d",&k);
            printf("%dsearched element: \n",Search_element(k));
        }
        else
        {
            fprintf(stderr,"wrong input\n");
        }
    }
    double end = clock();
    double cpu_time_used = (end - start) / CLOCKS_PER_SEC;
    return cpu_time_used;
}




// display function
void display()
{
    printf("U_L_L : \n");

    if(block_head == NULL)
        printf("empty list");
    
    else
    {
        struct linked_block *p = block_head;

        while(p != NULL)
        {
            struct list_node *q = p->head;
            
            do
            {
                printf("%d ",q->value);
                q = q->next;

            } while (q != p->head);
            
            printf("\n");
            p = p->next;
        }
    }
    
}




void menu()
{
    printf("\n0. exit\n");
    printf("1. add element\n");
    printf("2. search element at position k\n");
    printf("3. test unrolled linked list \n");
    printf("4. display list\n");
}



// driver program
int main()
{
    printf("\nunrolled linked list\n\n");
    //input the block size
    printf("block_size: ");
    scanf("%d",&block_size);

    int choice , k, x ;

    menu();

    printf("\nchoice:");
    scanf("%d",&choice);

    while( choice != 0)
    {
        switch(choice)
        {
            case 0: exit(1);
            break;

            case 1: printf(" k: ");
                    scanf("%d",&k);
                    printf(" x: ");
                    scanf("%d",&x);
                    add_element( k , x );
            break;

            case 2: printf(" k: ");
                    scanf("%d",&k);
                    printf("element is = %d\n", Search_element(k) );
            break;

            case 3: printf("cpu_time_used = %lf", test_unrolled_list() );

            case 4: display();
            break;

            default: printf("wrong choice \n");

        }
        printf("\n");
        menu();
        printf("\nchoice:");
        scanf("%d",&choice);
    }

}