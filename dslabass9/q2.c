#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node 
{
    struct binaryTreeNode *BTNode;
    struct node *next;
};

struct Queue
{
    struct node *front , *rear;
};

struct binaryTreeNode
{
    int data;
    struct binaryTreeNode *left;
    struct binaryTreeNode *right;
};


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
    new_node->BTNode = address;

    if(Q->rear)
        Q->rear->next = new_node;
        
    Q->rear = new_node;
    
    if(Q->front == NULL )
        Q->front = Q->rear;
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
        address = Q->front->BTNode;
        Q->front = Q->front->next;
        free(temp);

        if(Q->front == NULL )
            Q->rear = Q->front;
    }
    return address;
}


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


int index_in_inorder(char inorder[], int n, char c)
{
    for(int i = 0; i < n; i++)
        if(inorder[i] == c)
            return i;
    return 0;
}

struct binaryTreeNode* constructTreePreIn(char *preorder, char *inorder, int n, int s, int e)
{
    static int index = 0;
    struct binaryTreeNode *newnode = (struct binaryTreeNode*)malloc(sizeof(struct binaryTreeNode));

    if(s > e)           // important exception - occurs for one child nodes , right or left child is returned NULL
    {
        free(newnode);
        return NULL;
    }

    if(s == e)          // leaf nodes formed 
    {
        newnode->data = preorder[index++];
        newnode->left = newnode->right = NULL;
        return newnode;
    }
    
    // for other branch nodes

    char c = preorder[index++];
    int i = index_in_inorder(inorder, n, c);
    newnode->left = constructTreePreIn(preorder, inorder, n, s, i-1);
    newnode->right = constructTreePreIn(preorder, inorder, n, i+1, e);
    newnode->data = c;
    
    return newnode;
}


// for index in the postorder expression
int ind;
struct binaryTreeNode* constructTreePosIn(char *postorder, char *inorder, int n, int s, int e)
{
    struct binaryTreeNode *newnode = (struct binaryTreeNode*)malloc(sizeof(struct binaryTreeNode));

    if(s > e)           // important exception - occurs for one child nodes , right or left child is returned NULL
    {
        free(newnode);
        return NULL;
    }

    if(s == e)          // leaf nodes formed 
    {
        newnode->data = postorder[ind--];
        newnode->left = newnode->right = NULL;
        return newnode;
    }

    // for other branch nodes
    char c = postorder[ind--];
    int i = index_in_inorder(inorder, n, c);
    newnode->right = constructTreePosIn(postorder, inorder, n, i+1, e);
    newnode->left = constructTreePosIn(postorder, inorder, n, s, i-1);
    newnode->data = c;
    
    return newnode;
}


// level order traversal
void display_LOT( struct binaryTreeNode *root )
{
    printf("LEVEL ORDER: ");
    struct binaryTreeNode *temp;
    struct Queue *Q = create_queue();

    if( !root)
    {
        printf("empty\n");
        return ;
    }

    en_queue(Q,root);
    while( ! is_empty_queue(Q))
    {
        temp = de_queue(Q);
        printf("  %c",temp->data);
        if(temp->left)
            en_queue(Q,(temp->left));
        if(temp->right)
            en_queue(Q,(temp->right));
    }
    printf("\n");
    delete_queue(Q);
}


void menu()
{
    printf("\n0. Exit\n");
    printf("1. Construct by inorder and Postorder\n");
    printf("2. Construct By Inorder And Preorder\n\n");
}


int main()
{
    int choice, n;
    struct binaryTreeNode *root;
    char inorder[20], preorder[20], postorder[20]; 

    menu();
    printf("choice: ");
    while(scanf("%d", &choice))
    {
        switch(choice)
        {
            case 0: exit(1);
            break;
            
            case 1: printf("inorder: ");
                    scanf("%s", inorder);
                    printf("postorder: ");
                    scanf("%s", postorder);
                    n = strlen(inorder);
                    ind = n-1;
                    root = constructTreePosIn(postorder, inorder, n, 0, n-1);
                    display_LOT(root);
            break;
            case 2: printf("inorder: ");
                    scanf("%s", inorder);
                    printf("preorder: ");
                    scanf("%s", preorder);
                    n = strlen(inorder);
                    root = constructTreePreIn(preorder, inorder, n, 0, n-1);
                    display_LOT(root);
            break;

            default: printf("Invalid choice\n");
        }
        
        menu();
        printf("choice: ");
    }
}