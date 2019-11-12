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

struct binaryTreeNode
{
    int data;
    struct binaryTreeNode *left;
    struct binaryTreeNode *right;
};



struct binaryTreeNode* newNode(int data)  
{  
    struct binaryTreeNode* Node = (struct binaryTreeNode *)malloc(sizeof(struct binaryTreeNode));
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
  
    return(Node);  
} 

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



int countNodes( struct binaryTreeNode *root )
{
    if(root == NULL )
        return 0;
    else 
        return ( countNodes( root->left) +  1 + countNodes(root->right) );      
}


int height( struct binaryTreeNode *root )
{
    if(root == NULL )
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return ( 1 + ((leftHeight > rightHeight ) ? leftHeight : rightHeight) ); 
}

int leafNodes(struct binaryTreeNode *root)
{       
    if(!root)
        return 0;
    
    if(root->left == NULL && root->right == NULL)
        return 1;    

    return leafNodes(root->right) + leafNodes(root->left);
}   

int strictTree(struct binaryTreeNode *root)
{
    if(!root->right && !root->left)
        return 1;

    if( (!root->left && root->right) || (root->left && !root->right) )
        return 0;
    
    return strictTree(root->left) && strictTree(root->right);
}


int equalTrees(struct binaryTreeNode *a, struct binaryTreeNode *b)
{
    if (a == NULL && b == NULL)  
        return 1;  

    if (a != NULL && b != NULL)  
    {  
        return ( a->data == b->data && equalTrees(a->left, b->left) && equalTrees(a->right, b->right) );  
    }  

    // if either subtree is empty
    return 0;
}

    
void menu()
{
    printf("\n\n0. Exit \n");
    printf("1. Insert \n");
    printf("2. preorder\n");
    printf("3. number of nodes\n");
    printf("4. number of leaf nodes\n");
    printf("5. height\n");
    printf("6. strict tree or not\n");
    printf("7. if two trees are equal\n");
    printf("\n");
}





// driver function
int main()
{
    printf("\nBinary Tree\n");
    int choice, data,a,b;
    struct binaryTreeNode *root = create_tree();
    struct binaryTreeNode *root2 = create_tree();
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
                    display_Preorder(root);
            break;
            
            case 3: printf("node: %d\n", countNodes(root));
            break;
            
            case 4: printf("leaf nodes%d\n", leafNodes(root));
            break;

            case 5: printf("height: %d", height(root));
            break;

            case 6: if(strictTree(root))
                        printf("strict\n");
                    else
                        printf("not strict\n");
            break;

            case 7: root2 = newNode(10);
                    root2->left = newNode(20);  
                    root2->right = newNode(30);  
                    root2->left->left = newNode(40);  
                    root2->left->right = newNode(50); 
                    if(equalTrees(root, root2) )
                        printf("equal\n");
                    else
                        printf("unequl\n");
            break;

            default: printf("Wrong Choice\n");
        }
        menu();
        printf("choice: ");
    } 
}
