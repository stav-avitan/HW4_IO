//
// Created by stavavitan on 1/19/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"
#include "edges.h"
#include "graph.h"

void addEdge(int , int , int , newNode *);
void insertLastE(newNode, int , newNode *);
void deleteFromListE(int, pedge *, newNode *);
void freeEdges(pedge *);
edge *newEdge(int , newNode);

edge *newEdge(int weight, newNode dest)
{
    edge *e = (edge *)malloc(sizeof(edge));
    if (e == NULL)
    {
        return NULL;
    }
    e->weight = weight;
    e->endpoint = dest;
    e->next = NULL;
    return e;
}

void insertLastE(newNode dest, int w, newNode *head)
{
    pedge e = (*head)->edges;
    pedge ed = newEdge(w, dest);
    if (!e)
    {
        (*head)->edges = ed;
    }
    else
    {
        while (e->next)
        {
            e = e->next;
        }
        e->next = ed;
    }
}

void addEdge(int src, int dest, int w, newNode *head)
{
    newNode curr = *head;
    newNode nsrc = NULL;
    newNode ndest = NULL;

    while (curr)
    {
        if (curr->id == src)
        {
            nsrc = curr;
        }
        if (curr->id == dest)
        {
            ndest = curr;
        }
        curr = curr->next;
    }

    if (!nsrc || !ndest)
    {
        return;
    }

    insertLastE(ndest, w, &nsrc);
}

void deleteFromListE(int id, pedge *h, newNode *n)
{
    if (!*h)
        return;
    pedge p = *h;
    pedge *prev = h;
    while (p)
    {
        if (p->endpoint->id == id)
        {
            *prev = p->next;
            free(p);
            p = *prev;
        }
        else
        {
            prev = &(p->next);
            p = p->next;
        }
    }
}

void freeEdges(pedge *edge)
{
    if (!edge)
    {
        return;
    }
    pedge e = *edge;
    pedge *prev = edge;
    while (e)
    {
        *prev = e->next;
        free(e);
        e = *prev;
    }
}