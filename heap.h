#ifndef HEAP_H
#define HEAP_H

#include "node.h"
#include "linkedList.h"

typedef struct heap heap;
struct heap
{
    struct node *rootNode;
    struct list *l;
    int size;
};

extern heap *newHeap(void);
extern void insertItem(heap *h, node *n);
extern void heapifyUp(heap *h);
extern void heapifyDown(heap *h);
extern int heapIsNotEmpty(heap *h);
extern void printHeap(heap *h);

#endif
