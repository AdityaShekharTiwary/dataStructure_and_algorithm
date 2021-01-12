#include <stdio.h>
#include <stdlib.h>
#define INFINITE 99999
//edge cost has been taken as 1 b/w to neighbouring vertices
typedef struct
{
    int n;//number of vertices
    char *V;//A,B,C ... vertices
    int **wt;//2D array using pointers
}GRAPH;

typedef struct
{
    int front,rear;
    int *vertex;//queue will be stored here
}QUEUE;

void ip_Graph(GRAPH *G)
{
    int i,j,ans;
    printf("Enter the number of vertices: ");
    scanf("%d",&G->n);
    getchar();
    G->V=(char*)malloc(sizeof(char)*G->n);//initialising array of vertices (A,B,C,D...)
    for(i=0;i<G->n;i++)
        G->V[i]='A'+i;
    G->wt=(int**)malloc(sizeof(int*)*G->n);//initialising 2D array of cost b/w i-th and j-th vertices
    for(i=0;i<G->n;i++)
        G->wt[i]=(int*)malloc(sizeof(int)*G->n);//individual row is initialised as a new array

    for(i=0;i<G->n;i++)
        for(j=0;j<G->n;j++)
        {
            printf("\nIs there any edge b/w %d and %d? (YES=1||NO=0): ",i+1,j+1);
            scanf("%d",&ans);
            if(ans==1)
            {
                printf("\nEnter edge cost b/w %d and %d: ",i+1,j+1);
                scanf("%d",&G->wt[i][j]);
            }
            else
                G->wt[i][j]=INFINITE;
        }
}

void initialise_Queue(QUEUE *q, int sz)
{
    q->front=q->rear=-1;
    q->vertex=(int*)malloc(sizeof(int)*sz);//creating queue
}

void ins(QUEUE *q,int v)
{
    q->vertex[++(q->rear)]=v;
}

int del(QUEUE *q)
{
    if(q->front==q->rear)
    {
        printf("\nEmpty Queue");
        q->front=q->rear=-1;
        return -99999;
    }
    else
        return q->vertex[++(q->front)];
}

void BFS(GRAPH G, int v)//v is the first node to be visited
{
    QUEUE q;
    int *visited;
    int i,p;
    printf("\n");
    initialise_Queue(&q,G.n);
    visited=(int*)malloc(sizeof(int)*G.n);//creating an array to keep track of visited nodes
    for(i=0; i<G.n;i++)
        visited[i]=0;
    visited[v]=1;//starting node has been visited
    ins(&q,v);//push starting node into queue
    while(q.front!=q.rear)//loop will run until queue is empty
    {
        p=del(&q);//remove vertex from queue after it has been explored
        printf("\nVisited %c ",G.V[p]);
        for(i=0;i<G.n;i++)//run a loop to find the neighbouring vertices of current node which are unvisited
            if(G.wt[p][i]!=0&&G.wt[p][i]!=INFINITE&&visited[i]==0)
            {
                ins(&q,i);//put all encountered neighbouring vertices into queue
                visited[i]=1;
            }
    }
    free(visited);
    printf("\n");
}

void free_Graph(GRAPH *G)//free up space
{
    int i,j;
    free(G->V);
    for(i=0;i<G->n;i++)
        free(G->wt[i]);
    free(G->wt);
}

int main()
{
    GRAPH G;
    ip_Graph(&G);
    int x;
    printf("Enter starting vertex: (A=1,B=2...) ");//enter vertex from where search is to be started
    scanf("%d",&x);
    BFS(G,x-1);
    free_Graph(&G);
}
