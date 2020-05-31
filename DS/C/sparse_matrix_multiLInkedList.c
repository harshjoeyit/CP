#include<stdio.h>
#include<stdlib.h>

struct mlnode
{
    int row,col,val;
    struct mlnode *nextcol,*nextrow;
};

typedef struct mlnode MLNODE;


MLNODE *Create()
{
    int r,c;
    printf("Enter no of row & column respectively.\n");
    scanf("%d",&r);
    scanf("%d",&c);
    MLNODE *rowptr, *colptr;

    MLNODE *head;
    head = (MLNODE *)malloc(sizeof(MLNODE));
    head->row = -1;
    head->col = -1;
    head->val = -100;

    rowptr = colptr = head;

    for(int i=0 ; i<r ; i++)
    {
        MLNODE* temp = (MLNODE *)malloc(sizeof(MLNODE));
        temp->row = i;
        temp->col = -1;
        temp->val = -10;
        temp->nextcol = temp;
        rowptr->nextrow = temp;
        rowptr = temp;
    }
    rowptr->nextrow = head;


    for(int i=0 ; i<c ; i++)
    {
        MLNODE* temp = (MLNODE *)malloc(sizeof(MLNODE));
        temp->col = i;
        temp->row = -1;
        temp->val = -20;
        temp->nextrow = temp;
        colptr->nextcol = temp;
        colptr = temp;
    }
    colptr->nextcol = head;

    return head;
}


MLNODE *above(MLNODE *head , int r , int c)
{
    MLNODE *q;
    MLNODE *p = head->nextcol;
    // c must be correct no check here

    while(p->col != c)
        p = p->nextcol;

    do
    {
        q = p;
        p = p->nextrow;
    }
    while(p->row != -1 && p->row < r);

    return q;
}


MLNODE *left(MLNODE *head , int r , int c)
{
    MLNODE *q , *p = head->nextrow;
    while(p->row != r)
        p = p->nextrow;
    
    do
    {
        q = p;
        p = p->nextcol;
    }
    while(p->col != -1 && p->col < c);

    return q;
}


MLNODE *insertAt(MLNODE *head , int r , int c , int v)
{
    MLNODE *newnode, *a, *l;
    newnode = (MLNODE *)malloc(sizeof(MLNODE));
    newnode->row = r;
    newnode->col = c;
    newnode->val = v;
    a = above(head , r , c);
    l = left(head , r ,c);

    // printf("above: %d, %d\n", a->row, a->col);
    // printf("left: %d, %d\n", l->row, l->col);
    
    newnode->nextrow = a->nextrow;
    newnode->nextcol = l->nextcol;
    l->nextcol = newnode;
    a->nextrow = newnode;

    // printf("insertion Done\n");
    return head;
}



MLNODE *delete_node(MLNODE *head , int r , int c)
{
    MLNODE *p, *q , *a , *l;
    a = above(head ,r , c);
    l = left(head ,r ,c);
    p = a->nextrow;
    q = l->nextcol;
    MLNODE *temp = head->nextrow;

    // condition not correct
    if(p == a || q == l)
    {
        printf("Such node does not exist\n");
        return head;
    }
    // while(temp != head)
    // {
    //     if(temp == q)
    //     {
    //         printf("node does not exist\n");
    //         return head;
    //     }
    //     temp = temp->nextrow;
    // }
    
    a->nextrow = q->nextrow;
    l->nextcol = q->nextcol;

    printf("%d is removed from row = %d & col = %d.\n",q->val,r,c);
    free(q);
    return head;
}


// workout the swap function 
MLNODE *swap(MLNODE *head , int ri , int rj)
{
    MLNODE *p , *q , *r = head->nextrow, *temp;

    while(r != head)
    {
        if(r->row == ri)
            p = r;
        if(r->row == rj)
            q = r;
        
        r = r->nextrow;
    }

    p = p->nextcol;
    q = q->nextcol;

    while(p != head && q != head)
    {

        if(q->col < p->col)
        {
            head = insertAt(head , ri , q->col , q->val);
            temp = q->nextcol;
            head = delete_node(head , rj , q->col);
            q = temp;
        }
        if(q->col > p->col)
        {
            head = insertAt(head , rj , p->col , p->val);
            temp = p->nextcol;
            head = delete_node(head , ri , p->col);
            p = temp;
        }

        if(q->col == p->col)
        {
            // swap values if both the cols are found
            int t;
            t = q->val;
            q->val = p->val;
            p->val = t;
        }
        
    }
    
    while(p != head)
    {
        head = insertAt(head , rj , p->col , p->val);
        temp = p->nextcol;
        head = delete_node(head , ri , p->col);
        p = temp;
    }

    while(q != head)
    {
        head = insertAt(head , ri , q->col , q->val);
        temp = q->nextcol;
        head = delete_node(head , rj , q->col); 
        q = temp;
    }

    return head;
}


void display(MLNODE *head)
{
    printf("\ndisplay: \nr c val\n");
    MLNODE *p,*q;
    p = head->nextrow;
    while(p != head)
    {
        q = p->nextcol;
        while(q != p)
        {
            printf("%d %d %d\n",q->row, q->col, q->val);
            q = q->nextcol;
        }
        p = p->nextrow;
    }
    printf("\n");
}




void menu()
{
    printf("\n1.Insrt an element.\n2.Delete_node an Element.\n3.Swap two Rows.\n4.Display.\n5. exit\n\n");
}





int main()
{
    
    MLNODE *head = Create();
    int r, c, v, choice;    
   
    menu();
    printf("Enter choice : ");

    while(scanf("%d",&choice))
    {
        switch(choice)
        {

            case 1:
                printf("Data : ");
                scanf("%d",&v);
                printf("Row : ");
                scanf("%d",&r);
                printf("Column : ");
                scanf("%d",&c);
                head = insertAt(head,r,c,v);
                break;

            case 2:
                printf("Row : ");
                scanf("%d",&r);
                printf("Column : ");
                scanf("%d",&c);
                head = delete_node(head,r,c);
                break;

            case 3:
                printf("Row 1 : ");
                scanf("%d",&r);
                printf("Row 2 : ");
                scanf("%d",&c);
                head = swap(head,r,c);
                break;

            case 4:
                display(head);
                break;

            case 5: exit(1);
                    break;  

            default :
                printf("Wrong choice .... Try again....\n");  
        }

        menu();
        printf("Enter choice : ");
    }
}