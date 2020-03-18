#include<stdio.h>
#include<stdlib.h>

struct node 
{
    struct binaryTreeNode *trNodeAdd;
    struct node *next;
};

struct Queue
{
    struct node *front , *rear;
};

struct Stack
{
    struct binaryTreeNode *trNodeAdd;
    struct Stack *next;
};

struct binaryTreeNode
{
    int data;
    struct binaryTreeNode *left;
    struct binaryTreeNode *right;
};



// create tree
struct binaryTreeNode* create_tree()
{
    return NULL;
}


// ...................CREATE QUEUE..............
struct Queue* create_queue()
{
    struct Queue *Q = (struct Queue*)malloc( sizeof(struct Queue) );
    if( !Q )
        return NULL;

    Q->front = Q->rear = NULL;
    return Q;
}


int is_empty_queue( struct Queue *Q )
{
    return(Q->front == NULL );
}



// ........................ENQUEUE..................
void en_queue( struct Queue *Q , struct binaryTreeNode *address )
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if(!new_node)   
    {
        printf("memory erorr\n");
        return ;
    }
        
    new_node->next = NULL;
    new_node->trNodeAdd = address;

    if(Q->rear)
        Q->rear->next = new_node;
        
    Q->rear = new_node;
    
    if(Q->front == NULL )
        Q->front = Q->rear;
}

// ..................create_stack.............
struct Stack* create_stack()
{
    return NULL;
}

//...............isemptystack..................
int is_empty_stack( struct Stack **S )
{
    return( *S == NULL );                         // returns 1 if true , else returns 0
}

//.....................Push .......................
void Push( struct Stack **S , struct binaryTreeNode *address )
{
    struct Stack *temp = (struct Stack *)malloc(sizeof(struct Stack));
    temp->trNodeAdd = address;

    temp->next = *S;                                                // since S is intialized to be NULL , there is no need to make exception for head and other Stacks
    *S = temp;                                                     // all the Stacks get stacked over one another
}

//................................Push ............................
struct binaryTreeNode* Pop( struct Stack **S )
{
    struct binaryTreeNode *address ;
    if( is_empty_stack(S) ) 
        printf("empty stack \n");
    
    else
    {
        struct Stack *temp = *S;
        address = temp->trNodeAdd;
        *S = (*S)->next;
        free(temp);
    }
    return address;
}



//............................DEQUEUE...........................
struct binaryTreeNode* de_queue( struct Queue *Q )
{
    struct node *temp;
    struct binaryTreeNode *address;
    if( is_empty_queue(Q) )
    {
        printf("Queue is Empty !");
        return 0;
    }

    else
    {
        temp = Q->front;
        address = Q->front->trNodeAdd;
        Q->front = Q->front->next;
        free(temp);

        if(Q->front == NULL )
            Q->rear = Q->front;
    }
    return address;
}


//................DELETE QUEUE..............................
void delete_queue( struct Queue *Q )
{
    struct node *temp;

    while( !is_empty_queue(Q) )
    {
        temp = Q->front;
        Q->front = Q->front->next;
        free(temp);
    }  
    free(Q);
}



// insert into treee
void insert_into_binary_tree( struct binaryTreeNode **root , int data )
{
    struct Queue *Q;
    struct binaryTreeNode *temp;
    
    struct binaryTreeNode *new_node = (struct binaryTreeNode *)malloc(sizeof(struct binaryTreeNode));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = data;
    if(!new_node)
        printf("memory error");
    
    if(*root == NULL )
    {
        printf("root created \n");
        *root = new_node;
        return;
    }

    Q = create_queue();
    en_queue(Q, *root);

    while( !is_empty_queue(Q) )
    {
        temp = de_queue(Q);

        if(temp->left)
            en_queue(Q,(temp->left));
        else
        {
            temp->left = new_node; 
            delete_queue(Q);
            printf("on root->left");
            return;
        }

        if(temp->right)
            en_queue(Q,(temp->right));
        else
        {
            temp->right = new_node;
            delete_queue(Q);
            printf("on root->right");
            return;
        }
    }
    delete_queue(Q);
}



