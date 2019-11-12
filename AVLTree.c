#include<stdio.h>
#include<stdlib.h>


struct AVLTreeNode
{
    int data;
    int height;
    struct AVLTreeNode *left;
    struct AVLTreeNode *right;
};

typedef struct AVLTreeNode AVLNode;

struct node 
{
    AVLNode *AvlNode;
    struct node *next;
};

struct Queue
{
    struct node *front , *rear;
};




int maxOf(int a, int b)
{
    return ((a>b) ? a: b);
}

int Height(AVLNode *root)
{
    if(!root)
        return 0;
    
    return maxOf(Height(root->left), Height(root->right)) + 1;
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

void en_queue(struct Queue *Q ,AVLNode *address )
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if(!new_node)   
    {
        printf("memory erorr\n");
        return ;
    }
        
    new_node->next = NULL;
    new_node->AvlNode = address;

    if(Q->rear)
        Q->rear->next = new_node;
        
    Q->rear = new_node;
    
    if(Q->front == NULL )
        Q->front = Q->rear;
}

AVLNode* de_queue(struct Queue *Q )
{
    struct node *temp;
    AVLNode *address;
    if( is_empty_queue(Q) )
    {
        printf("Queue is Empty !");
        return 0;
    }

    else
    {
        temp = Q->front;
        address = Q->front->AvlNode;
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

void displayLOT(AVLNode *root )
{
    if( !root )
        return;

    AVLNode *temp;
    struct Queue *Q = create_queue();
    en_queue(Q,root);
    en_queue(Q, NULL);

    while( !is_empty_queue(Q))
    {
        temp = de_queue(Q);
        if(temp == NULL)
        {
            printf("\n");
            if(!is_empty_queue(Q))
                en_queue(Q, NULL);
        }
        else
        {
            printf("%d ",temp->data);
            if(temp->left)
                en_queue(Q,(temp->left));
            if(temp->right)
                en_queue(Q,(temp->right));
        }
    }
    delete_queue(Q);
}


AVLNode* LLRotation(AVLNode* X)
{
    AVLNode* W = X->left;
    X->left = W->right;
    W->right = X;

    X->height = maxOf(Height(X->left), Height(X->right)) + 1;
    W->height = maxOf(X->height, Height(W->left)) + 1;

    return W;
}

AVLNode* RRRotation(AVLNode* W)
{
    AVLNode* X = W->right;
    W->right = X->left;
    X->left = W;

    W->height = maxOf(Height(W->left), Height(W->right)) + 1;
    X->height = maxOf(W->height, Height(X->left)) + 1;

    return X;
}

AVLNode* LRRotation(AVLNode *Z)
{
    Z->left = RRRotation(Z->left);
    return LLRotation(Z);
}

AVLNode* RLRotation(AVLNode *X)
{
    X->right = LLRotation(X->right);
    return RRRotation(X);
}

AVLNode* insertNode(AVLNode *root, int data)
{
    if(!root)
    {
        root = (AVLNode *)malloc(sizeof(AVLNode));
        if(!root)
            printf("Memory Error\n");
        else
        {
            root->data = data;
            root->height = 0;
            root->left = root->right = NULL;
        }
    }

    else if(data < root->data)
    {
        root->left = insertNode(root->left, data);
        if(Height(root->left) - Height(root->right) == 2)
        {
            if(data < root->left->data)
                root = LLRotation(root);
            else
                root = LRRotation(root);
        }
    }

    else if(data > root->data)
    {
        root->right = insertNode(root->right, data);
        if(Height(root->right) - Height(root->left) == 2)
        {
            if(data > root->right->data)
                root = RRRotation(root);
            else
                root = RLRotation(root);
        }
    }   

    root->height = maxOf(Height(root->left), Height(root->right)) + 1;
    return root;
}


// construct an AVL tree with minimum node for a given height h
AVLNode* AVLTreeMinNodes(int h)
{
    static int count = 0;
    AVLNode* newNode = (AVLNode* )malloc(sizeof(AVLNode));
    newNode->height = h;

    if(h <= 0)          // for h = 0 and h = -1 
        return NULL;
    else
    {
        newNode->left = AVLTreeMinNodes(h-1);
        newNode->data = ++count;
        newNode->right = AVLTreeMinNodes(h-2);
    }

    return newNode;
}


void menu()
{
    printf("\n0. Exit\n");
    printf("1. Insert\n");
    printf("2. Display\n");
    printf("3. Min node AVL tree of height h\n");
}

int main()
{
    AVLNode* root = NULL, *Root;
    int choice, data, h;

    menu();
    printf("choice: ");
    while(scanf("%d", &choice))
    {
        switch(choice)
        {
            case 0: exit(1);
            break;

            case 1: printf("data: ");
                    scanf("%d", &data);
                    root = insertNode(root, data);
            break;

            case 2: displayLOT(root);
            break;

            case 3: printf("height: ");
                    scanf("%d", &h);
                    Root = AVLTreeMinNodes(h);
                    displayLOT(Root);
            break;

            default: printf("wrong choice!!\n");
        }

        menu();
        printf("choice: ");
    }
}   
