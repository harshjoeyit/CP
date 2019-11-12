#include<stdio.h>
#include<stdlib.h>

struct Graph
{
    int v, e;
    int **Adj;
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


struct Graph *adjMatrixOfGraph()
{
    int u, v, i, j;
    struct Graph *G = (struct Graph* )malloc(sizeof(struct Graph));
    if(!G)
    {
        printf("Memory Eroor\n");
        return NULL;
    }

    printf("Number of vertices, Number of Edges: ");
    scanf("%d%d",&i, &j);
    G->v = i;
    G->e = j;

    G->Adj = (int** )malloc(sizeof(int*) * G->v);
    for(i = 0; i < G->v; i++)
        G->Adj[i] = (int* )malloc(sizeof(int) * G->v);

    for(i = 0; i < G->v; i++)
        for(j = 0; j < G->v; j++)
            G->Adj[i][j] = 0;
    
    for(int i = 0; i < G->e; i++)
    {
        printf("Reading Edge:");
        scanf(" %d %d", &u, &v);
        G->Adj[u][v] = 1;
        G->Adj[v][u] = 1;
    }
    return G;
}


void display(struct Graph *G)
{
    if(!G)
        return ;
    int v = G->v;
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
            printf("%d ", G->Adj[i][j]);
        printf("\n");
    }
}

void DFS(struct Graph *G, int u, int visited[])
{
    visited[u] = 1;
    printf("%d ", u);

    for(int i = 0; i < G->v; i++)
    {
        if((G->Adj[u][i] == 1) && (visited[i] == 0))
            DFS(G, i, visited);
    }
}

void DFSTraversal(struct Graph *G)
{
    printf("DFS: ");
    int visited[G->v] = {0};
    // loop required if the graph is disconnect
    for(int i = 0; i < G->v; i++)
        if(visited[i] == 0)
            DFS(G, i, visited);
}


void BFS(struct Graph *G, int u, int visited[])
{
    struct LinkedQueue *Q = create_queue();
    en_queue(Q, u);

    while(!is_empty_queue(Q))
    {
        u = de_queue(Q);
        printf("%d ", u);
        visited[u] = 1;

        for(int i = 0; i < G->v; i++)
            if((G->Adj[u][i] == 1) && (visited[i] == 0))
                en_queue(Q, i);
    }
}


void BFSTraversal(struct Graph *G)
{
    printf("BFS: ");
    int visited[G->v] = {0};
    for(int i = 0; i < G->v; i++)
        if(visited[i] == 0)
            BFS(G, i, visited);
}


int main()
{
    struct Graph *G = adjMatrixOfGraph();
    display(G);

    DFSTraversal(G);
    printf("\n");

    BFSTraversal(G);
    printf("\n");
}

