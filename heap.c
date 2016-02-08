#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include "linkedList.h"
#include "node.h"
#include "listNode.h"
#include "queue.h"
#include "stack.h"

heap *newHeap(void)
{
    heap *h = (heap *) malloc(sizeof(heap));
    if (h==0) { fprintf(stderr,"out of memory"); exit(-1);}

    h->rootNode = NULL;
    h->queue = newLList();
    h->stack = newLList();
    h->size = 0;
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
        printf("next in queue: %p\n",temp);
        if (!temp->leftChild)
        {
//             printf("h1");
            temp->leftChild = n;
            n->parent = temp;
            enqueue(h->queue, n);
            pushStack(h->stack, n);
            
        }else if (!temp->rightChild)
        {
            printf("h2");
            temp->rightChild = n;
            n->parent = temp;
            enqueue(h->queue, n);
            pushStack(h->stack, n);
            dequeue(h->queue);
        }else
        {
            printf("h3");
            dequeue(h->queue);
            temp = pequeue(h->queue);
            temp->leftChild = n;
            enqueue(h->queue, n);
            pushStack(h->stack, n);
        }
    }
    h->size++;
    printf(" current: %p\n",n);
    printf(" parent: %p\n",n->parent);
    return;
}




int heapSize(heap *h)
{
    return h->size;
}

void printHeap(heap *h)
{
    node *n = popStack(h->stack);
    while (n)
    {
        printf("%d\n",n->value);
        n = popStack(h->stack);
    }

}

void heapify(h)
{
    listNode *ln = getListTail(h->stack);
    while (ln)
    {
        
        siftDown(getListNodeValue(ln));
        ln = ln->previous;
    }
}

void siftDown(n)
{
        if (!n->left && !n->right)
        {
            return;
        }else if (n->left && !n->right)
        {
            if (compare(n,n->left)
            {
               swapValue(n,n->left);
               siftDown(n->left);
            }
        }else if (n->left && n->right)
        {
            if compare(getNodeValue(n->left),getNodeValue(n->right))
            {
                node *x = n->left;
            }else
            {
                node *x = n->right;
            }
            if compare(n, x)
            {
                swapValue(n,x);
                siftDown(x);
            }
        }
}

