#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

list *newLList(void)
{
    struct list *l = (list *) malloc(sizeof(list));
    if (l==0) {fprintf(stderr,"out of memory"); exit(-1); }

    l->head = NULL;
    l->tail = NULL;
    l->size = 0;

    return l;
}

void addToHead(list *l, node *n)
{
    l->head->listPrevious = n;
    n->listNext = l->head;
    n->listPrevious = NULL;
    l->head = n;
}

node *seeHead(list *l)
{
    return l->head;
}

node *removeHead(list *l)
{
    node *temp = l->head;
    l->head = temp->listNext;
    l->head->listPrevious = NULL;
    temp->listPrevious = NULL;
    temp->listNext = NULL;
    
    return temp;
}

void addToTail(list *l, node *n)
{
    if (!listIsNotEmpty(l))
    {
        l->head = n;
        l->tail = n;
        l->size++;
    }else
    {    
        l->tail->listNext = n;
        n->listPrevious = l->tail;
        n->listNext = NULL;
        l->tail = n;
    };
    return;
}

node *seeTail(list *l)
{
    return l->tail;
}

node *removeTail(list *l)
{
    node *temp = l->tail;
    l->tail = temp->listPrevious;
    l->tail->listNext = NULL;
    temp->listPrevious = NULL;
    temp->listNext = NULL;
    
    return temp;
}

int listIsNotEmpty(list *l)
{
    return l->size;
}
