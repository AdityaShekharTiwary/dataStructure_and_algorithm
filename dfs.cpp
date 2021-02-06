#include <stdio.h>
#include <stdlib.h>
#define INFINITE 99999
//cost between 2 adjacent vertices is taken as 1
typedef struct
{
    int n;//number of vertices
    char *V;//A,B,C ... vertices
    int **wt;//2D array using pointers
}GRAPH;


typedef struct
{
    int top;
    int *vertex;// stack is taken here
}STACK;

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

void initialise_Stack(STACK *s, int sz)
{
    s->top=-1;
    s->vertex=(int*)malloc(sizeof(int)*sz);
}

void push(STACK *s,int v)
{
    s->vertex[++(s->top)]=v;
}

void pop(STACK *s)
{
    if(s->top==-1)
    {
        printf("\nEmpty Stack");
        //return -99999;
    }
    else
        s->vertex[(s->top)--];
}

int peep(STACK s)
{
    if(s.top==-1)
    {
        printf("\nEmpty Stack");
        return -99999;
    }
    else
        return s.vertex[(s.top)];
}

void DFS(GRAPH G, int v)//v is the first node to be visited
{
    STACK s;
    int *visited;
    int i,p,flag=0;
    printf("\n");
    initialise_Stack(&s,G.n);
    visited=(int*)malloc(sizeof(int)*G.n);//creating an array to keep track of all visited vertices
    for(i=0; i<G.n;i++)
        visited[i]=0;
    visited[v]=1;//first node is visited
    push(&s,v);
    printf("\nVisited %c ",G.V[peep(s)]);
    while(s.top!=-1)//run loop until stack is empty
    {
        p=peep(s);//see the first vertex
        flag=0;
        for(i=0;i<G.n;i++)
        {
            if(G.wt[p][i]!=0&&G.wt[p][i]!=INFINITE&&visited[i]==0)//check for any adjacent unvisited vertex
            {
                push(&s,i);// insert any one vertex into stack and print that vertex
                visited[i]=1;
                printf("\nVisited %c ",G.V[peep(s)]);
                flag=1;
                break;
            }
        }
        if(flag==0)//if the current vertex has no unvisited neighbours left then pop it out
            pop(&s);
    }
    free(visited);
    printf("\n");
}

void free_Graph(GRAPH *G)//freeing up space taken by graph
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
    printf("\nEnter starting vertex: (A=1,B=2...) ");
    scanf("%d",&x);
    DFS(G,x-1);
    free_Graph(&G);
}
