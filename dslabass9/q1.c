#include<stdio.h>
#include<stdlib.h>

struct binarySearchTreeNode
{
    int data;
    struct binarySearchTreeNode *left;
    struct binarySearchTreeNode *right;
};

struct node 
{
    int data;
    struct node *next;
};

typedef struct binarySearchTreeNode BSTNode;
typedef struct node Node;



//insertion in a BST- not duplicate elements 
BSTNode* insertNode(BSTNode *root, int data)
{
    if(root == NULL)
    {
        BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
        newNode->left = newNode->right = NULL;
        newNode->data = data;
        return newNode;
    }
        
    else if(data > root->data)
        root->right = insertNode(root->right, data);
    
    else
        root->left = insertNode(root->left, data);

    return root;
}


// deletetion in BST
BSTNode* deleteNode(BSTNode *root, int data)
{
    BSTNode *temp;

    if(!root)               // element not found 
    {
        printf("not present\n");
        return root;
    }
    
    else if(data > root->data)
        root->right = deleteNode(root->right, data);
    else if(data < root->data) 
        root->left = deleteNode(root->left, data);
    
    else
    {   
        // data = root->data
         // two child 
        if(root->left && root->right)
        {   
            BSTNode* maxlefTree;
            // temp is preorder predecessor
            maxlefTree = root->left;
            while(maxlefTree->right != NULL)
                maxlefTree = maxlefTree->right;

            root->data = maxlefTree->data;
            root->left = deleteNode(root->left, root->data);
        }
         // one child
        else
        {
            if(root->left == NULL)
                temp = root->right;

            if(root->right == NULL)
                temp = root->left;
                
            free(root);
            // leaf node satisfy both th eabove conditions so temp becomes NULL
            return temp;
        }
        
    }
    return root;
}

// dispaly Preorder 
void display_Preorder( BSTNode *root )
{
    if(root)
    {
        printf("%d  ",root->data);
        display_Preorder( root->left );
        display_Preorder( root->right );
    }
}

// dispaly Preorder 
void display_Inorder( BSTNode *root )
{
    if(root)
    {
        display_Inorder( root->left );
        printf("%d  ",root->data);
        display_Inorder( root->right );
    }
}

// postorder 
void display_Postorder( BSTNode* root )
{
    if( root )
    {
        display_Postorder( root->left );
        display_Postorder( root->right );
        printf("%d  ",root->data);
    }
}


void menu()
{
    printf("\n0. Exit\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Preorder\n");
    printf("4. Preorder\n");
    printf("5. Preorder\n\n");
}




int main()
{
    int choice, data;
    BSTNode *root = NULL;

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

            case 2: printf("data: ");
                    scanf("%d", &data);
                    root = deleteNode(root, data);
            break;

            case 3: display_Preorder(root);
            break;

            case 4: display_Inorder(root);
            break;

            case 5: display_Postorder(root);
            break;

            default: printf("wrong choice!!\n");
        }

        menu();
        printf("choice: ");
    }
}


