#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

typedef struct list list;
struct list
{
    struct node *head;
    struct node *tail;
    int size;
};

extern void addToHead(list *l, node *n);
extern node *seeHead(list *l);
extern node *removeHead(list *l);
extern void addToTail(list *l, node *n);
extern node *seeTail(list *l);
extern node *removeTail(list *l);
extern list *newLList(void);
extern int listIsNotEmpty(list *l);

#endif
