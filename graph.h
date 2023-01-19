#ifndef GRAPH_
#define GRAPH_

#include "nodes.h"
#include "edges.h"

void delete_graph(newNode *h);
void createNewGraph(newNode *h);
void addVertice(newNode *h);
void delete_node(newNode *h);
void shortsPath(newNode h);
int shortsPathWithMat(newNode h, int, int);
int min(int, int);
void TisTheShortestPath(newNode h);
void allChoices(newNode, int *, int, int , int *, int *);
int calc(newNode, int[], int);
void swap(int *, int *);
int numOfWays(int);
int findMinimum(int[], int);

void option (char, newNode *head);


#endif
