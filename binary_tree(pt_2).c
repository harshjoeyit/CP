#include<stdio.h>
#include<stdlib.h>

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
            printf("on root->left\n");
            return;
        }

        if(temp->right)
            en_queue(Q,(temp->right));
        else
        {
            temp->right = new_node;
            delete_queue(Q);
            printf("on root->right\n");
            return;
        }
    }
    delete_queue(Q);
}



// level order traversal
void display_LOT( struct binaryTreeNode *root )
{
    printf("LEVEL ORDER TRANSVERSAL\n Tree: ");
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


// level with the maximum sum
int maxSumLevel(struct binaryTreeNode *root )
{
    if( !root )
        return -1;

    struct binaryTreeNode *temp;
    struct Queue *Q = create_queue();

    int curSum = -1, maxSum = -1, lev = 1, maxSumlev = -1;
    en_queue(Q,root);
    en_queue(Q, NULL);

    while( !is_empty_queue(Q))
    {
        temp = de_queue(Q);
        if(temp == NULL)
        {
            if(curSum > maxSum)
            {
                maxSumlev = lev;
                maxSum = curSum;
            }
            ++lev;
            curSum = 0;

            if(!is_empty_queue(Q))
                en_queue(Q, NULL);
        }
        else
        {
            curSum += temp->data;
            if(temp->left)
                en_queue(Q,(temp->left));
            if(temp->right)
                en_queue(Q,(temp->right));
        }
    }
    delete_queue(Q);
    return maxSumlev;
}

void printPath(int *path, int pathlen)
{
    for(int i = 0; i <= pathlen; i++)
        printf("%d ", path[i]);
    printf("\n");
}

// root to leaf paths 
void rootToLeafPaths(struct binaryTreeNode *root, int *path, int pathlen)
{
    if(root == NULL)
        return;
    
    path[pathlen] = root->data;

    if(root->left == NULL && root->right == NULL)
        printPath(path, pathlen);
    
    else
    {
        rootToLeafPaths(root->left, path, pathlen + 1);
        rootToLeafPaths(root->right, path, pathlen + 1);
    }   
}


// given sum path possible or not
int givenSumPath(struct binaryTreeNode *root, int sum)
{
    if(root == NULL)
        return 0;
    
    int remsum = sum - root->data;

    if(remsum == 0)
        return 1;
    else if(remsum < 0)
        return 0;
    else
        return (givenSumPath(root->left, remsum) || givenSumPath(root->right, remsum));  
}


int index_in_inorder(char inorder[], int n, char c)
{
    for(int i = 0; i < n; i++)
        if(inorder[i] == c)
            return i;
    return 0;
}

struct binaryTreeNode* constructTree(char *preorder, char *inorder, int n, int s, int e)
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
    newnode->left = constructTree(preorder, inorder, n, s, i-1);
    newnode->right = constructTree(preorder, inorder, n, i+1, e);
    newnode->data = c;
    
    return newnode;
}


int main()
{
    struct binaryTreeNode *root = create_tree();
    // int data;
    // int n;
    // printf("Elements: ");
    // scanf("%d", &n);

    // for(int i = 0; i < n; i++)
    // {
    //     scanf("%d", &data);
    //     insert_into_binary_tree(&root, data);
    // }
    // // 1.
    // display_LOT(root);
    // // 2.
    // printf("max sum level: %d\n", maxSumLevel(root) );
    // //3. 
    // int a[n] = {};
    // rootToLeafPaths(root, a, 0);

    // //4.
    // int sum = 1;
    // printf("possible : %d\n", givenSumPath(root, sum));

    char preorder[] = {'A', 'B', 'D', 'E', 'F', 'C', 'G', 'H', 'J', 'L', 'K'};
    char inorder[] =  {'D', 'B', 'F', 'E', 'A', 'G', 'C', 'L', 'J', 'H', 'K'};
    int n = sizeof(preorder)/sizeof(char);
    root = constructTree(preorder, inorder, n, 0, n-1);

    display_LOT(root);
}