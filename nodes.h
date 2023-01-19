#ifndef nodes
#define nodes

typedef struct edge_ edge, *pedge;

// Node struct
typedef struct node_
{
    int id;
    pedge edges;
    struct node_ *next;
} node, *newNode;

node *newNode1(int);
void insertLastN(int, newNode *);
void deleteFromListN(int, node **);
newNode getNode (newNode *, int);
void deleteGraph(newNode *);

#endif