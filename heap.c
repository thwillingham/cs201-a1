#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include "linkedList.h"
#include "node.h"
#include "listNode.h"
#include "queue.h"
#include "stack.h"
#include "helpers.h"

heap *newHeap(void)
{
    heap *h = (heap *) malloc(sizeof(heap));
    if (h==0) { fprintf(stderr,"out of memory"); exit(-1);}

    h->rootNode = NULL;
    h->queue = newLList();
    h->stack = newLList();
    h->size = 0;
    h->type = 0;
    return h;
}

void insertItem(heap *h, int i)
{
    node *n = newNode();
    n->value = i;

    if (heapSize(h)==0)
    {
        h->rootNode = n;
        enqueue(h->queue, n);
        pushStack(h->stack, n);
    }
    else
    {
        node *temp = pequeue(h->queue);
        if (!temp->leftChild)
        {
            temp->leftChild = n;
            n->parent = temp;
            enqueue(h->queue, n);
            pushStack(h->stack, n);
            
        }else if (!temp->rightChild)
        {
            temp->rightChild = n;
            n->parent = temp;
            enqueue(h->queue, n);
            pushStack(h->stack, n);
            dequeue(h->queue);
        }else
        {
            dequeue(h->queue);
            temp = pequeue(h->queue);
            temp->leftChild = n;
            enqueue(h->queue, n);
            pushStack(h->stack, n);
        }
    }
    h->size++;
    return;
}




int heapSize(heap *h)
{
    return h->size;
}

void printHeap(heap *h)
{
    node *n = popHeap(h);
    while (n)
    {
        printf("%d ",getNodeValue(n));
        n = popHeap(h);
    }

}

void heapify(heap *h)
{
    listNode *ln = seeTail(h->stack);
    while (ln)
    {
        
        siftDown(h, getListNodeValue(ln));
        ln = ln->previous;
    }
}

void siftDown(heap *h, node *n)
{
    node *current = n;
    node *leftChild = NULL;
    node *rightChild = NULL;
    node *xChild = NULL;
    while(getNodeLeftChild(current))
    {
        leftChild = getNodeLeftChild(current);
        rightChild = getNodeRightChild(current);
        xChild = leftChild;

        if (rightChild && compare(h->type, leftChild, rightChild))
        {
            xChild = rightChild;
        }

        if (compare(h->type, current,xChild))
        {
            swapNodeValue(current,xChild);
        }else{
            break;
        }

        current = xChild;
    }
}

node *popHeap(heap *h)
{
    node *xNode = popStack(h->stack);
    if (xNode == h->rootNode)
    {
        return xNode;
    }else if (!xNode)
    {
        return NULL;
    }
    if (xNode->parent->leftChild == xNode)
    {
        xNode->parent->leftChild = NULL;
    }else if (xNode->parent->rightChild == xNode)
    {
        xNode->parent->leftChild = NULL;
    }
    swapNodeValue(h->rootNode, xNode);
    siftDown(h, h->rootNode);
    return xNode;

}