// level order traversal
void display_LOT( struct binaryTreeNode **root )
{
    printf("LEVEL ORDER TRANSVERSAL\n Tree: ");
    struct binaryTreeNode *temp;
    struct Queue *Q = create_queue();

    if( ! *root )
    {
        printf("empty\n");
        return ;
    }

    en_queue(Q,*root);
    while( ! is_empty_queue(Q))
    {
        temp = de_queue(Q);
        printf("  %d",temp->data);
        if(temp->left)
            en_queue(Q,(temp->left));
        if(temp->right)
            en_queue(Q,(temp->right));
    }
    delete_queue(Q);
}


// ....... PREORDER............
void display_Preorder( struct binaryTreeNode *root )
{
    if( root )
    {
        printf("  %d",root->data);
        display_Preorder( root->left );
        display_Preorder( root->right );
    }
}

//........POSTORDER
void display_Postorder( struct binaryTreeNode *root )
{
    if( root )
    {
        display_Postorder( root->left );
        display_Postorder( root->right );
        printf("  %d",root->data);
    }
}


// INORDER...................
void display_Inorder( struct binaryTreeNode *root )
{
    if( root )
    {
        display_Inorder( root->left );
        printf("  %d",root->data);
        display_Inorder( root->right );
    }
}


// ..........................FIND MAX VALUE BY RECURSION ....................
int find_max( struct binaryTreeNode *root )
{
    if( root == NULL )
        return -__INT_MAX__;

    int rootVal = root->data;
    int leftVal = find_max( root->left );
    int rightVal = find_max( root->right );

    int max = ( leftVal > rightVal ) ? leftVal : rightVal;
    return ( (max > rootVal) ? max : rootVal );

}



//............search element........................
struct binaryTreeNode* searchInTree(  struct binaryTreeNode *root , int data )
{
    struct binaryTreeNode *temp;
    if (root == NULL )
        return NULL;
    else
    {
        if( root->data == data )
        return root;

        temp = searchInTree(root->left, data );
        if( temp )
            return temp; 
        else
            return ( searchInTree(root->right, data )); 
    }
    return NULL;
}


//........SIZE OF THE TREE.......
int size_of_tree( struct binaryTreeNode *root )
{
    if(root == NULL )
        return 0;
    else 
        return ( size_of_tree( root->left) +  1 + size_of_tree(root->right) );      
}



// .............HEIGHT OF TREE ..................
int height_of_tree( struct binaryTreeNode *root )
{
    if(root == NULL )
        return 0;

    int leftHeight = height_of_tree(root->left);
    int rightHeight = height_of_tree(root->right);

    return ( 1 + ((leftHeight > rightHeight ) ? leftHeight : rightHeight) ); 
}


// * important
struct binaryTreeNode * deepest_node( struct binaryTreeNode *root )
{
    struct binaryTreeNode *temp;
    struct Queue *Q = create_queue();

    if(!root )
        return NULL;

    en_queue(Q,root);
    while( !is_empty_queue(Q) )
    {
        temp = de_queue(Q);
        if(temp->left)
            en_queue(Q,temp->left);
        if(temp->right)
            en_queue(Q,temp->right);
    }
    delete_queue(Q);
    return temp;
}



void delete_node( struct binaryTreeNode *root , int data )
{
    struct binaryTreeNode *temp , *delNode;
    int flag = 0;
    struct Queue *Q = create_queue();

    if(!root )
        return;

    en_queue(Q,root);
    while( !is_empty_queue(Q) )
    {
        temp = de_queue(Q);

        if( temp->data == data )
         {
            delNode = temp;
            flag = 1;
         }

        if(temp->left)
            en_queue(Q,temp->left);
        if(temp->right)
            en_queue(Q,temp->right);
    }

    if(flag)
    {
        delNode->data = temp->data;
        free(temp);     // the pointer pointing to this node has some defalut value : Not = NULL , so the display functions malfunction
    }                   // IMP ^^^^^^^^^
    delete_queue(Q);
}



