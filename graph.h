#ifndef GRAPH_
#define GRAPH_

#include "nodes.h"
#include "edges.h"


void build_graph(newNode *head);
void insert_node(newNode *head);
void delete_node(newNode *head);
void delete_graph(newNode *head);
void shortsPath(newNode head);
int shortsPathFun(newNode head, int, int);
int min(int, int);
void TheShortestPath(newNode head);
void permutation(newNode, int *, int, int, int*, int*);
int calcArray(newNode, int[], int);
void swap(int *, int *);
int factorial(int);
int find_minimum(int[], int);

void choice(char, newNode *head);


#endif
