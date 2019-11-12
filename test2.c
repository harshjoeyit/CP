#include<stdio.h>
#include<stdlib.h>

struct listNode 
{
    int vertex;
    struct listNode *next;
};

struct Graph
{
    int v, e;
    struct listNode **Adj;
};


struct Graph *addToList(struct Graph *G, int x, int y)
{
    struct listNode *newNode = (struct listNode *)malloc(sizeof(struct listNode));
    newNode->vertex = y;
    struct listNode *temp = G->Adj[x]->next;
    
    while(temp->next != G->Adj[x])
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
    
    return G;
}

struct Graph *adjListOfGraph()
{
    int i, x, y;
    struct listNode *temp;
    struct Graph *G = (struct Graph *)malloc(sizeof(struct Graph));
    if(!G)
    {
        printf("Memory Eroor\n");
        return NULL;
    }

    printf("Number of vertices, Number of Edges: ");
    scanf("%d%d",&x, &y);
    G->v = x;
    G->e = y;

    G->Adj = (struct listNode **)malloc(sizeof(struct listNode*) * G->v);

    for(i = 0; i < G->v; i++)
    {
        G->Adj[i] = (struct listNode *)malloc(sizeof(struct listNode));
        G->Adj[i]->vertex = i;
        G->Adj[i]->next = G->Adj[i];
    }

    for(int i = 0; i < G->e; i++)
    {
        printf("Reading Edge:");
        scanf("%d%d", &x, &y);

        G = addToList(G, x, y);
        G = addToList(G, y, x);
    }

    return G;
}

void display(struct Graph *G)
{
    int v = G->v;
    struct listNode* temp;

    for(int i = 0; i < v; i++)
    {
        temp = G->Adj[i]->next;
        while(temp != G->Adj[i])
        {
            printf("(%d,%d), ", i, temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}


int main()
{
    struct Graph *G = adjListOfGraph();
    display(G);
}