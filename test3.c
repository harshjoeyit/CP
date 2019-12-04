





#include<stdio.h>
#include<stdlib.h>

struct node 
{
    struct threadedBTNode *trNodeAdd;
    struct node *next;
};

struct Queue
{
    struct node *front , *rear;
};

struct threadedBTNode
{
    int data;
    struct threadedBTNode *left;
    struct threadedBTNode *right;
    int rightThread;
};


struct threadedBTNode* newNode(int data)  
{  
    struct threadedBTNode* Node = (struct threadedBTNode *)malloc(sizeof(struct threadedBTNode));
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
    Node->rightThread = 0;
  
    return(Node);  
} 

// create tree
struct threadedBTNode* create_tree()
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
void en_queue( struct Queue *Q , struct threadedBTNode *address )
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



//............................DEQUEUE...........................
struct threadedBTNode* de_queue( struct Queue *Q )
{
    struct node *temp;
    struct threadedBTNode *address;
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


void insert_into_binary_tree( struct threadedBTNode **root , int data )
{
    struct Queue *Q;
    struct threadedBTNode *temp;
    
    struct threadedBTNode *new_node = newNode(data);
    
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


void display_inorder(struct threadedBTNode* root)
{
    if(root)
    {
        display_inorder(root->left);
        printf("%d ",root->data);
        display_inorder(root->right);
    }
}


struct threadedBTNode* rightmostLeft(struct threadedBTNode* root)
{
    if(!root->left)
        return NULL;
    
    struct threadedBTNode* temp = root->left;
    while(temp->right != NULL)
        temp = temp->right;
    
    return temp;
}


void setNullPtrs(struct threadedBTNode **root)
{
    if(*root)
    {
        setNullPtrs(&((*root)->left));
        setNullPtrs(&((*root)->right));
        struct threadedBTNode* temp = rightmostLeft((*root));
        if(temp != NULL)
        {
            temp->rightThread = 1;
            temp->right = *root;
        }
    }
}



// Utility function to find leftmost node in a tree rooted with n 
struct threadedBTNode* leftMost(struct threadedBTNode *n) 
{ 
    if (n == NULL) 
       return NULL; 
  
    while (n->left != NULL) 
        n = n->left; 
  
    return n; 
} 
  
// C code to do inorder traversal in a threaded binary tree 
void inOrder(struct threadedBTNode *root) 
{ 
    struct threadedBTNode *cur = leftMost(root); 
    while (cur != NULL) 
    { 
        printf("%d ", cur->data); 
  
        // If this node is a thread node, then go to 
        // inorder successor 
        if (cur->rightThread) 
            cur = cur->right; 
        else // Else go to the leftmost child in right subtree 
            cur = leftMost(cur->right); 
    } 
}

    
void menu()
{
    printf("\n\n0. Exit \n");
    printf("1. Insert \n");
    printf("2. inorder\n");
    printf("3. make threaded\n");
    printf("4. inorder threaded\n");
    printf("\n");
}





// driver function
int main()
{
    printf("\nBinary Tree\n");
    int choice, data,a,b;
    struct threadedBTNode *root = create_tree();
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

            case 2: printf("preorder: ");
                    display_inorder(root);
            break;
            
            case 3: setNullPtrs(&root);
            break;
            
            case 4: inOrder(root);
            break;


            default: printf("Wrong Choice\n");
        }
        menu();
        printf("choice: ");
    } 
}
