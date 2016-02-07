#include <stdio.h>
#include <stdlib.h>
#include "node.h"

node *newNode()
{
    node *n = (node *) malloc(sizeof(node));
    if (n==0) { fprintf(stderr,"out of memory"); exit(-1); }
    
    n->value = 0;
    n->heapParent = NULL;
    n->heapLeftChild = NULL;
    n->heapRightChild = NULL;
    n->listNext = NULL;
    n->listPrevious = NULL;

    return n;
}

void setNodeValue(node *n, int value)
{
    n->value = value;
    return;
}

int getNodeValue(node *n)
{
    return n->value;
}

void setNodeLeftChild(node *n, node *leftChild)
{
    n->heapLeftChild = leftChild;
    return;
}

node *getNodeLeftChild(node *n)
{
    return n->heapLeftChild;
}

void setNodeRightChild(node *n, node *rightChild)
{
    n->heapRightChild = rightChild;
    return;
}

node *getNodeRightChild(node *n)
{
    return n->heapRightChild;
}

void setNodeListNext(node *n, node *listNext)
{
    n->listNext = listNext;
    return;
}
node *getNodeListNext(node *n)
{
    return n->listNext;
}

void setNodeListPrevious(node *n, node *listPrevious)
{
    n->listPrevious = listPrevious;
    return;
}

node *getNodeListPrevious(node *n)
{
    return n->listPrevious;
}

void setNodeParent(node *n, node *parent)
{
    n->heapParent = parent;
    return;
}

node *getNodeParent(node *n)
{
    return n->heapParent;
}