// .............NOT sure about algo , not testted properly
// logic , 1. visit every node , LEVEL ORDER TRAVERSAL
        // 2. for each node , consited it root of a tree and find maximum left_max_height - on the left sub tree , and find right_max_height - on the right sub tree
        // adding left_max_height and right_max_height + 1 (the current root ) gets the longest path available from leaf to leaf , for each node
        // filter : if root->left or root->right is NULL , means that the tree has no leaves on that side , so leaf to leaf path cannot be formed  
        
int find_width( struct binaryTreeNode *root )
{
    int left_max_depth, right_max_depth , max = 0, width ;

    struct binaryTreeNode *temp;
    struct Queue *Q = create_queue();

    if(!root )
        return 0;

    en_queue(Q,root);
    while( !is_empty_queue(Q) )
    {
        left_max_depth = right_max_depth = 0;
        temp = de_queue(Q);

        if(temp->left)
        {
            en_queue(Q,temp->left);
            left_max_depth = height_of_tree(temp->left);
        }

        if(temp->right)
        {
            en_queue(Q,temp->right);
            right_max_depth = height_of_tree(temp->right);
        }

        width = right_max_depth + 1 + left_max_depth ;
        if(width >= 3 )
        {
            if( width > max)
                max = width ;
        }
    }
    return max;
}



