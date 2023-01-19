//
// Created by stavavitan on 1/19/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "edges.h"
#include "nodes.h"
#include "graph.h"

node *newNode1(int);
void insertLastN(int, newNode *);
void deleteFromListN(int, node **);
newNode getNode (newNode *, int);
void deleteGraph(newNode *);

node *newNode1(int id)
{
    newNode p = (newNode)malloc(sizeof(node));
    if (p == NULL)
    {
        return NULL;
    }
    p->id = id;
    p->next = NULL;
    p->edges = NULL;
    return p;
}

newNode getNode(newNode *head, int id)
{
    newNode h = *head;
    while (h)
    {
        if (h->id == id)
        {
            return h;
        }
        h = h->next;
    }
    return NULL;
}

void insertLastN(int id, newNode *head)
{
    newNode *p = head;
    while (*p)
    {
        p = &((*p)->next);
    }
    *p = newNode1(id);
}

void deleteFromListN(int id, newNode *head)
{
    newNode h = *head;
    newNode p = NULL;
    if(h->id != id){
        while (h->next->id != id)
        {
            h = h->next;
        }
        p = h->next;
        h->next = h->next->next;
        freeEdges(&(p->edges));
        free(p);
    }
    else{
        p = *head;
        *head = p->next;
        freeEdges(&(p->edges));
        free(p);
    }
}