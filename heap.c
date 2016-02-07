#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include "linkedList.h"
#include "node.h"

heap *newHeap(void)
{
    heap *h = (heap *) malloc(sizeof(heap));
    if (h==0) { fprintf(stderr,"out of memory"); exit(-1);}

    h->rootNode = NULL;
    h->l = newLList();
    h->size = 0;
}

void insertItem(heap *h, node *n)
{
    if (!heapIsNotEmpty(h))
    {
        h->rootNode = n;
        addToTail(h->l, n);
        h->size++;
    }else
    {
        node *lastNode = seeTail(h->l);
        if (!getNodeParent(lastNode))
        {
            setNodeLeftChild(lastNode, n);
            setNodeParent(n, lastNode);
        }
        else
        {
            lastNode = getNodeParent(lastNode);
            if (getNodeLeftChild(lastNode) == NULL)
            {
                setNodeLeftChild(lastNode, n);
                setNodeParent(n, lastNode);
            }
            else if (getNodeRightChild(lastNode) == NULL)
            {
                setNodeRightChild(lastNode, n);
                setNodeParent(n, lastNode);
            }
            else
            {
                setNodeLeftChild(seeTail(lastNode),n);
                setNodeParent(n, seeTail(lastNode));
            }
        }
        addToTail(h->l,n);
        h->size++;
    }
}

int heapIsNotEmpty(heap *h)
{
    return h->size;
}

void printHeap(heap *h)
{
    int run = 1;
    node *n = h->l->head;
    while (run)
    {
        if (n->listNext == NULL)
        {
            printf("%d\n",n->value);
            run = 0;
        }else
        {
            printf("%d\n",n->value);
            n = n->listNext;
        };
    };
}