void make_mirror( struct binaryTreeNode *root )
{
    if(root == NULL)
    return;

    else
    {
        struct binaryTreeNode *temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    make_mirror( root->left );
    make_mirror( root->right );
}



//..........................LCA..................
struct binaryTreeNode * LCA( struct binaryTreeNode *root , struct binaryTreeNode *A , struct binaryTreeNode *B)
{
    struct binaryTreeNode *left , *right;
    if( root == NULL )
        return root;
    if(root == A || root == B )
        return root;
    left = LCA(root->left, A , B);
    right = LCA(root->right , A , B);

    if(left && right )                  // means that both recursions obtained some value that is one of them is found on left sub tree and the other on the right , so return root
        return root;
    else
        return ( left ? left : right );  // if only one of  the recursions return not a NULL ptr , other returns NULL ptr
}



// better code than book,same approach...................ancestors........................
int print_all_ancestors( struct binaryTreeNode *root , struct binaryTreeNode *search_node )
{
    if(root)        // either the element is equal to the node , or it is equal to one of the children of the current root 
    {
        if( (root == search_node)  ||  print_all_ancestors(root->left , search_node)  ||  print_all_ancestors(root->right , search_node ) )
        {
            printf("\t%d",root->data );      
            return 1;
        }
    }
    return 0;
}





void display_ZIGZAG( struct binaryTreeNode **root )
{
    // according to book , flag = lefttoright , S1 - currentlevel , S2 - nextlevel
    struct Stack *S1 = create_stack();
    struct Stack *S2 = create_stack();
    struct binaryTreeNode *temp;
    int flag = 0;                           // flag = 0 - S2 is empty , flag = 1 - S1 is empty 
                                            //            push - S2   ,             Push - S1
    if( *root )                             //            pop - S1    ,             Pop - S2
    {
        Push( &S1 , *root );
        while( !is_empty_stack(&S1) ||  !is_empty_stack(&S2) )
        {
            if( is_empty_stack(&S1) )
                flag = 1;
            if( is_empty_stack(&S2) )
                flag = 0;

            if( flag == 0)                  // S2 is empty
            {
                temp = Pop(&S1);
                printf("\t%d",temp->data );
                if( temp->left )            // push left first , conventionally
                    Push( &S2 , temp->left );         
                if( temp->right )
                    Push( &S2 , temp->right );
            }

            else                             // S1 is empty
            {
                temp = Pop(&S2);
                printf("\t%d",temp->data );
                if( temp->right )           // push right first , for the sake of sequence
                    Push( &S1 , temp->right );       
                if( temp->left )
                    Push( &S1 , temp->left );
            }
        }
    }

}



int if_sum_path_possible( struct binaryTreeNode *root , int sum )
{
    if( root == NULL )
        return 0;

    sum = sum - root->data ;
    if( sum == 0)
        return 1;
    
    return (  (if_sum_path_possible(root->left , sum ) == 1 ) ||  (if_sum_path_possible(root->right , sum ) == 1) );
}                                                 // == 1                                         == 1




void menu()
{
    printf("\n\n0. EXIT \n");
    printf("1. INPUT \n");
    printf("2. DISPLAY LOT\n");
    printf("3. DISPLAY PREORDER\n");
    printf("4. DISPLAY POSTORDER\n");
    printf("5. DISPLAY INORDER\n");
    printf("6. FIND MAXIMUM\n");
    printf("7. SEARCH ELEMENT \n");
    printf("8. SIZE OF TREE \n");
    printf("9. HEIGHT OF TREE \n");
    printf("10. DEEPEST NODE IN TREE\n");
    printf("11. DELETE NODE\n");
    printf("12. WIDTH OF THE TREE \n"); 
    printf("13. MIRROR TREE\n");
    printf("14. LAC\n");
    printf("15. PRINT ALL THE ANCESTORS OF A NODE\n");
    printf("16. ZIG-ZAG TEAVERSAL\n");
    printf("17. IF GIVEN SUM PATH IS POSSIBLE \n");
    printf("\n");
}





// driver function
int main()
{
    printf("\nBinary Tree\n");
    int choice, data,a,b;
    struct binaryTreeNode *root = create_tree();
    menu();

    printf("choice :");
    while( scanf("%d",&choice) )
    {     
        switch(choice)
        {
            case 0: exit(1);
            break;

            case 1: printf("data: ");
                    scanf("%d",&data);
                    insert_into_binary_tree(&root,data);
            break;

            case 2: display_LOT(&root);
            break;

            case 3: display_Preorder(root);
            break;
            
            case 4: display_Postorder(root);
            break;
            
            case 5: display_Inorder(root);
            break;

            case 6: printf("max-> %d",find_max(root));
            break;

            case 7: printf("data: ");
                    scanf("%d",&data);
                    if( searchInTree(root, data) ) 
                        printf("found\n");
                    else
                        printf("not found");
                    
            break;

            case 8: printf("size of tree :%d\n", size_of_tree(root) );
            break;

            case 9: printf("height of tree : %d\n", height_of_tree(root) );
            break;

            case 10: printf("deepest node : %d\n", (deepest_node(root))->data);
            break;

            case 11: printf("data: ");
                    scanf("%d",&data);
                    delete_node(root,data);
            break;

            case 12: printf("width of tree: %d\n", find_width(root) );
            break;

            case 13: make_mirror( root );
            break;

            case 14: printf("node1: ");
                    scanf("%d",&a);
                    printf("node2: ");
                    scanf("%d",&b);

                    data = LCA( root , searchInTree(root ,a) , searchInTree(root , b) )->data;
                    printf("LAC : %d",data);
    	    break;

            case 15: printf("node: ");
                    scanf("%d",&a);
                    printf("ancestors: ");
                    data = print_all_ancestors(root , searchInTree(root , a));
                    if( data == 0 )
                        printf("element does not exist in the tree \n");
    	    break;
            
            case 16: display_ZIGZAG(&root);
            break;

            case 17: printf("data: ");
                     scanf("%d",&data);
                     if( if_sum_path_possible(root, data ) )
                        printf("possible\n");
                    else
                        printf("not possible \n");
            break;

            default: printf("wrong choice \n");
        }
        menu();
        printf("choice: ");
    } 
}
