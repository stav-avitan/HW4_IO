#ifndef edgesh
#define edgesh

typedef struct node_ node, *newNode;

// Edge struct
typedef struct edge_
{
    int weight;
    newNode endpoint;
    struct edge_ *next;
} edge, *pedge;


void addEdge(int , int , int , newNode *);
void insertLastE(newNode, int , newNode *);
void deleteFromListE(int, pedge *, newNode *);
void freeEdges(pedge *);
edge *newEdge(int , newNode);

#endif
