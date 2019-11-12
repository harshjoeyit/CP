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


// BST to DLL
BSTNode *BSTToDLL(BSTNode *root, BSTNode *head)
{
    if(root == NULL)
        return head;

    static BSTNode *prev = NULL;

    head = BSTToDLL(root->left, head);

    if(prev == NULL)
        head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    
    head = BSTToDLL(root->right, head);
    
    return head;
}


BSTNode* midNode(BSTNode *head)
{
    BSTNode *fastptr , *slowptr;
    fastptr = slowptr = head;

    while( (fastptr->right != NULL) && ( fastptr->right->right != NULL ))
    {
        slowptr = slowptr->right;
        fastptr = fastptr->right->right;
    }
    return slowptr;
}


// DLL to BST(check)
BSTNode *DLLToBST(BSTNode *head)
{
    BSTNode *temp, *p, *q;
    
    if(!head || !head->right)
        return head;
    
    temp = midNode(head);
    
    p = head;
    while(p->right != temp)
        p = p->right;
    p->right = NULL;
    
    q = temp->right;
    temp->right = NULL;

    temp->left = DLLToBST(head);
    temp->right = DLLToBST(q);
    return temp;
}


BSTNode *arrayToBST(int a[], int l, int h)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));

    if(l > h)
    {
        free(newNode);
        return NULL;
    }
    
    else if(l == h)
    {
        newNode->data = a[l];
        newNode->left = newNode->right = NULL;
    }

    else
    {
        int mid = l + (h-l)/2;
        newNode->data = a[mid];
        newNode->left = arrayToBST(a, l, mid-1);
        newNode->right = arrayToBST(a, mid+1, h);
    }

    return newNode;
}


Node* insert_node(Node *head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL)
        return newNode;
    else
    {
        Node *temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    return head;
}



BSTNode* LLToBST(Node *&head, int l, int h)         //**& needed for head as head is chenged in the recursion and we are not returnning head anywhere so 
{                                                   // alternative for **head 
                                                    // just like int *&head = basically head, which is what we call the function with 
    if(l > h)
        return NULL;
    int mid = l + (h-l)/2;

    // bottom to top approach     
    // first the child nodes are created then the parent node is created completely 
    BSTNode *leftchild = LLToBST(head, l, mid-1);       // left
    BSTNode *parent = (BSTNode *)malloc(sizeof(BSTNode));   
    parent->data = head->data;
    parent->left = leftchild;
    head = head->next;                                  // head is moved forward
    parent->right = LLToBST(head, mid+1, h);            // right
    return parent;                                      // return parent
}


// display  DLL
void dispDLL(BSTNode *head)
{
    if(head == NULL)
    {
        printf("Empty\n");
        return;
    }

    printf("list: ");
    while(head != NULL)
    {
        printf(" %d", head->data);
        head = head->right;
    }
    printf("\n");
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


void display_Postorder( BSTNode* root )
{
    if( root )
    {
        display_Postorder( root->left );
        display_Postorder( root->right );
        printf("%d  ",root->data);
    }
}


int nextGreaterOrEqual(BSTNode *root, int N) 
{
    return -1; 
}

int prevSmallerOrEqual(BSTNode *root, int N) 
{
    return -1; 
}


void freeNodes(BSTNode *root)
{
    if(root)
    {
        freeNodes(root->left);
        freeNodes(root->right);
        free(root);
    }
}

//trimmed in range n , m
BSTNode* PruneBST(BSTNode *root, int m, int n)
{
    // free the left and right neglected tree as memory leak
    if(!root)
        return NULL;

    root->left = PruneBST(root->left, m, n);
    root->right = PruneBST(root->right, m, n);

    if(m <= root->data && root->data <= n)
        return root;
    else if(root->data < m)
    {
        freeNodes(root->left);
        return root->right;
    }
    else if(root->data > n)
    {
        freeNodes(root->right);
        return root->left;
    }
    
    return NULL;
}

void menu()
{
    printf("\n1. Insert\n");
    printf("2. Display preorder\n");
    printf("3. Delete\n");
    printf("4. BST to DLL\n");
    printf("5. DLL to BST\n");
    printf("6. Array to BST\n");
    printf("7. LL to BST\n");
    printf("8. Next Greater or equal to\n");
    printf("9. Prune BST\n");
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

            case 2: display_Preorder(root);
            break;

            case 3: printf("data: ");
                    scanf("%d", &data);
                    root = deleteNode(root, data);
            break;

            case 4: BSTNode *head;
                    head = BSTToDLL(root, head);
                    dispDLL(head);
            break;    

            case 5: root = DLLToBST(head);
            break;

            case 6:
            {
                int a[] = {1,3,5,8,10,11,24};
                int l = 0, h = sizeof(a)/sizeof(int)-1;
                BSTNode *newRoot = arrayToBST(a, l, h);
                display_Preorder(newRoot);
            }
            break;

            case 7:
            {
                int n, data;
                printf("n: ");
                scanf("%d", &n);
                Node *head = NULL;

                for(int i=0; i<n; i++)
                {
                    printf("data: ");
                    scanf("%d", &data);
                    head = insert_node(head,data);
                }

                BSTNode *newRoot = LLToBST(head, 0, n-1);
                display_Preorder(newRoot);
            }
            break;

            case 8: int n;
                    printf("data: ");
                    scanf("%d", &data);
                    printf("%d\n",nextGreaterOrEqual(root, data));
            break;

            case 9: printf("range: ");
                    scanf("%d%d",&data ,&n);
                    root = PruneBST(root, data, n);
            break;

            default: printf("wrong choice!!\n");
        }

        menu();
        printf("choice: ");
    }
}


