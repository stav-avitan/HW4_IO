//
// Created by stavavitan on 1/19/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "graph.h"
#include "nodes.h"
#include "edges.h"

#define MAX 1000000

void createNewGraph(newNode *head);
void insert_node(newNode *head);
void delete_node(newNode *head);
void delete_graph(newNode *head);
void shortsPath(newNode head);
int shortsPathFun(newNode head, int, int);
int min(int, int);
void TheShortestPath(newNode head);
void permutation(newNode, int *, int, int, int *, int *);
int calcArray(newNode, int[], int);
void swap(int *, int *);
int factorial(int);
int find_minimum(int[], int);

void choice(char answer, newNode *graph)
{
    switch (answer)
    {
        case 'A':
            build_graph(graph);
            break;

        case 'B':
            insert_node(graph);
            break;

        case 'D':
            delete_node(graph);
            break;

        case 'S':
            shortsPath(*graph);
            break;

        case 'T':
            TheShortestPath(*graph);
            break;

        default:
            if (answer == EOF)
            {
                return;
            }
    }
}

void createNewGraph(newNode *head)
{
    int numOfVertices = 0;
    scanf("%d", &numOfVertices);
    for (int i = 0; i < numOfVertices; i++)
    {
        insertLastN(i, head);
    }
    char p = 0;
    while (scanf(" %c", &p) != 0)
    {
        if (p == 'n')
        {
            int src = -1;
            scanf("%d", &src);
            int dest, weight;
            while (scanf("%d", &dest) != 0 && scanf("%d", &weight) != 0)
            {
                if (isalpha(dest))
                {
                    break;
                }
                addEdge(src, dest, weight, head);
            }
        }
        else
        {
            break;
        }
    }
    choice(p, head);
}

void insert_node(newNode *head)
{
    int index;
    scanf("%d", &index);
    int dest, weight;
    newNode newNode1 = getNode(head, index);
    if (newNode1 == NULL)
    {
        insertLastN(index, head);
        while (scanf("%d", &dest) != 0 && scanf("%d", &weight) != 0)
        {
            if (isalpha(dest))
            {
                break;
            }
            addEdge(index, dest, weight, head);
        }
    }
    else
    {
        pedge *pe = &(newNode1->edges);
        freeEdges(pe);
        newNode1->edges = NULL;
        while (scanf("%d", &dest) != 0 && scanf("%d", &weight) != 0)
        {
            if (isalpha(dest))
            {
                break;
            }
            addEdge(index, dest, weight, head);
        }
    }
    choice(getchar(), head);
}

void delete_graph(newNode *h)
{
    if (h!= NULL)
    {
        return;
    }
    newNode t = *h;
    while (t)
    {
        pedge nodeEdges = t->edges;
        while (nodeEdges)
        {
            pedge newEdge = nodeEdges;
            nodeEdges = nodeEdges->next;
            free(newEdge);
        }
        newNode node = t;
        t = t->next;
        free(node);
    }
    free(t);
}

void delete_node(newNode *head)
{
    int ind;
    scanf("%d", &ind);

    newNode temp = *head;
    while (temp)
    {
        pedge *tempEdge = &(temp->edges);
        deleteFromListE(ind, tempEdge, head);
        temp = temp->next;
    }
    deleteFromListN(ind, head);
    choice(getchar(), head);
}

void shortsPath(newNode head)
{
    int src = 0, dst = 0;
    scanf("%d", &src);
    scanf("%d", &dst);
    printf("Dijsktra shortest path: %d \n", shortsPathFun(head, src, dst));
}

int shortsPathFun(newNode head, int source, int target)
{
    if (!head)
    {
        return -1;
    }
    newNode curr = head;
    int N = 0;
    while (curr)
    {
        if (N < curr->id)
        {
            N = curr->id;
        }
        curr = curr->next;
    }
    N += 1;
    int mat[N][N];

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            mat[k][i] = MAX;
        }
    }

    curr = head;
    while (curr)
    {
        pedge ed = curr->edges;
        while (ed)
        {
            mat[curr->id][ed->endpoint->id] = ed->weight;
            ed = ed->next;
        }
        curr = curr->next;
    }

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j)
                {
                    mat[i][i] = 0;
                }
                else if (i == k || j == k)
                {
                    mat[i][j] = mat[i][j];
                }
                else
                {
                    int val = mat[i][k] + mat[k][j];
                    if (mat[i][k] == 0 || mat[k][j] == 0)
                    {
                        val = 0;
                    }
                    mat[i][j] = min(mat[i][j], val);
                }
            }
        }
    }
    if (mat[source][target] == MAX)
    {
        return -1;
    }
    return mat[source][target];
}

int min(int a, int b)
{
    return (a == 0) ? b : (b == 0) ? a
                                   : (a < b)    ? a
                                                : b;
}

void TheShortestPath(newNode head)
{
    int count;
    scanf("%d", &count);
    if (count == 0)
    {
        return;
    }
    int cities[count];
    for (size_t i = 0; i < count; i++)
    {
        scanf("%d", &cities[i]);
    }
    int fac = factorial(count);
    int perm[fac];
    int temp = 0;
    permutation(head, cities, 0, count - 1, perm, &temp);
    int ind = find_minimum(perm, fac);
    if (perm[ind] == MAX)
    {
        printf("TSP shortest path: %d \n", -1);
    }
    else
    {
        printf("TSP shortest path: %d \n", perm[ind]);
    }
}

int calcArray(newNode head, int cities[], int size)
{
    int distance = 0;
    for (size_t i = 0; i < size - 1; i++)
    {
        int path = shortsPathFun(head, cities[i], cities[i + 1]);
        if (path == -1)
        {
            return MAX;
        }
        distance += path;
    }
    return distance;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(newNode head, int *cities, int start, int end, int *perm, int *ind)
{
    if (start == end)
    {
        perm[(*ind)++] = calcArray(head, cities, end + 1);
        return;
    }
    int i;
    for (i = start; i <= end; i++)
    {
        swap((cities + i), (cities + start));
        permutation(head, cities, start + 1, end, perm, ind);
        swap((cities + i), (cities + start));
    }
}

int find_minimum(int arr[], int n)
{
    int index = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[index])
        {
            index = i;
        }
    return index;
}

int factorial(int num)
{
    if (num == 0)
        return 1;
    if (num < 0)
        return 0;
    return factorial(num - 1) * num;
}