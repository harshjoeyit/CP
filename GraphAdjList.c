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

struct node 
{
    int data;
    struct node *next;
};


struct LinkedQueue
{
    struct node *front , *rear;
};

struct LinkedQueue* create_queue()
{
    struct LinkedQueue *Q = (struct LinkedQueue*)malloc( sizeof(struct LinkedQueue) );
    if( !Q )
        return NULL;

    Q->front = Q->rear = NULL;
    return Q;
}

int is_empty_queue( struct LinkedQueue *Q )
{
    return(Q->front == NULL );
}

int queue_size( struct LinkedQueue *Q )
{
    struct node *temp = Q->front;
    int count = 0;

    if(temp == NULL )
        return 0;
    
    while( temp != NULL )
    {
        ++count;
        temp = temp->next;
    }
    return count;
}

void en_queue( struct LinkedQueue *Q , int data )
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if(!new_node)   
    {
        printf("memory error\n");
        return ;
    }
        
    new_node->next = NULL;
    new_node->data = data;

    if(Q->rear)
        Q->rear->next = new_node;
        
        Q->rear = new_node;
    
    if(Q->front == NULL )
        Q->front = Q->rear;
}


int de_queue( struct LinkedQueue *Q )
{
    struct node *temp;
    int data = 0;
    if( is_empty_queue(Q) )
        return -1;

    else
    {
        temp = Q->front;
        data = Q->front->data;
        Q->front = Q->front->next;
        free(temp);
    }
    return data;
}

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


void DFS(struct Graph *G, int u, int visited[])
{
    visited[u] = 1;
    printf("%d ", u);

    struct listNode* temp = G->Adj[u]->next;
    while(temp != G->Adj[u])
    {
        if(visited[temp->vertex] == 0)
            DFS(G, temp->vertex, visited);
        temp = temp->next;
    }
}

void DFSTraversal(struct Graph *G)
{
    printf("DFS: ");
    int visited[G->v] = {};
    // loop required if the graph is disconnect
    for(int i = 0; i < G->v; i++)
        if(visited[i] == 0)
            DFS(G, i, visited);
}


void BFS(struct Graph *G, int u, int visited[])
{
    struct LinkedQueue *Q = create_queue();
    en_queue(Q, u);
    visited[u] = 1;

    while(!is_empty_queue(Q))
    {
        u = de_queue(Q);
        printf("%d ", u);;

        struct listNode* temp = G->Adj[u]->next;
        while(temp != G->Adj[u])
        {
            if(visited[temp->vertex] == 0)
            {
                en_queue(Q, temp->vertex);
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
}


void BFSTraversal(struct Graph *G)
{
    int visited[G->v] = {};

    printf("BFS: ");
    for(int i = 0; i < G->v; i++)
        if(visited[i] == 0)
            BFS(G, i, visited);
}


void shortestPath(struct Graph *G, int u)
{
    int visited[G->v] = {};
    int pathLength[G->v], U = u;

    for(int i = 0; i < G->v; i++)
        pathLength[i] = -1;

    struct LinkedQueue *Q = create_queue();
    en_queue(Q, u);
    visited[u] = 1;
    pathLength[u] = 0;

    while(!is_empty_queue(Q))
    {
        u = de_queue(Q);

        struct listNode* temp = G->Adj[u]->next;
        while(temp != G->Adj[u])
        {
            if(visited[temp->vertex] == 0)
            {
                en_queue(Q, temp->vertex);
                visited[temp->vertex] = 1;
                pathLength[temp->vertex] = pathLength[u] + 1;           // all the children of u have pathlength 1 form their parent 
            }
            temp = temp->next;
        }
    }

    printf("\n");
    for(int i = 0; i < G->v; i++)
        printf("pathlen of %d from %d = %d\n", i, U, pathLength[i]);
    
}


int main()
{
    struct Graph *G = adjListOfGraph();
    display(G);

    DFSTraversal(G);
    printf("\n");

    BFSTraversal(G);
    printf("\n");

    shortestPath(G, 0);
}